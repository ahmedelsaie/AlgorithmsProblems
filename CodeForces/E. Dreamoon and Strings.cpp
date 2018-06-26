#include <bits/stdc++.h>
using namespace std;
#define MAX 2005
#define ll long long

int gn(int pos, int left);
int fn(int x, int y);

char a[MAX], p[MAX];
int m, n, dp1[MAX][MAX], dp2[MAX][MAX];
const int inf = 9999999;

int main()
{
    scanf("%s %s", a, p);
    m = strlen(a), n = strlen(p);

    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    for(int i = 0; i <= m; i++)
        printf("%d ", gn(0, i));

    printf("\n");

    return 0;
}

int fn(int x, int y)
{
    if(y == n) return 0;
    if(x == m) return inf;

    int &ret = dp1[x][y];
    if(ret != -1) return ret;

    ret = fn(x + 1, y + (a[x] == p[y])) + 1;

    return ret;
}

int gn(int pos, int left)
{
    if(pos > m || left < 0)
        return -inf;

    if(pos == m)
        return left == 0 ? 0 : -inf;

    int &ret = dp2[pos][left];
    if(ret != -1) return ret;
    ret = -inf;

    int tmp = fn(pos, 0);

    ret = max(gn(pos + 1, left), gn(pos + 1, left - 1));

    ret = max(ret, gn(pos + tmp, left - abs(tmp - n)) + 1);

    return ret;
}


