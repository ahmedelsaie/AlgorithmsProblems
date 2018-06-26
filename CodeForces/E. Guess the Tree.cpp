#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long
int fn(int curr, int i, int accum, int taken);

int with_me[100], msk[100];
int left1[100], n_left, n_with = 0;
int n, f = 0, x;
int cnt[100] = {0};

int main()
{
    for(int i = 0; i < 100; i++)
        msk[i] = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &left1[i]), f += (left1[i] == 2);

    sort(left1, left1 + n);

    int i = 0;
    for(i = 0; i < n && left1[i] == 1; i++)
        cnt[1]++;

    n_left = i;
    int ans = 0;
    if(f == 0)
        ans = fn(n_left, 0, 0, 0);

    printf("%s", ans == 1 && !f ? "YES" : "NO");

    return 0;
}

int fn(int curr, int i, int accum, int taken)
{
    if(curr == n)
    {
        int tmp = 0;
        for(int i = 0; i < 100; i++)
            tmp += cnt[i];

        return tmp == 1;
    }

    if(accum == left1[curr] - 1)
    {
        if(taken > 1)
        {
            cnt[left1[curr]]++;
            return fn(curr + 1, 1, 0, 0);
        }

        return 0;
    }

    if(accum > left1[curr] - 1 || i >= 100)
        return 0;

    int ret = 0;

    int tmp = cnt[i];
    for(int j = 0; j <= tmp && !ret && accum < left1[curr]; j++)
    {
        cnt[i] -= j;
        ret = ret || fn(curr, i + 1, accum + i * j, taken + j);
        cnt[i] += j;
    }

    return ret;
}

