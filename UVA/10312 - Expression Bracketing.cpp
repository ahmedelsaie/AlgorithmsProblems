#include <stdio.h>
#include <cstring>

long long cnt_all(int length);
long long cnt_bin(int x);

long long dp_bin[30];
long long dp_all[30];

int main()
{
    int x;
    memset(dp_bin, -1, sizeof(dp_bin));
    memset(dp_all, -1, sizeof(dp_all));

    while(scanf("%d", &x) != EOF)
        printf("%lld\n", cnt_all(x) - cnt_bin(x) );

    return 0;
}

long long cnt_all(int length)
{
    if(length == 0)
        return 1;

    long long &ret = dp_all[length];
    if(ret != -1)
        return ret;

    ret = 0;

    for(int i = 2; i < length + 1; i++)
        ret += cnt_all(i) * cnt_all(length - i);

    ret += cnt_all(length - 1);

    return ret;
}

long long cnt_bin(int x)
{
    if(x <= 2)
        return 1;

    long long &ret = dp_bin[x];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i = 1; i < x; i++)
        ret += cnt_bin(i) * cnt_bin(x - i);

    return ret;
}
