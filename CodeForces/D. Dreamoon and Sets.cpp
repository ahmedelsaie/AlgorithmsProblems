#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 10000

int ans[4][MAX], k, n;

int main()
{
    scanf("%d %d", &n, &k);
    int even = 2, odd = 1, m = 1;

    for(int i = 0; i < n; i++)
    {
        ans[1][i] = odd * k, odd += 2;
        ans[2][i] = odd * k, odd += 2;
        ans[3][i] = odd * k, odd += 2;
        ans[0][i] = (odd - 3) * k, even += 2;
        m = max(m, odd - 2);
    }

    printf("%d\n", m * k);
    for(int i = 0; i < n; i++)
        printf("%d %d %d %d\n", ans[0][i], ans[1][i], ans[2][i], ans[3][i]), even -= 2;


    return 0;
}
