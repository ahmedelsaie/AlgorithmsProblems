#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 200009;
template <typename type>
void merge_sort(int start, int last, type array, type swap);
bool fn();

pair<int, int>tmp1[200009], tmp2[200009];
int n, n1, n2, x, vec[200009], val[200009], p[200009];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        tmp1[i].first = x, tmp1[i].second = i;
    }

    merge_sort(0, n - 1, tmp1, tmp2);

    bool ans = fn();
    printf("%s\n", ans == 1 ? "Possible" : "Impossible");
    if(ans)
        for(int i = 0; i < n; i++)
        {
            if(i)
                printf(" ");
            printf("%d", vec[i] + 1);
        }

    return 0;
}

bool fn()
{
    n1 = n, n2 = 0;
    bool s = 0;
    int accum = 0, put = 0, i = 0;
    int test = 0;

    memset(val, 0, sizeof(val));
    memset(p, -1, sizeof(p));

    p[tmp1[0].first] = 0, val[tmp1[0].first]++;

    for(int i = 1; i < n; i++)
    {
        if(tmp1[i].first != tmp1[i - 1].first)
            p[tmp1[i].first] = i;
        val[tmp1[i].first]++;
    }

    while(put < n)
    {
        if(val[accum] > 0)
        {
            i = p[accum];
            vec[put] = tmp1[i].second, put++;
            val[accum]--;
            if(val[accum] > 0)
                p[accum]++;
            else
                p[accum] = -1;
            accum++;
        }
        else
        {
            if(accum >= 3)
                accum = accum - 3;
            else
                return 0;
        }
    }

    return true;
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

        else if(swap[p1].first < array[p2].first)
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
