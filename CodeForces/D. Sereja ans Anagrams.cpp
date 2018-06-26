#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 200009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
void fn(ll start, ll end);
int bin_search(int x);

int first[MAX], sec[MAX], cnt[MAX], nw[MAX], res[MAX];
ll n, m, wrong, start, start2, end, p, j = 0, ans = 0;

int main()
{
    scanf("%lld %lld %lld", &n, &m, &p);
    for(int i = 0; i < n; i++)
        scanf("%d", &first[i]);

    for(int i = 0; i < m; i++)
        scanf("%d", &sec[i]);

    merge_sort(0, m - 1, sec, nw);

    int i = 0, prev = sec[0], accum = 0;

    while(i < m)
    {
        if(prev == sec[i])
            accum++;
        else
        {
            sec[j] = prev, cnt[j++] = accum;
            prev = sec[i], accum = 1;
        }
        i++;
    }

    sec[j] = prev, cnt[j++] = accum;

    // for(int i = 0; i < j; i++)
    // printf("%d %d\n", sec[i], cnt[i]);

    start2 = 0;
    while(start2 < p)
    {
        start = start2, end = start + (m - 1) * p + 1;
      //  printf("%lld\n",end);
        if(end <= n)
            fn(start2, end);
        else
            break;

        // printf("%d %d\n", start, end);

        while(end <= n)
        {
            if(wrong == 0)
                res[ans++] = start;
            // printf("wrong%d\n", wrong);
            int tmp = bin_search(first[start]);
            if(tmp != -1)
            {
                if(nw[tmp] == cnt[tmp])
                    wrong++;
                nw[tmp]--;

                if(nw[tmp] == cnt[tmp])
                    wrong--;
            }

            end += p, start += p;
            if(end > n)
                break;

            tmp = bin_search(first[end - 1]);
            if(tmp != -1)
            {
                if(nw[tmp] == cnt[tmp])
                    wrong++;
                nw[tmp]++;

                if(nw[tmp] == cnt[tmp])
                    wrong--;
            }

            //       printf("inner loop %d %d\n", start, end);
        }

        start2++;
    }

    merge_sort(0, ans - 1, res, nw);

    printf("%lld\n", ans);
    for(ll i = 0; i < ans; i++)
        printf("%d ", res[i] + 1);

    return 0;
}

int bin_search(int x)
{
    int small = 0, big = j - 1, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;
        if(sec[mid] == x)
            return mid;

        if(sec[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return -1;
}

void fn(ll start, ll end)
{
    wrong = j;
    memset(nw, 0, sizeof(nw));

    for(ll i = start; i < end; i += p)
    {
        int tmp = bin_search(first[i]);
        if(tmp != -1)
        {
            if(nw[tmp] == cnt[tmp])
                wrong++;

            nw[tmp]++;

            if(nw[tmp] == cnt[tmp])
                wrong--;
        }
    }

    //printf("locale %d %d %d\n", start, end, wrong);
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

        else if(swap[p1] < array[p2])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
