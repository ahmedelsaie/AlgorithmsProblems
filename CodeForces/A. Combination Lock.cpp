#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int best[1005], nw[1005], n;
char input[1005];
int main()
{
    scanf("%d", &n);
    scanf("%s", input);
    for(int i = 0; i < n; i++)
        nw[i] = input[i] - '0';
    scanf("%s", input);
    for(int i = 0; i < n; i++)
        best[i] = input[i] - '0';


    int ret = 0;

    for(int i = 0; i < n; i++)
    {
        int tmp1 = abs(nw[i] - best[i]);
        int tmp2 = 10 - tmp1;

        ret += min(tmp1, tmp2);

    }
    printf("%d\n", ret);

    return 0;
}
