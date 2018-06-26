#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 16

void fn(int x);

int pos[MAX + 5], neg[MAX + 5], pos_sum[MAX + 5], neg_sum[MAX + 5];

int main()
{
    int prev = 1, cases, p = 1, x;

    pos_sum[0] = 0;
    for(int i = 1; i <= MAX; i++)
    {
        pos[i] = prev;
        pos_sum[i] += pos_sum[i - 1] + prev;
        prev *= 4;
    }

    prev = 2, neg_sum[0] = 0;
    for(int i = 1; i <= MAX; i++)
    {
        neg[i] = prev;
        neg_sum[i] += neg_sum[i - 1] + prev;
        prev *= 4;
    }

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &x);
        printf("Case #%d: ", p++);

        fn(x);
        printf("\n");
    }

    return 0;
}

void fn(int x)
{
    if(x == 0)
    {
        printf("0");
        return;
    }

    int ret = 0, j = 1, i = 1, with_me = 0, k;
    j = k = MAX;

    int ans[4 * MAX];
    memset(ans, 0, sizeof(ans));

    while(with_me != x)
    {
        while(with_me < x)
        {
            if(with_me + pos_sum[j - 1] < x)
                with_me += pos[j], ans[2 * j - 1] = 1;
            j--;
        }

        while(with_me > x)
        {
            if(with_me - neg_sum[k - 1] > x)
                with_me -= neg[k], ans[2 * k] = 1;
            k--;
        }
    }

    for(i = 2 * MAX; i >= 1; i--)
        if(ans[i])
            break;

    for(; i >= 1; i--)
        printf("%d", ans[i] == 1 ? 1 : 0);

    return;
}
