#include <stdio.h>
#include <cstring>

int fn(int sub_left, int mark_left, int p);

int n, p, subj;
int dp[75][75][75];

int main()
{
    int cases;
    int ans;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d %d", &subj, &n, &p);
        ans = fn(subj, n, p);
        printf("%d\n", ans);
    }
    return 0;
}

int fn(int sub_left, int mark_left, int p)
{
    if(sub_left < 0 || mark_left < 0)
        return 0;

    if(sub_left == 0)
    {
        if(mark_left == 0)
            return 1;
        return 0;
    }

    int &ret = dp[sub_left][mark_left][p];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i = p; i <= mark_left; i++)
        ret += fn(sub_left - 1, mark_left - i, p);

    return ret;
}
