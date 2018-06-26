#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int fn(int m, int n);
void print();
void reset();

int arr[200][200];
int dp[200][200];
int m_main, n_main;
int last;
int last2;
int first;
const int inf = 2147483647;

int main()
{
    int n = 0;
    int t = 0;

    while(scanf("%d", &m_main) != EOF)
    {
        scanf("%d", &n_main);

        for(int i = 0; i < m_main; i++)
            for(int j = 0; j < n_main; j++)
                scanf("%d", &arr[i][j]);

        last = inf;
        reset();

        for(int i = 0; i < m_main; i++)
        {
            last2 = fn(i, 0);
            if(last2 < last)
            {
                last = last2;
                first = i + 1;
            }
        }

        print();
        printf("\n");
    }

    return 0;
}

void print()
{
    printf("%d", first);
    if(n_main == 1)
    {
        printf("\n%d", last);
        return;
    }

    if(m_main == 1)
    {
        for(int i = 0; i < n_main - 1; i++)
            printf(" %d", 1);
        printf("\n%d", last);
        return;
    }

    int m = first - 1;
    int current = 0;
    int max1;
    for(int i = 0; i < n_main - 1; i++)
    {
        max1 = inf;
        if(m == m_main - 1 && dp[0][i + 1] < max1)
        {
            max1 = dp[0][i + 1];
            current = 0;
        }

        if(m - 1 >= 0 && dp[m - 1][i + 1] < max1)
        {
            max1 = dp[m - 1][i + 1];
            current = m - 1;
        }

        if(dp[m][i + 1] < max1)
        {
            max1 = dp[m][i + 1];
            current = m;
        }

        if(m + 1 < m_main && dp[m + 1][i + 1] < max1)
        {
            max1 = dp[m + 1][i + 1];
            current = m + 1;
        }

        if( m == 0 &&  dp[m_main - 1][i + 1] < max1)
        {
            max1 = dp[m_main - 1][i + 1];
            current = m_main - 1;
        }

        m = current;
        printf(" %d", current + 1);
    }

    printf("\n%d", last);
}

int fn(int m, int n)
{
    if(n < 0 || n >= n_main)
        return inf;

    if(m < 0 || m >= m_main)
        return inf;

    int max1 = inf, l;
    int &ret = dp[m][n];

    if(ret != inf)
        return dp[m][n];

    if(n == n_main - 1)
        return ret = arr[m][n];

    if(m == m_main - 1)
    {
        l = fn(0, n + 1);
        if(l < max1)
            max1 = l;
    }

    if(m == 0)
    {
        l = fn(m_main - 1, n + 1);
        if(l < max1)
            max1 = l;
    }

    l = fn(m - 1, n + 1);
    if(l < max1 )
        max1 = l;

    l = fn(m, n + 1);
    if(l < max1 )
        max1 = l;

    l = fn(m + 1, n + 1);
    if(l < max1 )
        max1 = l;

    return ret = max1 + arr[m][n];
}

void reset()
{
    for(int i = 0; i < m_main + 5; i++)
        for(int j = 0; j < n_main + 5; j++)
            dp[i][j] = inf;
}
