#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100009

ll fn(int curr);
int bin_search(int start, int desired, int array[]);
ll gn();

const int inf = 999999999;
const ll MOD = 21092013;
int accum_u[MAX], accum_r[MAX], accum_l[MAX], depth[MAX], n, m, tc, cases = 1;
char arr1[MAX], arr2[MAX];
ll dp[MAX];

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s %s", arr1, arr2);
        n = strlen(arr2), m = strlen(arr1);
        printf("Case %d: %lld\n", cases++, gn());
    }

    return 0;
}

ll gn()
{
    ll ret = 0;
    accum_u[0] = accum_l[0] = accum_r[0] = 0;
    memset(dp, -1, sizeof(dp));
    n++;
    for(int i = 1; i < n; i++)
    {
        accum_u[i] = accum_u[i - 1] + (arr2[i - 1] == 'U');
        accum_r[i] = accum_r[i - 1] + (arr2[i - 1] == 'R');
        accum_l[i] = accum_l[i - 1] + (arr2[i - 1] == 'L');
        //if(arr2[i-1]=='L')
        //  accum_l[i]++;
        //+ arr2[i - 1] == 'L';
    }

    //for(int i = 0; i < n; i++)
    //   printf("%d ", accum_l[i]);
    int curr_depth = 0;
    memset(depth, 0, sizeof(depth));

    for(int i = 0; i < m; i++)
    {
        if(arr1[i] == 'R') depth[curr_depth++] = 1;
        if(arr1[i] == 'L') depth[curr_depth++] = 2;
        if(arr1[i] == 'U') curr_depth--;

        if(curr_depth < 0)curr_depth = 0;
    }

    // printf("dpth %d\n", curr_depth);
    //printf("%d %d\n", depth[0], depth[1]);
    for(int i = 0; i < curr_depth; i++)
    {
        int indx = bin_search(0, curr_depth - i, accum_u);

        //printf("== %d %d %d\n", i, tmp, fn(1));

        if(depth[i] == 1 && indx != inf)
        {
            int tmp = bin_search(indx, 1, accum_l);
            if(tmp != inf)
                ret += fn(tmp + 1) + 1, ret %= MOD;
            ret++, ret %= MOD;
        }

        if(depth[i] == 2 && indx != inf)
        {
            int tmp = bin_search(indx, 1, accum_r);
            if(tmp != inf)
                ret += fn(tmp + 1) + 1, ret %= MOD;
            ret++, ret %= MOD;
        }

        //if(depth[i] == 0)
        //ret += fn(1), ret %= MOD, printf("jjj %lld\n", fn(1));

    }
    //printf("kkll %lld\n", fn(1)+1);
    ret += fn(1) + 1, ret %= MOD; // printf("ttttt %d\n", fn(1));
    return ret;
}

ll fn(int curr)
{
    ll& ret = dp[curr];
    if(ret != -1)return ret;
    ret = 0;

    int tmp = bin_search(curr, 1, accum_r); ///get_right
    // printf(" === %d %d\n", curr, tmp);
    if(tmp != inf)
        ret += fn(tmp + 1) + 1, ret %= MOD;

    tmp = bin_search(curr, 1, accum_l); ///get_left

    if(tmp != inf)
        ret += fn(tmp + 1) + 1, ret %= MOD;

    //ret++, ret %= MOD;
    // printf("================== %d %lld\n",curr,ret);
    return ret ;
}

int bin_search(int start, int desired, int array[])
{
    int small = start, big = n - 1, mid, ret = inf;

    while(big >= small)
    {
        mid = (small + big) / 2;
        int tmp = array[mid] - array[start - 1];
        //   printf("start %d mid %d ene %d tmp %d\n", small, mid, big, tmp);
        if(tmp >= desired)
            big = mid - 1, ret = min(ret, mid);
        else
            small = mid + 1;
    }

    return ret;
}
