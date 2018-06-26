#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 100009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
bool comp(pair<int, int>x, pair<int, int>y);
int bin_search(int accum[], int i, int set1);
int play(int set1);
int fn();

int array[MAX], accuma[MAX], accumb[MAX], n;
pair<int, int>ans[MAX], help[MAX];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &array[i]);

    int ret = fn();
    merge_sort(0, ret - 1, ans, help);

    printf("%d\n", ret);
    for(int i = 0; i < ret; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}

int fn()
{
    int ret = 0, tmp;

    accuma[0] = accumb[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        accuma[i] = accuma[i - 1] + (array[i] == 1);
        accumb[i] = accumb[i - 1] + (array[i] == 2);
    }

    // for(int i = 1; i <= n; i++)
    //      printf("%d ", accuma[i]);

    //  printf("done with a\n");

    // for(int i = 1; i <= n; i++)
    //   printf("%d ", accumb[i]);



    for(int i = 1; i <= n; i++)
    {
        tmp = play(i);
        //    printf("\n\n\n");
        if(tmp != -1)
            ans[ret].second = i, ans[ret].first = tmp, ret++;
    }

    return ret;
}

int play(int set1)
{
    int i = 1, seta = 0, setb = 0;
    int tmpa, tmpb, last;

    //printf("============ %d\n", set1);

    while(i <= n)
    {
        tmpa = bin_search(accuma, i, set1);
        tmpb = bin_search(accumb, i, set1);

        //printf("tmp = %d %d\n", tmpa, tmpb);

        if(tmpa == -1 && tmpb == -1)
            return -1;

        if(tmpa == -1)
            setb++, i = tmpb + 1, last = 2;
        else if(tmpb == -1)
            seta++, i = tmpa + 1, last = 1;
        else if(tmpa < tmpb)
            seta++, i = tmpa + 1, last = 1;
        else if(tmpb < tmpa)
            setb++, i = tmpb + 1, last = 2;
        else
            return -1;

    }

    if(seta == setb)
        return -1;

    if(seta > setb && last == 2)
        return -1;

    if(setb > seta && last == 1)
        return -1;

    return max(seta, setb);
}

int bin_search(int accum[], int i, int set1)
{
    int small = i, big = n, mid, ret = 999999999;

    while(big >= small)
    {
        mid = (small + big) / 2;

        if(accum[mid] - accum[i - 1] == set1 && mid < ret)
            ret = mid;

        if(accum[mid] - accum[i - 1] >= set1)
            big = mid - 1;
        else
            small = mid + 1;
    }

    if(ret == 999999999)
        return -1;

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

        else if(comp(swap[p1], array[p2]))
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

bool comp(pair<int, int>x, pair<int, int>y)
{
    if(x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}
