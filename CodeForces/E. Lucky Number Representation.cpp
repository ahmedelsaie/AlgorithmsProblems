#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int fn(int i, int j, int sum);
void trace(int i, int j, int sum);
void print();

int v[20][10][300], dp[20][10][300], arr[20], res[20][20];
int n,cases;
ll x;

int main()
{
    memset(v, -1, sizeof(v));

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lld", &x);
        ll y = x;
        n = 0;
        while(y)
            arr[n++] = y % 10, y /= 10;

        memset(res, 0, sizeof(res));

        int ans = fn(0, 0, 0);
        if(ans == 0)
            printf("-1");
        else
            trace(0, 0, 0), print();

        printf("\n");
    }

    return 0;
}

void print()
{
    for(int i = 0; i < 6; i++)
    {
        ll tmp = 0;
      //  printf("%d === i\n",i);
        for(int j = 19; j >= 0; j--)
            tmp = tmp * (ll)10 +(ll) res[i][j];//printf("%d ",res[i][j]);

        printf("%lld ", tmp);
    }
}

void trace(int i, int j, int sum)
{
    if(i == n)
        return ;

    if(j == 6)
        return trace(i + 1, 0, sum / 10);
    else
    {
        if(fn(i, j + 1, sum + 7) == 1)
        {
            res[j][i] = 7;
            trace(i, j + 1, sum + 7);
            return;
        }

        if(fn(i, j + 1, sum + 4) == 1)
        {
            res[j][i] = 4;
            trace(i, j + 1, sum + 4);
            return;
        }

        if(fn(i, j + 1, sum + 0) == 1)
        {
            res[j][i] = 0;
            trace(i, j + 1, sum + 0);
            return;
        }
    }
}

int fn(int i, int j, int sum)
{
    if(i == n)
        return sum == 0;

    int &flag = v[i][j][sum];
    int &ret = dp[i][j][sum];

    if(flag == cases)
        return ret;

    flag = cases;
    ret = 0;

    if(j == 6)
    {
        if(sum % 10 == arr[i])
            ret = fn(i + 1, 0, sum / 10);
    }
    else
    {
        ret = max(ret, fn(i, j + 1, sum + 7));
        ret = max(ret, fn(i, j + 1, sum + 4));
        ret = max(ret, fn(i, j + 1, sum + 0));
    }

    return ret;
}
