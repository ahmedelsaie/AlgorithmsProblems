#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
double fn(int left);

int initial, cases, n, gen, pr = 1;
double p[1005], ans, tmp;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d", &n, &initial, &gen);
        for(int i = 0; i < n; i++)
            scanf("%lf", &p[i]);

        tmp = fn(gen);
        ans = pow(tmp, initial);

        printf("Case #%d: %.7lf\n", pr++, ans);
    }
    return 0;
}

double fn(int left)
{
    if(left == 0)
        return 0;

    if(left == 1)
        return p[0];

    double ret = 0;
    double tmp = fn(left - 1);
    for(int i = 0; i < n; i++)
        ret += p[i] * pow(tmp, i);
    return ret;
}
