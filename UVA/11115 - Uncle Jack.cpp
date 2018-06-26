#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll unsigned long long

ll fn(int cd, int neph);
void pre_process();

ll comb[30][30], dp[30][30];
bool visited[30][30];

int main()
{
    pre_process();
    int x, y;
    while(true)
    {
        scanf("%d %d", &x, &y);
        if(x + y == 0)
            break;
        printf("%llu\n", fn(y, x));
    }

    return 0;
}

ll fn(int cd, int neph)
{
    if(cd == 0)
        return 1;

    if(neph == 0)
        return 0;

    ll& ret = dp[cd][neph];
    bool& flag = visited[cd][neph];
    if(flag)
        return ret;
    ret = 0, flag = 1;
    ret += fn(cd, neph - 1);
    for(int i = 1; i <= cd; i++)
        ret += comb[cd][i] * fn(cd - i, neph - 1);

    return ret;
}

void pre_process()
{
    memset(visited, 0, sizeof(visited));
    for(int left = 0; left < 30; left++)
        for(int p = 0; p <= left; p++)
        {
            comb[left][p] = 0;
            if(p <= left)
            {
                if(left == 0)
                {
                    if(p == 0)
                        comb[left][p] = 1;
                }
                else
                {
                    comb[left][p] += comb[left - 1][p];
                    if(p > 0)
                        comb[left][p] += comb[left - 1][p - 1];
                }
            }
        }
}
