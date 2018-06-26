#include <stdio.h>
#include <cstdio>
#include <cstring>

int fn(int current, int last, int prev_sum);
void reset();

int cat;
int categories[1005];
int no_pearls[1005];
int dp[1005][1005];

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int j = 0; j < cases; j++)
    {
        scanf("%d", &cat);
        for(int i = 0; i < cat; i++)
        {
            scanf("%d%d", &no_pearls[i], &categories[i]);
        }

        reset();

        printf("%d\n", fn(0, 0, 0));
    }

    return 0;
}

int fn(int current, int last, int prev_sum)
{
    if(current == cat)
    {
        if(last != current)
            return (int)1e9;

        return 0;
    }
    int &ret = dp[current][last];

    if(ret != (int)1e9)
        return ret;


    int x1 = (int)1e9, x2 = (int)1e9;

    //for(int i=last;i<=current;i++)
    //sum+=no_pearls[i];
    int sum = 10 + prev_sum + no_pearls[current];

    x1 = fn(current + 1, current + 1, 0) + sum * categories[current];

    x2 = fn(current + 1, last, prev_sum + no_pearls[current]);

    if(x1 < x2)
        return ret = x1;
    else
        return ret = x2;
}

void reset()
{
    for(int i = 0; i < cat + 2; i++)
        for(int j = 0; j < cat; j++)
            dp[i][j] = (int)1e9;
}
