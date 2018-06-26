#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
int fn(int start, int end);
int comp(const string &help, const string &help2);
void reverse();
void reset();
int max(int x, int y);


const int inf = 99999;
string got[60][60];
int dp[60][60];
int n;
char cities[60][60];
char input[60];
string p;
char f[60];

int main()
{
    int cases;
    int l, m;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &n);

        for(int j = 0; j < n; j++)
            scanf("%s", cities[j]);

        reset();
        int t = fn(0, n - 1);

        if(t <= 0)
            printf("NO PALINDROMIC PATH\n");
        else
        {
            p = got[0][n - 1];
            reverse();
            printf("%s\n", f);
        }
    }

    return 0;
}

void reverse()
{
    int l = p.length();
    f[0] = '\0';

    for(int i = 0; i < l; i++)
        f[i] = p[i];

    if(f[l - 1] == '0')
    {
        l--;
        for(int i = 0; i < l; i++)
            f[2 * l - i - 1] = f[i];
        f[2 * l] = '\0';
    }
    else
    {
        int j = 2 * l - 2;
        for(int i = 0; i < l - 1; i++)
        {
            f[j] = f[i];
            j--;
        }
        f[2 * l - 1] = '\0';
    }

    return ;
}

int fn(int start, int end)
{
    if(start == end)
    {
        string r = "0";
        got[start][end] = r;
        return 0;
    }

    int &ret = dp[start][end];
    if(ret != -1)
        return ret;

    string help;
    string last;

    int ans = 0, temp = 0;
    bool flag = true;

    if(cities[end][start] != '*')
    {
        flag = false;
        string r;
        r = cities[start][end];
        temp = 1;
        help = r;

        if(temp > ans)
        {
            ans = temp;
            last = help;
        }
        if(temp == ans)
        {
            if(comp(help, last) == 1)
                last = help;
        }
    }

    for(int i = start + 1; i < end; i++)
        for(int j = end; j >= i; j--)
        {
            if(cities[start][i] == cities[end][j] && cities[end][j] != '*')
            {
                flag = false;
                string r;
                r = cities[start][i];
                temp = fn(i, j) + 1;
                r += got[i][j];
                help = r;

                if(temp > ans)
                {
                    ans = temp;
                    last = help;
                }
                if(temp == ans)
                {
                    if(comp(help, last) == 1)
                        last = help;
                }
            }
        }

    if(flag)
        return -1 * inf;

    got[start][end] = last;

    return ret = ans;
}

int comp(const string &help, const string &help2)
{
    int x1 = help.length();
    int x2 = help2.length();

    if(help[x1 - 1] != '0' && help2[x2 - 1] != '0')
    {
        if(help2 < help)
            return 2;
        else
            return 1;
    }

    if(help[x1 - 1] == '0' && help2[x2 - 1] == '0')
    {
        if(help2 < help)
            return 2;
        else
            return 1;
    }

    if(help[x1 - 1] == '0' && help2[x2 - 1] != '0')
        return 1;

    if(help[x1 - 1] != '0' && help2[x2 - 1] == '0')
        return 2;
}

void reset()
{
    for(int i = 0; i < n + 10; i++)
        for(int j = 0; j < n + 10; j++)
            dp[i][j] = -1;
    return;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
