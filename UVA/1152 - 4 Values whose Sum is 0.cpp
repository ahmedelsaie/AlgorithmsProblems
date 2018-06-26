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
#define MAX 4009

int bin_search(ll x);
int fn();

ll array[4][MAX], a[MAX* MAX], b[MAX* MAX];
int k, n, cases;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 4; j++)
                scanf("%lld", &array[j][i]);

        printf("%d\n", fn());

        if(cases)
            printf("\n");
    }

    return 0;
}

int fn()
{
    int ret = 0;
    k = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            a[k] = array[0][i] + array[1][j];
            b[k++] = array[2][i] + array[3][j];
        }

    // sort(a, a + k);
    sort(b, b + k);

    for(int i = 0; i < k; i++)
    {

        ll tmp = -1 * a[i];
        int tmp2 = bin_search(tmp);
        for(int j = tmp2; j < k; j++)
            if(b[j] == -a[i])
                ret++;
            else
                break;
    }

    return ret;
}

int bin_search(ll x)
{
    int small = 0, big = k - 1, mid, ret = k + 5;

    while(big >= small)
    {
        mid = (big + small) / 2;
        if(b[mid] == x && mid <= ret)
            ret = mid;

        if(b[mid] >= x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return ret;
}
