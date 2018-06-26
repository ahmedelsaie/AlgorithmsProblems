#include <stdio.h>
#include <cstring>

int fn(int curr, int msk, int left, int x0, int y0);
int dist(int x0, int y0, int x1, int y1);
bool check(int msk, int x0, int y0, int x1, int y1);
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int con(int i, int j);
int abs(int x);
int max(int x, int y);
int min(int x, int y);

int dp[13][(1 << 12) + 1][1002];
int visited[13][(1 << 12) + 1][1002];

int col = 3, cases = 0, no_msk, len, n;

int main()
{
    int x, y, ans;
    memset(visited, -1, sizeof(visited));
    scanf ("%d", &cases);

    while(cases--)
    {
        no_msk = 0, ans = 0;
        scanf("%d %d", &len, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &y, &x);
            x = 4 - x + 1;
            x--, y--;
            no_msk = setbit(no_msk, con(x, y), 1);
        }

        for(int x = 0; x < 4; x++)
            for(int y = 0; y < 3; y++)
                if(getbit(no_msk, con(x, y)) == 0)
                    ans += fn(con(x, y), setbit(0, con(x, y), 1), len, x, y);

        if(ans == 0)
            printf("BAD MEMORY");
        else
            printf("%d", ans);

        printf("\n");
    }

    return 0;
}

int fn(int curr, int msk, int left, int x0, int y0)
{
    if(left < 0)
        return 0;

    if(left == 0)
        return 1;

    int& ret = dp[curr][msk][left];
    int& flag = visited[curr][msk][left];
    if(flag == cases)
        return ret;

    ret = 0;
    flag = cases;

    for(int x = 0; x < 4; x++)
        for(int y = 0; y < 3; y++)
            if(getbit(no_msk, con(x, y)) == 0  && getbit(msk, con(x, y)) == 0 && con(x, y) != curr && check(msk, x0, y0, x, y))
            {
                ret += fn(con(x, y), setbit(msk, con(x, y), 1), left - dist(x0, y0, x, y), x, y);
            }

    return ret;
}

bool check(int msk, int x0, int y0, int x1, int y1)
{
    if(y0 == y1)
    {
        for(int i = min(x1, x0) + 1; i < max(x0, x1); i++)
            if(getbit(no_msk, con(i, y0)) == 1 || getbit(msk, con(i, y0)) == 0)
                return false;
    }

    if(x0 == x1)
    {
        for(int i = min(y1, y0) + 1; i < max(y0, y1); i++)
            if(getbit(no_msk, con(x0, i)) == 1 || getbit(msk, con(x0, i)) == 0)
                return false;
    }

    if ( (x1 == 1 && y1 == 0 && x0 == 3 && y0 == 2) || (x0 == 1 && y0 == 0 && x1 == 3 && y1 == 2))
    {
        if(getbit(no_msk, con(2, 1)) == 1)
            return false;

        if(getbit(msk, con(2, 1)) == 0)
            return false;
    }

    if ( (x1 == 0 && y1 == 0 && x0 == 2 && y0 == 2) || (x0 == 0 && y0 == 0 && x1 == 2 && y1 == 2))
    {
        if(getbit(no_msk, con(1, 1)) == 1)
            return false;

        if(getbit(msk, con(1, 1)) == 0)
            return false;
    }

    if ( (x1 == 3 && y1 == 0 && x0 == 1 && y0 == 2) || (x0 == 3 && y0 == 0 && x1 == 1 && y1 == 2))
    {
        if(getbit(no_msk, con(2, 1)) == 1)
            return false;

        if(getbit(msk, con(2, 1)) == 0)
            return false;
    }

    if ( (x1 == 2 && y1 == 0 && x0 == 0 && y0 == 2) || (x0 == 2 && y0 == 0 && x1 == 0 && y1 == 2))
    {
        if(getbit(no_msk, con(1, 1)) == 1)
            return false;

        if(getbit(msk, con(1, 1)) == 0)
            return false;
    }

    return true;
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

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int dist(int x0, int y0, int x1, int y1)
{
    return abs(x0 - x1) + abs(y0 - y1);
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
