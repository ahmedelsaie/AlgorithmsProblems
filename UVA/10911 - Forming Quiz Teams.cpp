#include <stdio.h>
#include <math.h>

float dist(int first, int second);
float min(float x, float y);
void reset();
float fn(int mask);
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int cntbit(int mask);

int x[20];
int y[20];
float dp[65550];
float dp2[16][16];
int n;

int main()
{
    char input[25];
    int cases = 1;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        n *= 2;
        reset();
        for(int i = 0; i < n; i++)
            scanf("%s %d %d", input, &x[i], &y[i]);

        printf("Case %d: %.2f\n", cases, fn(0));
        cases++;
    }

    return 0;
}

float fn(int mask)
{
    if(cntbit(mask) == n)
        return 0;
    float &ret = dp[mask];
    if(ret != (float) - 1)
        return ret;

    ret = 10000000;
    for(int i = 0; i < n; i++)
    {
        if(!getbit(mask, i))
            for(int j = i + 1; j < n; j++)
                if(!getbit(mask, j))
                {
                    int new_mask = mask;
                    new_mask = setbit(new_mask, i, 1);
                    new_mask = setbit(new_mask, j, 1);
                    ret = min(ret, fn(new_mask) + dist(i, j));
                }
    }

    return ret;
}

float min(float x, float y)
{
    if(x < y)
        return x;
    else
        return y;
}

float dist(int first, int second)
{
    float &ans = dp2[first][second];
    if(ans != (float) - 1)
        return ans;

    ans = pow((float)(x[first] - x[second]), 2);
    ans += pow((float)(y[first] - y[second]), 2);
    ans = sqrt(ans);
    return ans;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
    }
    return ret;
}

void reset()
{
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++)
            dp2[i][j] = (float) - 1;

    for(int i = 0; i < pow(2, n) + 100; i++)
        dp[i] = (float) - 1;
}
