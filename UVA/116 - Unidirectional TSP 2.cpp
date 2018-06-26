#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void fn();
void print();

int arr[15][105];
int dp[15][105];
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
        fn();
        print();
        printf("\n");
    }

    return 0;
}

void fn()
{
    int maxi;

    for(int i = 0; i < m_main; i++)
        dp[i][n_main - 1] = arr[i][n_main - 1];

    if(n_main == 1)
        return;

    for(int i = n_main - 2; i >= 0; i--)
        for(int j = 0; j < m_main; j++)
        {
            maxi = inf;

            if(j == m_main - 1 && dp[0][i + 1] < maxi)
                maxi = dp[0][i + 1];

            if(j - 1 >= 0 && dp[j - 1][i + 1] < maxi)
                maxi = dp[j - 1][i + 1];

            if(dp[j][i + 1] < maxi)
                maxi = dp[j][i + 1];

            if(j + 1 < m_main && dp[j + 1][i + 1] < maxi)
                maxi = dp[j + 1][i + 1];

            if(j == 0 && dp[m_main - 1][i + 1] < maxi)
                maxi = dp[m_main - 1][i + 1];

            dp[j][i] = maxi + arr[j][i];
        }
}

void print()
{
    for(int i = 0; i < m_main; i++)
    {
        last2 = dp[i][0];
        if(last2 < last)
        {
            last = last2;
            first = i + 1;
        }
    }


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
        if(m == m_main - 1 &&  dp[0][i + 1] < max1)
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
