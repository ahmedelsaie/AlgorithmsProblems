#include <stdio.h>

int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);
int fn(int num, int mask);
int max(int x, int y);
void reset();

int comb[85][4];
int dp[90][(1 << 9) + 5];
int n_comb;

const int inf = 2147483647;

int main()
{
    int cases = 1;
    while(true)
    {
        scanf("%d", &n_comb);
        if(n_comb == 0)
            break;
        for(int i = 0; i < n_comb; i++)
            scanf("%d %d %d %d", &comb[i][0], &comb[i][1], &comb[i][2], &comb[i][3]);

        reset();
        int ans = fn(0, 0);

        printf("Case %d: ", cases);
        if(ans != -1 * inf)
            printf("%d\n", ans);
        else
            printf("-1\n");
        cases++;
    }
    return 0;
}

int fn(int num, int mask)
{
    if(mask == 1022)
        return 0;

    if(num == n_comb)
    {
        if(mask == 1022)
            return 0;
        else
            return -1 * inf;
    }


    int &ret = dp[num][mask];
    if(ret != -1)
        return ret;

    ret = -1 * inf;
    int temp = -1 * inf;
    int x = getbit(mask, comb[num][0]);
    int y = getbit(mask, comb[num][1]);
    int z = getbit(mask, comb[num][2]);

    if(!x && !y && !z && comb[num][2] != comb[num][1] && comb[num][0] != comb[num][1])
    {
        int new_mask = mask;
        new_mask = setbit(new_mask, comb[num][0], 1);
        new_mask = setbit(new_mask, comb[num][1], 1);
        new_mask = setbit(new_mask, comb[num][2], 1);
        temp = fn(num + 1, new_mask);
        if(temp != -1 * inf)
            temp += comb[num][3];
        ret = max(ret, temp);
    }

    temp = fn(num + 1, mask);
    ret = max(ret, temp);

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

void reset()
{
    for(int i = 0; i < n_comb + 6; i++)
        for(int j = 0; j < (1 << 9) + 5; j++)
            dp[i][j] = -1;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
