#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 500005

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int fn(int color);

int red[MAX], blue[MAX], help[MAX], n_red, n_blue, n, cases, x;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        n_red = n_blue = 0;

        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(x > 0)
                red[n_red++] = x;
            else
                blue[n_blue++] = -1 * x;
        }
        merge_sort(0, n_blue - 1, blue, help);
        merge_sort(0, n_red - 1, red, help);

        printf("%d\n", max(fn(0), fn(1)));
    }
    return 0;
}

int fn(int color)
{
    int i = 0, j = 0, prev = 9999999, c1 = 0;

    while(i < n_red || j < n_blue)
    {
        ///nw=red;
        if(color)
        {
            if(i >= n_red)
                break;

            if(red[i] < prev)
                prev = red[i], c1++, color = !color;
            i++;
        }
        else
        {
            if(j >= n_blue)
                break;

            if(blue[j] < prev)
                prev = blue[j], c1++, color = !color;
            j++;
        }
    }

    return c1;
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

        else if(swap[p1] > array[p2])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
