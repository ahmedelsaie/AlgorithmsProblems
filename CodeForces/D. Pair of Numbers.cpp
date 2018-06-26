#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 300009

int gcd(int a, int b);
int bin_search(int x, int flag);

struct sparse_table
{
    int n;
    ll spt[MAX][20];

    void construct(int a[], int n)
    {
        for(int i = 0; i < n; i++)
            spt[i][0] = a[i];

        for(int j = 1; (1 << j) <= n; j++)
            for(int i = 0; i + (1 << j) - 1 < n; i++)
                spt[i][j] = gcd(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
    }

    int get_query(int i, int j)
    {
        int k = (int)floor(log((double)j - i + 1) / log(2.0));
        return gcd(spt[i][k], spt[j - (1 << k) + 1][k]);
    }
};

sparse_table tab;
int array[MAX], n;
pair<int, int> v[MAX];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    tab.construct(array, n);

    int ans = 0, ans_l = 0, ans_r = 0;
    int ret = 0;

    for(int i = 0; i < n; i++)
    {
        int r = max(i, bin_search(i, 0));
        int l = min(i, bin_search(i, 1));

        //printf("%d - %d %d\n", i, l, r);
        if(r - l > ans)
            ans = r - l, ans_l = l, ans_r = r, ret = 1, v[0].first = l, v[0].second = r;
        else if(r - l == ans)
            v[ret].first = l, v[ret].second = r, ret++;
    }

    sort(v, v + ret);
    int cnt=0,i=0;
    pair<int,int> prev=v[0];

    while(i<ret)
    {
        if(prev!=v[i])
            v[cnt++]=prev,prev=v[i];

        i++;
    }
                v[cnt++]=prev;


    ret=cnt;
    printf("%d %d\n", ret, ans);
    for(int i = 0; i < ret; i++)
        printf("%d ", v[i].first+1);

    return 0;
}

int bin_search(int x, int flag)
{
    if(flag == 0)
    {
        int small = x + 1, big = n - 1, mid, ret = -1;
        while(big >= small)
        {
            mid = (small + big) / 2;
            int tmp = tab.get_query(x + 1, mid);
            if(tmp % array[x] == 0)
                small = mid + 1, ret = max(ret, mid);
            else
                big = mid - 1;
        }
        return ret;
    }
    else
    {
        int small = 0, big = x - 1, mid, ret = 9999999;
        while(big >= small)
        {
            mid = (small + big) / 2;
            int tmp = tab.get_query(mid, x);
            if(tmp % array[x] == 0)
                big = mid - 1, ret = min(ret, mid);
            else
                small = mid + 1;
        }
        return ret;
    }
}

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
