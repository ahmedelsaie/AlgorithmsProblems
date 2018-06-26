#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 3005

int fn(int first, int sec);

int prob[MAX], n, k, zeros[MAX], ones[MAX], dp[MAX][MAX], ans = 0;
const int inf = 9999999;

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &prob[i]);

    zeros[n + 1] = ones[n + 1] = 0;
    for(int i = n; i >= 1; i--)
    {
        zeros[i] = zeros[i + 1] + (prob[i] == 0);
        ones[i] = ones[i + 1] + (prob[i] == 100);
    }

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n + 1; i++)
        for(int j = 1; j <= n + 1; j++)
        {
            int tmp = fn(i, j);
       //     printf("%d %d %d\n", i, j, tmp);
            if(tmp <= k)
                ans++;
        }

    int tmp = fn(n + 1, n + 2);
   // printf("snsijnius %d\n", tmp);
    if(tmp <= k)
        ans++;

    printf("%d\n", ans);

    return 0;
}

int fn(int first, int sec)
{
    int& ret = dp[first][sec];
    if(ret != -1)
        return ret;
    ret = inf;

    if(first < 1 || sec < 2 || sec <= first)
        return ret;

    if(first == 1 && sec == 2)
    {
        ret = 0;
        return ret;
    }

    if(sec - first != 1)
    {
        if(prob[first] != 0 && ones[sec - 1] == 0)
            ret = min(ret, fn(first, sec - 1));
    }
    else
    {
        ///first killed and sec is the same
        if(!(first == n + 1 && sec == n + 2))
            for(int i = first - 1; i >= 1; i--)
            {
                if(zeros[first] != n - first + 1 && prob[i] != 100)
                    ret = min(ret, fn(i, first));
            }

     //   if((first == n + 1 && sec == n + 2))
       //     printf("nsdfijsfndi\n");

        ///both are killed
        int sec_d = sec - 2;
        for(int first_d = sec - 3; first_d >= 1; first_d--)
        {
            if(zeros[sec_d] != n - sec_d + 1 && prob[first_d] != 0)
                ret = min(ret, fn(first_d, sec_d));
        }
    }

    if(ret != inf)
        ret++;

    return ret;
}
