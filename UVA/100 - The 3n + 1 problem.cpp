#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int fn(int x);
void reset();

int dp[1000000];

int main()
{
    int start, end, max, c;
    reset();

    while(scanf("%d", &start) != EOF)
    {
        max = 0;
        c = 0;

        scanf("%d", &end);
        if(start < end)
        {
            for(int i = start; i <= end; i++)
            {
                c = fn(i);
                if(c > max)
                    max = c;
            }
        }
        else
        {
            for(int i = end; i <= start; i++)
            {
                c = fn(i);
                if(c > max)
                    max = c;
            }
        }
        printf("%d %d %d\n", start, end, max);
    }

    return 0;
}

void reset()
{
    for(int i = 0; i < 1000000; i++)
        dp[i] = -1;
}

int fn(int x)
{
    int &ret = dp[x];
    if(ret != -1)
        return ret;
    int flag = 1;
    while(x != 1)
    {
        if(x % 2 == 0)
            x = x / 2;
        else
            x = 3 * x + 1;
        flag++;
    }
    return ret = flag;
}

