#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009
#define ll long long

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int cntbit(int mask);

int v[MAX];

int main()
{
    int n;
    scanf("%d", &n);

    memset(v, -1, sizeof(v));

    for(int i = n; i >= 0; i--)
    {
        if(v[i] == -1)
        {
            int tmp = cntbit(i);
            int x = 0, j = 0;

            while(tmp)
            {
                if(getbit(i, j))
                    x = setbit(x, j, 0), tmp--;
                else
                    x = setbit(x, j, 1);
                j++;
            }

            v[x] = i, v[i] = x;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++)
        ans = ans + (ll)(i ^ v[i]);

    printf("%lld\n", ans);

    for(int i = 0; i <= n; i++)
        printf("%d ", v[i]);

    return 0;
}

///Bit Operations
int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
    }
    return ret;
}
