#include <bits/stdc++.h>
using namespace std;
#define MAX 60
#define ll long long

int fn(int x, int y, int f1, int f2);

char arr1[MAX], arr2[MAX];
int dp[MAX][MAX][2][2], m, n, tc;
const int inf = 999999999;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s %s", arr1, arr2);
        n = strlen(arr1), m = strlen(arr2);

        memset(dp, -1, sizeof(dp));
        int ans = fn(0, 0, 0, 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans = max(ans, fn(i, j, 0, 0));

        printf("%d\n", ans);
    }

    return 0;
}

int fn(int x, int y, int f1, int f2)
{
    if(x == n && y == m) return 0;
    if(x == n || y == m)
    {
        if(x == n && f2) return 0;
        if(y == m && f1) return 0;
        return -1;
    }

    int& ret = dp[x][y][f1][f2];
    if(ret != -1) return ret;
    ret = -1 * inf;

    if(!f1 && !f2)  ///no one
    {
        ret = max(ret, fn(x + 1, y + 1, 0, 0) + 2 * (arr1[x] == arr2[y])); ///keep them

        ret = max(ret, fn(x, y + 1, 1, 0) - 1); ///open up
        ret = max(ret, fn(x + 1, y, 0, 1) - 1); ///open down
    }

    if(f1 && !f2)  ///if up
    {
        ret = max(ret, fn(x, y + 1, 1, 0));  ///skip down
        ret = max(ret, fn(x, y, 0, 0));  ///close up
    }

    if(f2 && !f1) ///if down
    {
        ret = max(ret, fn(x + 1, y, 0, 1)); ///skip down
        ret = max(ret, fn(x, y, 0, 0));  ///close up
    }

    return ret;
}
