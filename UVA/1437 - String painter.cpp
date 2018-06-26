#include <bits/stdc++.h>
using namespace std;

int fn(int start, int end, int changed);
int get_nxt(int start, int end);
int min(int x, int y);

int bad = 30;
char arr1[105];
char arr2[105];
int dp[105][105][34];

const int inf = 9999999;
int n;

int main()
{
    bool flag = true;
    while(scanf("%s %s",arr1,arr2) == 2)
    {
        n = strlen(arr1);
        memset(dp, -1, sizeof(dp));

        printf("%d", fn(0, n - 1, bad));
        printf("\n");
    }

    return 0;
}

int fn(int start, int end, int changed)
{
    if(end < start || start == n)
        return 0;

    int &ret = dp[start][end][changed];
    if(ret != -1)
        return ret;

    ret = inf;
    int x;

    if(changed == bad)
    {
        if(arr1[start] == arr2[start])
            ret = min(ret, fn(start + 1, end, bad));
        else
        {
            for(int i = start; i <= end; i++)
                ret = min(ret, fn(start, i, arr2[start] - 'a') + 1 + fn(i + 1, end, bad));
        }
    }
    else
    {
        if(changed == arr2[start] - 'a')
            ret = min(ret, fn(start + 1, end, changed));
        else
        {
            for(int i = start; i <= end; i++)
                ret = min(ret, fn(start, i, arr2[start] - 'a') + 1 + fn(i + 1, end, changed));
        }
    }
    return ret;
}

int get_nxt(int start, int end)
{
    //printf("%d %d\n",start,end);
    for(int i = start + 1; i < end; i++)

        if(arr2[i] == arr2[start]) // && arr1[i]!=arr2[i])
        {
            return i;
        }
    //printf("no\n");
    return -1;
}


int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
