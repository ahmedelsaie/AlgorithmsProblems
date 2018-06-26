#include <stdio.h>
#include <cstring>
struct level
{
    int value;
    int levels;
};

level dp[300][300];
int visited [300][300];
int array[300];
int n, k;
const int inf = 9999999;
level min(int value, int lev, level ret);
level fn(int start , int end);
int cases;

int main()
{
    level ans;
    int  p = 1;;
    scanf("%d", &cases);
    memset(visited, -1, sizeof(visited));
    while(cases--)
    {
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; i++)
            array[i] = (i + 1) + k;



        ans = fn(0, n - 1);
        printf("Case %d: %d\n", p, ans.value);
        p++;
    }
    return 0;
}

level fn(int start , int end)
{
    if(end < start)
    {
        level x;
        x.value = 0;
        x.levels = 0;
        return x;
    }

    if(start == end)
    {
        level x;
        x.value = 0;
        x.levels = 1;
        return x;
    }

    int& flag = visited[start][end];
    if(flag==cases)
        return dp[start][end];
    flag = cases;

    level sour, bitter, ret;
    ret.value = inf;
    int value, lev;

    for(int i = start; i <= end; i++)
    {
        sour = fn(start, i - 1);
        bitter = fn(i + 1, end);
        int j = i;
        i++;
        value = array[j] + array[j] * bitter.levels + array[j] * sour.levels;
        value += bitter.value + sour.value;
        lev = 1 + bitter.levels + sour.levels;
        ret = min(value, lev, ret);
        i--;
    }

    return dp[start][end] = ret;
}

level min(int value, int lev, level ret)
{
    if(ret.value < value)
        return ret;
    ret.levels = lev;
    ret.value = value;
    return ret;
}

