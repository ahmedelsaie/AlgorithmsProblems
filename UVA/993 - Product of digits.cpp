#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

void fn(int left);
int parse();

int num[100], cases, x, ans;

int main()
{
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        ans = -1, memset(num, 0, sizeof(num));
        scanf("%d", &x);
        if(x == 1 || x == 0)
            printf("%d", x);
        else
            fn(x), printf("%d", ans);

        printf("\n");
    }
    return 0;
}

void fn(int left)
{
    if(left == 1)
    {
        int tmp = parse();
        if(ans == -1 || tmp < ans)
            ans = tmp;
        return ;
    }

    for(int j = 2; j < 10; j++)
        if(left % j == 0)
            num[j]++, fn(left / j), num[j]--;
    return ;
}

int parse()
{
    int ret = 0;
    for(int j = 1; j < 10; j++)
        for(int k = 0; k < num[j]; k++)
            ret = ret * 10 + j;
    return ret;
}
