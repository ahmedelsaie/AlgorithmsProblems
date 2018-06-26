#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

long long fn(int left, int right);
void print(int left, int right);
void reset();

int no;
long long rows[15];
long long cols[15];
long long dp[15][15];
long long inf = 2000000000;

int main()
{
    int cases = 1;

    while(true)
    {
        scanf("%d", &no);
        if(no == 0)
            break;

        for(int i = 0; i < no; i++)
            scanf("%d %d", &rows[i], &cols[i]);

        reset();
        fn(0, no - 1);
        printf("Case %d: ", cases);
        print(0, no - 1);
        printf("\n");
        cases++;
    }

    return 0;
}

void print(int left, int right)
{
    if(left == right)
    {
        printf("A%d", right + 1);
        return ;
    }

    long long x;
    long long max1 = inf;
    int y;

    for(int i = left; i < right; i++)
    {
        x = fn(left, i) + fn(i + 1, right) + rows[i + 1] * cols[right] * rows[left];
        if(x <= max1)
        {
            max1 = x;
            y = i;
        }
    }

    printf("(");
    print(left, y);
    printf(" x ");
    print(y + 1, right);
    printf(")");

    return ;
}

long long fn(int left, int right)
{
    long long &ret = dp[left][right];


    if(left >= right)
        return ret = 0;

    if(ret != -1)
        return ret;

    long long x;
    long long max1 = inf;

    for(int i = left; i < right; i++)
    {
        x = fn(left, i) + fn(i + 1, right) + rows[i + 1] * cols[right] * rows[left];
        if(x < max1)
            max1 = x;
    }

    return ret = max1;
}

void reset()
{
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            dp[i][j] = -1;
}
