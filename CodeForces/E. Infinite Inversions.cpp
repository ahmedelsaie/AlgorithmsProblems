#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 100009
#define ll long long

template <typename type>
void merge_sort(int start, int last, type array, type swap);
template <typename type>
void merge_sort2(int start, int last, type array, type swap);
int get_place(int x);
ll cnt;
pair<int, int>array[2 * MAX], input[MAX], help2[2 * MAX];
int places[2 * MAX], help[2 * MAX], n, j = 0, k = 0;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &input[i].first, &input[i].second);
        places[j] = input[i].first, places[j + 1] = input[i].second, j += 2;
    }

    merge_sort(0, j - 1, places, help);

    int prev = places[0], accum = 0;
    int i = 0;
    while(i < j)
    {
        if(prev == places[i])
            accum++;
        else
        {
            array[k].first = array[k].second = prev, k++;
            prev = places[i];
            accum = 1;
        }

        i++;
    }
    array[k].first = array[k].second = prev, k++;

    int p1, p2;
    for(int i = 0; i < n; i++)
    {
        p1 = get_place(input[i].first);
        p2 = get_place(input[i].second);
        int swap1 = array[p1].second;
        array[p1].second = array[p2].second;
        array[p2].second = swap1;
    }

    cnt = 0;

    for(int i = 0; i < k; i++)
    {
        int tmp = get_place(array[i].second);
        int a = abs(array[i].second - array[i].first - 1);
        a -= abs(tmp - i - 1);
        cnt += (ll) a;
    }

    merge_sort2(0, k - 1, array, help2);
    printf("%lld\n", cnt);
    return 0;
}

int get_place(int x)
{
    int small = 0, big = k, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;
        if(array[mid].first == x)
            return mid;

        if(array[mid].first < x)
            small = mid + 1;
        else
            big = mid - 1;
    }

    return mid;
}

///merge_sort
template <typename type>
void merge_sort(int start, int last, type array, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, array, swap);
    merge_sort(middle + 1, last, array, swap);

    ///MERGING  ///MERarray[p2].secondGING  ///MERGING  ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        swap[i] = array[i];

    while(main_p <= last)
    {
        if(p1 > middle)
            array[main_p] = array[p2], p2++;

        else if(p2 > last)
            array[main_p] = swap[p1], p1++;

        else if(swap[p1] < array[p2])
            array[main_p] = swap[p1], p1++, cnt++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

///merge_sort
template <typename type>
void merge_sort2(int start, int last, type array, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort2(start, middle, array, swap);
    merge_sort2(middle + 1, last, array, swap);

    ///MERGING  ///MERarray[p2].secondGING  ///MERGING  ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    int left = 0;

    for(int i = start; i <= middle; i++)
        swap[i] = array[i];
    int c = 0;

    while(main_p <= last)
    {
        if(p1 > middle)
            array[main_p] = array[p2], p2++, left++;

        else if(p2 > last)
            array[main_p] = swap[p1], p1++, cnt += (ll)left, c += left;

        else if(swap[p1].second < array[p2].second)
            array[main_p] = swap[p1], p1++, cnt += (ll)left, c += left;

        else
            array[main_p] = array[p2], p2++, left++;

        main_p++;
    }

    return;
}
