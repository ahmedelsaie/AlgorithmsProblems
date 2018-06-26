#include <stdio.h>
#include <cstring>
int fn(int trip, int spheres);
int min(int x, int y);

int dp[110][110];
int arr_spheres[105];
int time[105];

const int inf = 0xfffffff;
int n;

int main()
{
    while(scanf("%d", &n) == 1 && n)
    {
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d %d", &time[i], &arr_spheres[i]);

        memset(dp, -1, sizeof(dp));

        printf("%d\n", fn(0, 0));
    }
    return 0;
}

int fn(int trip, int spheres)
{
    if(trip == n)
        return 0;

    int &ret = dp[trip][spheres];
    if(ret != -1)
        return ret;
    ret = inf;

    int new_spheres = spheres + arr_spheres[trip];
    if(new_spheres > 105)
        new_spheres = 105;

    ret = min(ret, fn(trip + 1, new_spheres) + time[trip]);

    if(spheres > 0)
        ret = min(ret, fn(trip + 1, new_spheres - 1) + time[trip] / 2);

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
