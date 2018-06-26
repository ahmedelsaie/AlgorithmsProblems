#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char input[100006];
int array[10];

int main()
{
    scanf("%d %s", &n, input);
    memset(array, 0, sizeof(array));

    for(int i = 0; i < n; i++)
    {
        ///tagc
        if(input[i] == 'T')
            array[0]++;
        else if(input[i] == 'A')
            array[1]++;
        else if(input[i] == 'G')
            array[2]++;
        else if(input[i] == 'C')
            array[3]++;
    }

    sort(array, array + 4);
    int x = array[3];
    int y = 1;

    for(int i = 2; i >= 0; i--)
        if(array[i] == x)
            y++;
        else
            break;

    long long mod = 1000000007;

    long long ans = 1;
    for(int i = 0; i < n; i++)
        ans = (ans % mod * y % mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
