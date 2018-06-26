#include <stdio.h>
#include <cstring>

struct doll
{
    int h, w, d;
    int hollow_h, hollow_d;
};
doll toys[210];

int fn(int x, int y, int accum, int i);
void print(int x, int y, int accum, int i, int taken2);
void bsort();

int array1[105];
int array2[105];
int n;
const int inf = 99999999;
int dp[205][205][105];

int main()
{
    int ans;
    toys[202].hollow_d = inf;
    toys[202].hollow_h = inf;
    bool flag = true;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0; i < 2 * n; i++)
        {
            scanf("%d %d %d", &toys[i].h, &toys[i].d, &toys[i].w);
            toys[i].hollow_h = toys[i].h - 2 * toys[i].w;
            toys[i].hollow_d = toys[i].d - 2 * toys[i].w;
        }

        if(flag)
            flag = false;
        else
            printf("\n");

        bsort();
        memset(dp, -1, sizeof(dp));
        ans = fn(202, 202, 0, 0);
        print(202, 202, 0, 0, 0);
    }
    return 0;
}

int fn(int x, int y, int accum, int i)
{
    int &ret = dp[x][y][accum];
    if(ret != -1)
        return ret;

    if(accum > n)
        return ret = 0;

    if(i == 2 * n)
    {
        if(accum == n)
            return ret = 1;
        return ret = 0;
    }

    ret = 0;

    if(toys[x].hollow_h >= toys[i].h && toys[x].hollow_d >= toys[i].d)
        ret = ret | fn(i, y, accum + 1, i + 1);

    if(toys[y].hollow_h >= toys[i].h && toys[y].hollow_d >= toys[i].d)
        ret = ret | fn(x, i, accum, i + 1);

    return ret;
}

void print(int x, int y, int accum, int i, int taken2)
{
    if(i == 2 * n)
    {
        for(int j = 0; j < n; j++)
            printf("%d %d %d\n", toys[array1[j]].h, toys[array1[j]].d, toys[array1[j]].w);

        printf("-\n");

        for(int j = 0; j < n; j++)
            printf("%d %d %d\n", toys[array2[j]].h, toys[array2[j]].d, toys[array2[j]].w);
        return;
    }


    if(dp[i][y][accum + 1] == 1)
    {
        array1[accum] = i;
        print(i, y, accum + 1, i + 1, taken2);

    }
    else
    {
        array2[taken2] = i;
        print(x, i, accum, i + 1, taken2 + 1);
    }

    return;
}

void bsort()
{
    doll swap;
    for(int i = 0; i < 2 * n - 1; i++)
        for(int j = 0; j < 2 * n - 1; j++)
        {
            if(toys[j].hollow_d < toys[j + 1].hollow_d)
            {
                swap = toys[j];
                toys[j] = toys[j + 1];
                toys[j + 1] = swap;
            }
        }
}
