#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 20009

struct node
{
    int r, d, w;
};

int bin_search();
int check(int x);
bool comp(node x, node y);

node array[MAX];
int n, m, tc;
int v[MAX];
const int inf = 99999999;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        m = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d %d", &array[i].r, &array[i].d, &array[i].w), m += array[i].w;

        sort(array, array + n, comp);
        printf("%d\n", bin_search());

    }
    return 0;
}

bool comp(node x, node y)
{
    return x.d < y.d;
}

int bin_search()
{
    int small = 1, big = m, mid, ret = 100000;
    while(big >= small)
    {
        mid = (big + small) / 2;

        int tmp = check(mid);
        if(tmp)
            ret = min(ret, mid);

        if(tmp)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return ret;
}

int check(int x)
{
    memset(v, 0, sizeof(v));
    int i = 0, j, tmp, w, k;

    while(i < n)
    {
        j = array[i].r, k = array[i].d, tmp = 0;
        w = (array[i].w);// * x);

        while(tmp < w && j < k)
        {
            if(v[j] < x)
            {
                int tmp2 = min(x - v[j], w - tmp);
                v[j] += tmp2, tmp += tmp2;
            }
            j++;
        }

        if(tmp < w)
            return 0;

        i++;
    }

    return 1;
}
