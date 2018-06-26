#include <bits/stdc++.h>
using namespace std;
#define MAX 10009
#define ll long long

void rot(int x, int flag);
void print();

int arr[105][105];
int q[5][MAX];
int row, col, n;

int main()
{
    scanf("%d %d %d", &row, &col, &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &q[0][i]);

        if(q[0][i] == 1 || q[0][i] == 2)
            scanf("%d", &q[1][i]);
        else
            scanf("%d %d %d", &q[1][i], &q[2][i], &q[3][i]);
    }

    memset(arr, 0, sizeof(arr));
    for(int i = n - 1; i >= 0; i--)
    {
        if(q[0][i] == 1)
            rot(q[1][i], 0);
        else if(q[0][i] == 2)
            rot(q[1][i], 1);
        else
        {
            int r = q[1][i] - 1;
            int c = q[2][i] - 1;
            arr[r][c] = q[3][i];
        }

        print();
    }

    return 0;
}

void print()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }


}

void rot(int x, int flag)
{
    x--;
    ///0 row
    if(flag == 0)
    {
        ll tmp = arr[x][col - 1];

        for(int j = col - 1; j >= 1; j--)
            arr[x][j] = arr[x][j - 1];

        arr[x][0] = tmp;
    }
    else
    {
        ll tmp = arr[row - 1][x];

        for(int i = row - 1; i >= 1; i--)
            arr[i][x] = arr[i - 1][x];

        arr[0][x] = tmp;
    }

}
