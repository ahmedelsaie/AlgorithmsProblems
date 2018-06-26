#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void fn(int row, int col, int square, int off);
int min(int x, int y);
int abs(int x);
void update();

int offices_x[6];
int offices_y[6];
int offices_n[6];
int n;
const int inf = 99999999;
int area_x[30];
int area_y[30];
int area_n[30];

int result;
int result_array[5];

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int c = 0; c < cases; c++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d %d", &area_x[i], &area_y[i], &area_n[i]);

        result = inf;
        fn(0, 0, 0, 0);

        for(int i = 0; i < 5; i++)
        {
            printf("%d", result_array[i]);
            if(i < 4)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}

void fn(int row, int col, int square, int off)
{
    if(off == 5)
    {
        update();
        return ;
    }


    if(col >= 5)
        return fn(row + 1, 0, square, off);

    if(row >= 5)
        return ;

    offices_x[off] = row;
    offices_y[off] = col;
    offices_n[off] = square;
    fn(row, col + 1, square + 1, off + 1);

    fn(row, col + 1, square + 1, off);

    return ;

}

void update()
{
    int ans = 0;
    int temp;
    int min_temp;

    for(int i = 0; i < n; i++)
    {
        min_temp = inf;
        for(int j = 0; j < 5; j++)
        {
            temp = abs(offices_x[j] - area_x[i]) + abs(offices_y[j] - area_y[i]);
            min_temp = min(min_temp, temp);

        }
        ans += min_temp * area_n[i];
    }

    if(ans < result)
    {
        for(int j = 0; j < 5; j++)
            result_array[j] = offices_n[j];
        result = ans;
    }
    return ;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
