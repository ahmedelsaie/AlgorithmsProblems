#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 65539

template <typename type>
void merge_sort(int start, int last, type array, type swap);

struct Song
{
    int id, l;
    double freq, quan;
};
Song array[MAX], help[MAX];
int n, x, y;

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d%lf", &array[i].id, &array[i].l, &array[i].freq);
        scanf("%d", &y);

        for(int i = 0; i < n; i++)
            array[i].quan = (double)array[i].l / array[i].freq;

        merge_sort(0, n - 1, array, help);
        printf("%d\n", array[y - 1].id);

    }
    return 0;
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

        else if(swap[p1].quan < array[p2].quan)
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
