#include <stdio.h>
#include <cstring>
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int fn(int mask, int left);
int check(int x, int mask, int mode);
int con(int i, int j);

int row, col, n;
int dp[5][5][(1 << 16) + 5];

int main()
{
    int mask, x, y, cases, p = 1;
    scanf("%d", &cases);
    memset(dp, -1, sizeof(dp));

    while(cases--)
    {
        mask = 0;
        scanf("%d %d %d", &row, &col, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            mask = setbit(mask, con(x - 1, y - 1), 1);
        }

        printf("Case %d: %d\n", p++, fn(mask, n));
    }

    return 0;
}

int fn(int mask, int left)
{
    if(left == 1)
        return 1;

    int &ret = dp[row][col][mask];
    if(ret != -1)
        return ret;
    ret = 0;

    int temp;

    for(int i = 0; i < row * col; i++)
        for(int j = 1; j <= 8; j++)
        {
            temp = check(i, mask, j);
            if(temp != -1)
                ret += fn(temp, left - 1);
        }

    return ret;
}

int check(int x, int mask, int mode)
{
    int r, c, ret;
    c = x % col;
    r = (x - c) / col;

    if(!getbit(mask, x))
        return -1;

    if(mode == 1)
    {
        if(c >= 2 && getbit(mask, con(r, c - 1)) && !getbit(mask, con(r, c - 2)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r, c - 1), 0);
            ret = setbit(ret, con(r, c - 2), 1);
            return ret;
        }
        return -1;
    }

    if(mode == 2)
    {
        if(c + 2 < col && getbit(mask, con(r, c + 1)) && !getbit(mask, con(r, c + 2)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r, c + 1), 0);
            ret = setbit(ret, con(r, c + 2), 1);
            return ret;
        }
        return -1;
    }

    if(mode == 3)
    {
        if(r >= 2 && getbit(mask, con(r - 1, c)) && !getbit(mask, con(r - 2, c)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r - 1, c), 0);
            ret = setbit(ret, con(r - 2, c), 1);
            return ret;
        }
        return -1;
    }

    if(mode == 4)
    {
        if(r + 2 < row && getbit(mask, con(r + 1, c)) && !getbit(mask, con(r + 2, c)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r + 1, c), 0);
            ret = setbit(ret, con(r + 2, c), 1);
            return ret;
        }
        return -1;
    }

    if(mode == 5)
    {
        if(c >= 2 && r >= 2 && getbit(mask, con(r - 1, c - 1)) && !getbit(mask, con(r - 2, c - 2)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r - 1, c - 1), 0);
            ret = setbit(ret, con(r - 2, c - 2), 1);
            return ret;
        }
        return -1;
    }

    if(mode == 6)
    {
        if(c + 2 < col && r >= 2 && getbit(mask, con(r - 1, c + 1)) && !getbit(mask, con(r - 2, c + 2)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r - 1, c + 1), 0);
            ret = setbit(ret, con(r - 2, c + 2), 1);
            return ret;
        }
        return -1;
    }

    if(mode == 7)
    {
        if(c >= 2 && r + 2 < row && getbit(mask, con(r + 1, c - 1)) && !getbit(mask, con(r + 2, c - 2)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r + 1, c - 1), 0);
            ret = setbit(ret, con(r + 2, c - 2), 1);
            return ret;
        }
        return -1;
    }

    if(mode == 8)
    {
        if(c + 2 < col && r + 2 < row && getbit(mask, con(r + 1, c + 1)) && !getbit(mask, con(r + 2, c + 2)))
        {
            ret = setbit(mask, x, 0);
            ret = setbit(ret, con(r + 1, c + 1), 0);
            ret = setbit(ret, con(r + 2, c + 2), 1);
            return ret;
        }
        return -1;
    }

}

int con(int i, int j)
{
    return j + i * col;
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
