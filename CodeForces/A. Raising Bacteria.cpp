#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 50009
int fn(int x);

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",fn(x));
    return 0;
}

int fn(int x)
{
    if(x == 0)
        return 0;
    int k = (int)floor(log((double)x) / log(2.0));
    int left = x - (1 << k);

    return 1 + fn(left);
}


