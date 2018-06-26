#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 1000

ll array[MAX][MAX];
int taken[MAX], n_city, n_can;

int main()
{
    memset(taken, 0, sizeof(taken));
    scanf("%d %d", &n_can, &n_city);

    for(int i = 0; i < n_city; i++)
        for(int j = 0; j < n_can; j++)
            scanf("%lld", &array[i][j]);

    for(int i = 0; i < n_city; i++)
    {
        ll ret = 0, val = array[i][0];
        for(int j = 0; j < n_can; j++)
        {
            if(array[i][j] > val)
                val = array[i][j], ret = j;
        }
        taken[ret]++;
    }

    ll ret = 0, val = taken[0];
    for(int j = 0; j < n_can; j++)
    {
        if(taken[j] > val)
            ret = j, val = taken[j];
    }

    printf("%lld\n", ret+1);
    return 0;
}

