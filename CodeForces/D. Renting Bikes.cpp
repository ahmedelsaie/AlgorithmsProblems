#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

int bin_search();
int fn(int x, ll shared);

template <typename type>
void merge_sort(int start, int last, type array, type swap, bool flag);

ll bike[MAX], stud[MAX], help[MAX], shared;
int n_stud, n_bike, taken;

int main()
{
    scanf("%d %d %lld", &n_stud, &n_bike, &shared);

    for(int i = 0; i < n_stud; i++)
        scanf("%lld", &stud[i]);

    for(int i = 0; i < n_bike; i++)
        scanf("%lld", &bike[i]);

    merge_sort(0, n_stud - 1, stud, help, 0);
    merge_sort(0, n_bike - 1, bike, help, 0);

    taken = bin_search();
    ll ans = 0;

    for(int j = n_bike - taken; j < n_bike; j++)
        ans += bike[j];

    ans = max(ans - shared, (ll)0);
    printf("%d %lld\n", taken, ans);

    return 0;
}

int bin_search()
{
    int big = min(n_bike, n_stud), small = 1, mid, ret = 0;

    while(big >= small)
    {
        mid = (small + big) / 2;
        int tmp = fn(mid, shared);
        if(tmp)
            small = mid + 1, ret = max(ret, mid);
        else
            big = mid - 1;
    }

    return ret;
}

int fn(int x, ll shared)
{
    int j = n_bike - x, i = 0;

    while(i < n_stud && j < n_bike)
    {
        if(shared + stud[i] >= bike[j])
        {
            int diff = max(bike[j] - stud[i], (ll) 0);
            shared -= diff;
            i++, j++;
        }
        else
            return 0;
    }

    return 1;
}

///merge_sort
template <typename type>
void merge_sort(int start, int last, type array, type swap, bool flag)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, array, swap, flag);
    merge_sort(middle + 1, last, array, swap, flag);

    ///MERGING  ///MERGING  ///MERGING  ///MERGING
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

        else if((flag == 0 && swap[p1] > array[p2]) || (flag == 1 && swap[p1] < array[p2]))
            array[main_p] = swap[p1], p1++;
        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
