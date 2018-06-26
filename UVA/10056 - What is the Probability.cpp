#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

double fn();

double prob;
int target, n, cases;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        scanf("%lf", &prob);
        scanf("%d", &target);
        printf("%.4lf\n", fn());
    }
    return 0;
}

double fn()
{
    if(prob == 0.0)
        return 0;
    double ret;
    // for(int i = 0; i < target; i++)
    //   c1 = c1 * (1 - prob);

    //for(int i = target; i < n; i++)
    //    c2 = c2 * (1 - prob);

    //  ret = 1 / (1 - c1 * c2);
    ret = prob * pow(1.0 - prob, target - 1) / (1 - pow(1.0 - prob, n));
    //   printf("%.4lf\n", p ? pow(1.0 - p, k - 1) * p / (1 - pow(1.0 - p, n)) : 0);

//pow(1.0 - p, k - 1) * p / (1 - pow(1.0 - p, n)) : 0);
    return ret;
}

