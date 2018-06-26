#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 50

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int getbit(int mask, int bit);
ll fn();

ll array[MAX], help[MAX], x, maxi, mini;
int n;

int main()
{
    scanf("%d %lld %lld %lld", &n, &mini, &maxi, &x);
    for(int i = 0; i < n; i++)
        scanf("%lld", &array[i]);

    merge_sort(0, n - 1, array, help);

    printf("%lld\n", fn());
    return 0;
}

ll fn()
{
    ll ret = 0, small, big, ones, sum;
    for(int i = 0; i < (1 << n); i++)
    {
        small = -1, big = -1, sum = 0, ones = 0;
        for(int j = 0; j < n; j++)
        {
            if(getbit(i, j) == 1)
            {
                ones++;
                if(small == -1)
                    small = array[j];

                big = array[j];
                sum+=array[j];
            }
        }

        if(ones >= 2 && big - small >= x && sum >= mini && sum <= maxi)
            ret++;
    }

    return ret;
}

//merge_sort
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

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
