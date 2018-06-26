#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 100009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
void fn();

int array[MAX], help[MAX], diff[MAX], n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    fn();
    return 0;
}

void fn()
{
    merge_sort(0, n - 1, array, help);

    if(n == 1)
    {
        printf("-1");
        return;
    }

    if(n == 2)
    {
        if(array[0] != array[1])
        {
            if((array[1] - array[0]) % 2 == 0)
                printf("3\n%d %d %d\n", array[0] - (array[1] - array[0]), (array[1] - array[0]) / 2 + array[0], array[1] + array[1] - array[0]);
            else
                printf("2\n%d %d\n", array[0] - (array[1] - array[0]), array[1] + array[1] - array[0]);
        }
        else
            printf("1\n%d\n", array[0]);
        return;
    }

    ///forming good
    for(int i = 1; i < n; i++)
        diff[i - 1] = array[i] - array[i - 1];

    merge_sort(0, n - 2, diff, help);

    int accum = 0, prev = diff[0], m = 0, diff2;
    for(int i = 0; i < n - 1; i++)
    {
        if(diff[i] == prev)
            accum++;
        else
        {
            if(accum > m)
                diff2 = prev, m = accum;
            prev = diff[i], accum = 1;
        }
    }
    if(accum > m)
        diff2 = prev, m = accum;

    int v = 0, j;
    for(int i = 1; i < n; i++)
        if(diff2 != array[i] - array[i - 1])
            v++, j = i;

    switch(v)
    {
    case 0:
        if(diff2 == 0)
            printf("1\n%d\n", array[0]);
        else
            printf("2\n%d %d\n", array[0] - diff2, array[n - 1] + diff2);
        break;

    case 1:
        if((array[j] - array[j - 1]) / 2 == diff2 && (array[j] - array[j - 1]) % 2 == 0)
            printf("1\n%d\n", array[j - 1] + diff2);
        else
            printf("0\n");
        break;

    default :
        printf("0\n");
        break;
    }
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
