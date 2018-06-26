#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int fn();

char last[4];
int b1, b2, b3;
int c1, c2, c3;
int g1, g2, g3;

int main()
{
    while(scanf("%d", &b1) != EOF)
    {
        scanf("%d %d %d %d %d %d %d %d", &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3);

        int ans=fn();

        printf("%s %d\n", last, ans);
    }

    return 0;
}

int fn()
{
    int ret = 2147483647;
    int ans = b2 + b3 + c1 + c3 + g1 + g2;

    if (ans < ret)
    {
        ret = ans;
        last[0] = 'B';
        last[1] = 'C';
        last[2] = 'G';
    }

    ans = b2 + b3 + g1 + g3 + c1 + c2;
    if (ans < ret)
    {
        ret = ans;
        last[0] = 'B';
        last[1] = 'G';
        last[2] = 'C';
    }

    ans = c2 + c3 + b1 + b3 + g1 + g2;
    if (ans < ret)
    {
        ret = ans;
        last[0] = 'C';
        last[1] = 'B';
        last[2] = 'G';
    }

    ans = c2 + c3 + g1 + g3 + b1 + b2;
    if (ans < ret)
    {
        ret = ans;
        last[0] = 'C';
        last[1] = 'G';
        last[2] = 'B';
    }

    ans = g2 + g3 + b1 + b3 + c1 + c2;
    if (ans < ret)
    {
        ret = ans;
        last[0] = 'G';
        last[1] = 'B';
        last[2] = 'C';
    }

    ans = g2 + g3 + c1 + c3 + b1 + b2;
    if (ans < ret)
    {
        ret = ans;
        last[0] = 'G';
        last[1] = 'C';
        last[2] = 'B';
    }

    last[3] = '\0';

    return ret;
}



