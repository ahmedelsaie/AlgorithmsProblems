#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long
bool small[501], big[501], ans[501];
int small_n, big_n;
ll small_num, big_num;
int long_bin(ll x, bool array[]);
ll fn();
ll bin_long(int i, bool array[]);

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lld %lld", &small_num, &big_num);
        memset(small, 0, sizeof(small));
        memset(big, 0, sizeof(big));
        memset(ans, 0, sizeof(ans));

        printf("%lld\n", fn());
    }

    return 0;
}

ll fn()
{
    big_n = long_bin(big_num, big);
    small_n = big_n;
    long_bin(small_num, small);

    int i;
    for(i = big_n - 1; i >= 0; i--)
        if(small[i] == 0 && big[i] == 1)
            break;
    for(int k = 0; k < big_n; k++)
        ans[k] = small[k];

    for(int j = i - 1; j >= 0; j--)
        ans[j] = 1;

    int cnt_big = 0, cnt_ans = 0;
    for(int i = 0; i < big_n; i++)
        cnt_big += (big[i] == 1), cnt_ans += (ans[i] == 1);

    if(cnt_big > cnt_ans)
        return bin_long(big_n, big);

    return bin_long(big_n, ans);
}

int long_bin(ll x, bool array[])
{
    int ret = 0;
    if(x == 0)
        array[0] = 0, ret++;
    while(x)
    {
        array[ret] = x % 2, ret = ret + 1;
        x = x / 2;
    }
    return ret;
}

ll bin_long(int i, bool array[])
{
    ll ret = 0;
    ll pow = 1;
    for(int j = 0; j < i; j++)
        ret += array[j] * pow, pow = pow * 2;

    return ret;
}
