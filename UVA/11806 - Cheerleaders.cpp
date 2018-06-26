#include <stdio.h>
#include <cstring>
#define ll long long
#define mod 1000007

int setbit(int mask, int bit, int value);
ll fn(int row, int col, int left, int msk);

ll dp[22][22][505][16];
int visited[22][22][505][16];

int n_row, n_col, cases = 1, left;

int main()
{
    int tc;
    memset(visited, -1, sizeof(visited));

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d %d", &n_row, &n_col, &left);
        printf("Case %d: %lld\n", cases++, fn(0, 0, left, 0) % mod);
    }

    return 0;
}

ll fn(int row, int col, int left, int msk)
{
    if(left == 0)
    {
        if(msk == 15)
            return 1;
        return 0;
    }

    if(row == n_row)
        return 0;

    if(col == n_col)
        return fn(row + 1, 0, left, msk) % mod;

    ll& ret = dp[row][col][left][msk];
    int& flag = visited[row][col][left][msk];
    if(flag == cases)
        return ret;
    ret = 0;
    flag = cases;

    int new_msk = msk;
    ret += fn(row, col + 1, left, msk) % mod;

    if(row == 0)
        new_msk = setbit(new_msk, 0, 1);

    if(row == n_row - 1)
        new_msk = setbit(new_msk, 2, 1);

    if(col == n_col - 1)
        new_msk = setbit(new_msk, 1, 1);

    if(col == 0)
        new_msk = setbit(new_msk, 3, 1);

    ret += fn(row, col + 1, left - 1, new_msk) % mod;
    ret = ret % mod;
    return ret;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}
