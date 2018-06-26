#include <stdio.h>
#include <cstring>

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int fn(int mask, int last, int current_seen, bool flag, int left, int b);
bool check(int mask, int last);
int cntbit(int mask);

int dp[8193][13][13][13][2];
int n, r, b, all_ones;

int main()
{
    memset(dp, -1, sizeof(dp));
    int cases, ans;

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d", &n, &r, &b);
        if(r > b)
        {
            int swap = b;
            b = r;
            r = swap;
        }
        all_ones = (1 << n) - 1;

        ans = fn((1 << n) - 1, 0, r, false, n, b);
        printf("%d\n", ans);
    }
    return 0;
}

int fn(int mask, int last, int current_seen, bool flag, int left, int b)
{
    if(flag)
    {
        if(left < current_seen)
            return 0;
        if(getbit(mask, n - 1))
            return 0;

        if(!check(mask, last) && current_seen > 1)
            return 0;
    }

    if(!flag)
    {
        if(!getbit(mask, n - 1) && current_seen > 0)
            return 0;

        if(left < b + current_seen - 1)
            return 0;

        if(!check(mask, last) && current_seen > 1)
            return 0;
    }

    if(left == 0)
    {
        if(flag && current_seen == 0)
            return 1;
        return 0;
    }

    int &ret = dp[mask][last][current_seen][b][flag];
    if(ret != -1)
        return ret;
    ret = 0;

    if(!flag && current_seen == 0)
        return ret = fn(mask, 0, b - 1, true, left, b);

    for(int i = 0; i < n; i++)
    {
        if(getbit(mask, i))
        {
            if(i >= last)
                ret += fn(setbit(mask, i, 0), i, current_seen - 1, flag, left - 1, b);
            else
                ret += fn(setbit(mask, i, 0), last, current_seen, flag, left - 1, b);
        }
    }

    return ret;
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

bool check(int mask, int last)
{
    int filter = (1 << last + 1) - 1;
    filter = ~filter;
    filter = filter & all_ones;

    int new_mask = filter & mask;
    if(new_mask == 0)
        return false;
    return true;
    return cntbit(new_mask);
}
