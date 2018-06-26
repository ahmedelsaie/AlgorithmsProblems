#include <bits/stdc++.h>
using namespace std;
#define MAX 2009
#define ll long long

struct node
{
    int start, end, cnt, v;
};

int fn();

int land[MAX][MAX], accum[MAX][MAX], n, m, x, num, c, indx = 0, cases = 1, tc;
vector<int> vec[MAX];
node arr[MAX];

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        memset(accum, 0, sizeof(accum));
        memset(land, 0, sizeof(land));

        scanf("%d %d", &n, &m);
        m++, n++;

        for(int i = 1; i < n; i++)
        {
            indx = 1;
            scanf("%d %d", &num, &c);
            for(int j = 0; j < num; j++)
            {
                scanf("%d", &x);
                for(int k = 0; k < x; k++)
                    land[i][indx++] = !c;
                c = !c;
            }
        }

        printf("Case %d: %d\n", cases++, fn());
    }

    return 0;
}

int fn()
{
    int ret = 0;
    for(int j = 1; j < m; j++)
        for(int i = n - 1; i >= 1; i--)
            accum[i][j] = (land[i][j] == 0 ? 0 : accum[i + 1][j] + 1);

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= max(n, m); j++)
            vec[j].clear(), arr[j].v = 0;

        for(int j = 1; j < m; j++)
            vec[accum[i][j]].push_back(j);

        for(int j = n; j >= 0; j--)
            if(vec[j].size())
                for(int k = vec[j].size() - 1; k >= 0; k--)
                {
                    int p = vec[j][k];
                    if(arr[p + 1].v + arr[p - 1].v == 0) ///both are empty
                    {
                        arr[p].cnt = 1;
                        arr[p].start = p;
                        arr[p].end = p + 1;
                        arr[p].v = 1;
                        ret = max(ret, j * 1);
                    }
                    else if(arr[p + 1].v + arr[p - 1].v == 2)///both are there
                    {
                        int s = arr[p - 1].start;
                        arr[s].end = arr[p + 1].end;
                        arr[s].cnt += arr[p + 1].cnt + 1;

                        int e = arr[p + 1].end - 1;
                        arr[e].start = s;
                        arr[e].cnt = arr[s].cnt;

                        ret = max(ret, j * arr[s].cnt);
                    }
                    else if(arr[p + 1].v && !arr[p - 1].v) ///second only
                    {
                        arr[p] = arr[p + 1];
                        arr[p].start--;
                        arr[p].cnt++;
                        arr[p].v = 1;

                        int e = arr[p + 1].end - 1;
                        arr[e].start = p;
                        ret = max(ret, j * arr[p].cnt);
                    }
                    else ///first only
                    {
                        arr[p] = arr[p - 1];
                        arr[p].end++;
                        arr[p].cnt++;
                        arr[p].v = 1;

                        int s = arr[p - 1].start;
                        arr[s].end++;
                        arr[s].cnt++;

                        ret = max(ret, j * arr[s].cnt);
                    }
                }
    }

    return ret;
}
