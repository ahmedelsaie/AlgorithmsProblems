#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 100009
#define MAX_LETTERS 26
#define ll long long
struct block
{
    int i, prev;
    ll a;
};

template <typename type>
void merge_sort(int start, int last, type array, type swap);
ll fn();
ll get(int k, int l);
int bin_search(int indx, ll val, int i);
bool comp(block x, block y);

int letters[30], n;
char array[MAX];
block accum[MAX], help[MAX];

int main()
{
    for(int i = 0; i < MAX_LETTERS; i++)
        scanf("%d", &letters[i]);

    scanf("%s", array);
    n = strlen(array);

    printf("%lld\n", fn());

    return 0;
}

ll fn()
{
    ll with, ret = 0, tmp;
    int k = 0;

    for(int i = 0; i < MAX_LETTERS; i++)
    {
        k = 0, with = 0;
        for(int j = 0; j < n; j++)
        {
            if(array[j] - 'a' != i)
                with += (ll)letters[array[j] - 'a'];
            else
                accum[k].a = with, accum[k].i = j, k++, with += (ll)letters[array[j] - 'a'];
        }
        ll tmp5 = get(k, i);

        ret += tmp5;
    }

    return ret;
}

ll get(int k, int l)
{
    merge_sort(0, k - 1, accum, help);

    ll prev = accum[0].a, taken = 0, ret = 0, tmp;
    int i = 0, j = 0;

    while(i < k)
    {
        if(prev == accum[i].a)
            taken++, accum[i].prev = taken;
        else
        {
            prev = accum[i].a;
            taken = 1;
            accum[i].prev = taken;
        }
        i++;
    }

    for(int i = 0; i < k; i++)
    {
        tmp = (ll) bin_search(k, accum[i].a - letters[l], accum[i].i);

        if(tmp != -1)
            ret += tmp;
    }

    return ret;
}

int bin_search(int indx, ll val, int i)
{
    int ret = -1;

    int big = indx - 1, small = 0, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(ret == -1 && accum[mid].a == val && accum[mid].i < i)
            ret = mid;

        if(ret != -1)
        {
            if(accum[mid].a == val && accum[mid].i > accum[ret].i && accum[mid].i < i)
                ret = mid;
        }

        if(accum[mid].a > val)
            big = mid - 1;
        else if(accum[mid].a < val)
            small = mid + 1;
        else if(accum[mid].a == val)
        {
            if(accum[mid].i >= i)
                big = mid - 1;
            else
                small = mid + 1;
        }
    }

    if(ret != -1)
        return accum[ret].prev;

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

    ///MERGING  ///MERarray[p2].secondGING  ///MERGING  ///MERGING
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

bool comp(block x, block y)
{
    if(x.a == y.a)
        return x.i < y.i;

    return x.a < y.a;
}
