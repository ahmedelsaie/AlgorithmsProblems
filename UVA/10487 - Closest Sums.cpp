#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>

using namespace std;
template <typename type>
void merge_sort(int start, int last, type array, type swap);
int bin_search(int x);

int input[1000005], array[1000005];
int n, q, indx, cases = 1;

int main()
{
    while(true)
    {
        indx = 0;
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d", &input[i]);

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                array[indx] = input[i] + input[j], indx++;

        merge_sort(0, indx - 1, array, input);

        scanf("%d", &q);
        for(int i = 0; i < q; i++)
            scanf("%d", &input[i]);

        printf("Case %d:\n", cases++);
        for(int i = 0; i < q; i++)
            printf("Closest sum to %d is %d.\n", input[i], bin_search(input[i]));

    }
    return 0;
}

int bin_search(int x)
{
    int big = indx - 1, small = 0, mid, ret = 9999999999999999;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(abs(ret - x) > abs(array[mid] - x))
            ret = array[mid];

        if(array[mid] < x)
            small = mid + 1;
        else
            big = mid - 1;
    }

    return ret;
}

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

