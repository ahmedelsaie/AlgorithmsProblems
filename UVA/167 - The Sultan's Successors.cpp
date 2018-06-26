#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

bool check(int i, int j);
void fn(int i, int value);
int max(int x, int y);
int abs(int x);

int accum[9];
int board[9][9];
int ans;

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int k = 0; k < cases; k++)
    {
        ans = 0;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                scanf("%d", &board[i][j]);

        fn(0, 0);
        printf("%5d\n", ans);
    }

    return 0;
}

void fn(int i, int value)
{
    if(i == 8)
    {
        ans = max(ans, value);
        return ;
    }

    for(int j = 0; j < 8; j++)
    {
        if(check(i, j))
        {
            accum[i] = j;
            fn(i + 1, value + board[i][j]);
        }

    }
}

bool check(int i, int j)
{
    for(int k = 0; k < i; k++)
        if(accum[k] == j || abs(accum[k] - j) == abs(k - i))
            return false;
    return true;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
