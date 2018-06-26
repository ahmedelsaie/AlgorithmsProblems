#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int fn();
int go(int i);

int array[105], help[105], n, check[105];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    merge_sort(0, n - 1, array, help);
    printf("%d\n", fn());

    return 0;
}

int fn()
{
    memset(check, 0, sizeof(check));

    int ret = 0, accum = 0;

    while(accum < n)
    {
        for(int i = 0; i < n; i++)
            if(check[i] == 0)
            {
                check[i] = 1;
                accum += go(i);
                break;
            }
        ret++;
    }
    return ret;
}

int go(int i)
{
    int ret = 1, accum = 1;

    for(int j = i + 1; j < n; j++)
        if(check[j] == 0 && array[j] >= accum)
            check[j] = 1, ret++, accum++;

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

        else if(swap[p1] < array[p2])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
