#include <bits/stdc++.h>
using namespace std;
#define MAX 10
#define ll long long

int check(int r, int c);
const int inf = 9999999;
char board[MAX][MAX];

int main()
{
    for(int i = 0; i < 8; i++)
        scanf("%s", board[i]);

    int a = inf, b = inf;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == 'W')
                a = min(a, check(i, j));
            else if(board[i][j] == 'B')
                b = min(b, check(i, j));
        }

    if(a <= b)
        printf("A");
    else
        printf("B");

    return 0;
}

int check(int r, int c)
{
    int ret = 0;
    if(board[r][c] == 'B')
    {
        int i;
        for(i = r + 1; i < 8; i++)
            if(board[i][c] == '.')
                ret++;
            else
                break;
//printf("%d\n",i);
        if(i != 8)
            return inf;
        return ret;
    }
    else
    {
        int i;
        for(i = r - 1; i >= 0; i--)
            if(board[i][c] == '.')
                ret++;
            else
                break;
        if(i != -1)
            return inf;
        return ret;
    }
}
