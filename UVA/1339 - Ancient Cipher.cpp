#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

template <typename type>
void merge_sort(int start, int last, type array, type swap);
bool fn();

char origin[105], encrypt[105];
int cnt1[30], cnt2[30], help[30], l;

int main()
{
    while(gets(origin))
    {
        gets(encrypt);
        printf("%s\n", fn() ? "YES" : "NO");
    }

    return 0;
}

bool fn()
{
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    l = strlen(origin);

    for(int i = 0; i < l; i++)
        cnt1[origin[i] - 'A']++, cnt2[encrypt[i] - 'A']++;

    merge_sort(0, 29, cnt1, help);
    merge_sort(0, 29, cnt2, help);

    for(int i = 0; i < 30; i++)
        if(cnt1[i] != cnt2[i])
            return 0;

    return 1;
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
