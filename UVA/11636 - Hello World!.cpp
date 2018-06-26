#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main()
{
    double ans;
    int x, cases = 1;

    while(true)
    {
        scanf("%d", &x);
        if(x < 0)
            break;

        ans = log2((double)x);
        ans = ceil(ans);
        printf("Case %d: %d\n", cases++, (int)ans);
    }
    return 0;
}
