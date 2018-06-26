#include <bits/stdc++.h>
using namespace std;
#define MAX 505
#define ll long long

struct node
{
    int  add[MAX], all, last;
};

void fn(int e, int indx, int p);
bool comp(node x, node y);

int n = 500, arr[MAX], k, n_ans[MAX], tc, cases = 1;

node s[MAX * 100], ans[MAX][20];
int m;

int main()
{
    memset(n_ans, 0, sizeof(n_ans));
    k = 1;
    s[0].last = 0;
    s[0].all = 0;
    fn(0, 0, 0);

    for(int i = 0; i <= n; i++)
        m = i, sort(ans[i], ans[i] + n_ans[i], comp);

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);

        printf("Case #%d:", cases++);

        if(n == 1)
            printf(" 0");

        for(int i = 0; i < n_ans[n]; i++)
        {
            printf(" ");
            for(int j = 0; j < n; j++)
                printf("%d", ans[n][i].add[j]);
        }

        if(n_ans == 0)
            printf(" Impossible");

        printf("\n");
    }

    return 0;
}

bool comp(node x, node y)
{
    for(int i = 0; i <= m; i++)
    {
        if(x.add[i] != y.add[i])
            return x.add[i] < y.add[i];
    }

    return 0;
}

void fn(int e, int indx, int p)
{
    int c = k;
    s[k++] = s[p];

    if(arr[indx - 1] > 0)
    {
        int j = 0;
        int& ret = n_ans[indx];
        for(int i = indx - 1; i >= 0; i--)
            ans[indx][ret].add[j++] = arr[i];
        ret++;
    }

    if(s[c].last >= n)
        return;

    int start = indx == 0 ? 1 : 0;


    for(int num = start; num <= 9; num++)
    {
        arr[indx] = num;

        s[c] = s[p];
        s[c].add[e] = 0;
        int tmp = 0;

        int j = s[c].last;
        for(int i = 0; i <= e; i++)
            tmp += (arr[i] * arr[j--] + s[c].add[i]) % 10;

        tmp += s[c].all;

        s[c].all = tmp / 10;
        tmp = tmp % 10;
        if(tmp == num)
        {
            int j = s[c].last;
            for(int i = 0; i <= e; i++)
                s[c].add[i] = (arr[i] * arr[j--] + s[c].add[i]) / 10;

            s[c].last++;
            fn(e + 1, indx + 1, c);
        }
    }
}

