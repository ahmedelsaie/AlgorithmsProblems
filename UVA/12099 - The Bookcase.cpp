#include <bits/stdc++.h>
using namespace std;
#define MAX 2100
#define ll long long

bool comp(pair<int, int> x, pair<int, int> y);
int fn(int i, int first, int sec);
int gn();
int max(int x, int y, int z);

int dp[71][MAX][MAX], val[71][MAX], best[71], accum[MAX];
bool v[71][MAX][MAX];
pair<int, int> array1[75];
int n, cases, sum, tc;
const int inf = 9999999;
int arr[MAX];
bool vis[MAX];

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        sum = 0;

        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &array1[i].first, &array1[i].second), sum += array1[i].second;

        printf("%d\n", gn());
    }

    return 0;
}

int gn()
{
    int ret = inf;
    memset(v, 0, sizeof(v));
    memset(val, 0, sizeof(val));

    sort(array1, array1 + n, comp);
    accum[0] = 0;
    for(int i = 0; i < n; i++)
        accum[i + 1] = array1[i].second + accum[i];

    fn(1, array1[0].second, 0);
    int tmp = 0;
    for(int i = 0; i < n; i++)
        best[i] = val[i][tmp];

    arr[0] = 0;
    int    diff = 1;

    for(int i = 1; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        diff = 1;
        tmp = inf;
        for(int j = i + 1; j < n; j++)
        {
            ///gettiing the diffeene val
            tmp = diff;
           for(int h = 0; h < diff; h++)
                if(vis[arr[h] + array1[j].second] == 0)
                    arr[tmp++] = arr[h] + array1[j].second, vis[arr[h] + array1[j].second]=1;
            diff = tmp;
            tmp = inf;

            for(int h = 0; h < diff; h++)
            {
                int k = accum[i] + arr[h];

                if(v[j][k][0] && accum[j] - k >= array1[i].second)
                {
                    tmp = min(tmp, max(fn(j + 1, k, array1[j].second), fn(i + 1, accum[i], 0)));
                }
            }

            ret = min(ret, tmp * (array1[i].first + array1[j].first + array1[0].first));

        }
    }

    return ret;
}

int max(int x, int y, int z)
{
    return max(max(x, y), z);
}

bool comp(pair<int, int> x, pair<int, int> y)
{
    return x.first > y.first;
}

int fn(int i, int first, int sec)
{
    if(i == n)
    {
        int ret = max(max(first, sec), sum - (first + sec));
        return ret;
    }

    int& ret = dp[i][first][sec];
    bool& flag = v[i][first][sec];
    if(flag)
        return ret;

    ret = inf, flag = 1;

    int tmp1 = fn(i + 1, first, sec);
    int tmp2 = fn(i + 1, first + array1[i].second, sec);

    int tmp3 = inf;
    if(sec || first != accum[i])
        tmp3 = fn(i + 1, first, sec + array1[i].second);

    ret = min(tmp1, tmp2);
    ret = min(ret, tmp3);

    if(sec == 0)
    {
        int t = min(tmp1, tmp2);
        val[i][first] = val[i][first] == 0 ? ret : min(ret, val[i][first]);
    }

    return ret;
}
