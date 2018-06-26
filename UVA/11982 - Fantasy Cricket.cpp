#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#define ll long long

ll fn(int i, int places, int with);

char arr1[MAX], arr2[MAX];
ll dp[MAX][MAX];
ll const MOD = 1000000007;
int n, tc, cases = 1;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%s", arr2);
        n = strlen(arr2);
        int j = 0;

        for(int i = 0; i < n; i++)
            if(arr2[i] != 'E')
                arr1[j++] = arr2[i];
        n = j;
        printf("Case %d: %lld\n", cases++, fn(0, 0, 0));
    }

    return 0;
}

ll fn(int i, int places, int with)
{
    if(i == n)return with == 0;

    ll& ret = dp[i][places];
    if(ret != -1)return ret;
    ret = 0;

    if(arr1[i] == 'D')
    {
        ret += places * fn(i + 1, places, with) % MOD, ret %= MOD; ///put in before & leave it empty
        ret += with * places * fn(i + 1, places - 1, with - 1) % MOD, ret %= MOD; ///put in before & put in some
    }
    else
    {
        ret += fn(i + 1, places + 1, with + 1), ret %= MOD; ///take it and leave empty
        ret += with * fn(i + 1, places, with) % MOD, ret %= MOD; ///take it and put from me
    }

    return ret;
}

