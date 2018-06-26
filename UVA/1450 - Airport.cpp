#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 5005

bool valid(int val);
int bin_search();

int a[MAX], b[MAX], n, cases, total;
const int inf = 9999999;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        total = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &a[i], &b[i]), total += a[i] + b[i];
        if(total == 0)
            printf("%d\n", 0);
        else
            printf("%d\n", bin_search() - 1);
    }

    return 0;
}

int bin_search()
{
    int ret = inf;
    int big = total, small = 0 , mid;
    while(big >= small)
    {
        mid = (big + small) / 2;

        if(valid(mid))
            ret = min(ret, mid), big = mid - 1;
        else
            small = mid + 1;
    }

    return ret;
}

bool valid(int val)
{
    int i = 0, accum_a = 0, accum_b = 0, del_u = 0;

    while(i < n)
    {
        if(accum_a + a[i] <= val)
            accum_a += a[i];
        else
        {
            int diff = accum_a + a[i] - val;

            if(diff > del_u || a[i] > val)
                return 0;

            del_u -= diff;
            accum_a = val;
        }

        if(accum_b + b[i] <= val)
            accum_b += b[i];
        else
        {
            int diff = accum_b + b[i] - val;
            if(diff > del_u || b[i] > val)
                return 0;

            del_u -= diff;
            accum_b = val;
        }

        if(accum_a && accum_b && accum_a + accum_b > del_u)
            del_u++;
        else if(accum_a == 0 && accum_b)
            accum_b--;
        else if(accum_b == 0 && accum_a)
            accum_a--;

        i++;
    }

    return true;
}

