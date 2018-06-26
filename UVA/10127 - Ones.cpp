#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 10000
ll fn();

ll visited[MAX];
int x;

int main()
{
    memset(visited, -1, sizeof(visited));

    while(scanf("%d", &x) != EOF)
    {
        if(visited[x] == -1)
            visited[x] = fn();

        printf("%lld\n", visited[x]);
    }


    return 0;
}

ll fn()
{
    ll ret = 1, d = 1%x;

    while(true)
    {
        if(d== 0)
            return ret;
        ret++;
        d = (d * 10 + 1) % x;
    }

    return ret;
}
