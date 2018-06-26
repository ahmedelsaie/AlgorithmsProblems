#include <stdio.h>

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int cntbit(int mask);
int process();
int min(int x, int y);
int fn(int mask);
void reset();

char input[13];
int dp[4100];
int inf = 100000000;

int main()
{
    reset();
    int cases, mask;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%s", input);
        mask = process();
        printf("%d\n", fn(mask));
    }
    return 0;

}

void reset()
{
    for(int i = 0; i < 4100; i++)
        dp[i] = -1;
}

int fn(int mask)
{
    // printf("mask= %d\n",mask);
    int &ret = dp[mask];
    if(ret != -1)
        return ret;
    int new_mask;
    ret = inf;
    bool flag = true;
    for(int i = 0; i < 10; i++)
    {
        if(getbit(mask, i) && getbit(mask, i + 1) && !getbit(mask, i + 2))
        {
            flag = false;
            new_mask = mask;
            new_mask = setbit(new_mask, i, 0);
            new_mask = setbit(new_mask, i + 1, 0);
            new_mask = setbit(new_mask, i + 2, 1);
            ret = min(ret, fn(new_mask));
        }

        if(!getbit(mask, i) && getbit(mask, i + 1) && getbit(mask, i + 2))
        {
            new_mask = mask;
            flag = false;
            new_mask = setbit(new_mask, i, 1);
            new_mask = setbit(new_mask, i + 1, 0);
            new_mask = setbit(new_mask, i + 2, 0);
            ret = min(ret, fn(new_mask));
        }
    }
    return ret = min(ret, cntbit(mask));
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int process()
{
    int ret = 0;
    for(int i = 0; i < 12; i++)
    {
        if(input[11 - i] == 'o')
            ret = setbit(ret, i, 1);
        else
            ret = setbit(ret, i, 0);
    }
    return ret;
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
