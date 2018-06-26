#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 10009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
bool comp(pair<int, int> x, pair<int, int> y);
int fn();

pair<int, int> array[MAX], help[MAX];
int n;
///first val ///sec expiration date

int main()
{
    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d %d", &array[i].first, &array[i].second);

        merge_sort(0, n - 1, array, help);

        printf("%d\n", fn());
    }

    return 0;
}

int fn()
{
    ///first val ///sec expiration date
    int ret = 0, i = 0;
    int p_prev = array[0].second;
    int tmp;
    priority_queue<int>x;

    while(i < n)
    {
        if(p_prev == array[i].second)
            x.push(array[i].first);
        else
        {
            if(x.empty() == 0)
                tmp = x.top(), x.pop(), ret += tmp;

            int k = 0;
            int j = p_prev - array[i].second - 1;
            while(k < j)
            {
                if(x.empty() == 0)
                    tmp = x.top(), x.pop();
                else
                    break;
                ret += tmp;
                k++;
            }

            x.push(array[i].first);
            p_prev = array[i].second;
        }

        i++;
    }

    if(x.empty() == 0)
        tmp = x.top(), x.pop(), ret += tmp;
    int k = 0;
    int j = p_prev - array[i].second - 1;
    while(k < j)
    {
        if(x.empty() == 0)
            tmp = x.top(), x.pop();
        else
            break;
        ret += tmp;
        k++;
    }

    return ret;
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

        else if(swap[p1].second > array[p2].second)
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

bool comp(pair<int, int> x, pair<int, int> y)
{
    ///first val ///sec expiration date
    if(x.second == y.second)
        return x.first > y.second;

    return x.first > y.first;
}
