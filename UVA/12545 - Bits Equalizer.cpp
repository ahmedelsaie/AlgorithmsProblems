#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define MAX 50009

int fn();

char arr1[MAX], arr2[MAX];
int n, tc,cases=1;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s %s", arr1, arr2);
        n = strlen(arr1);
        printf("Case %d: %d\n",cases++, fn());
    }

    return 0;
}

int fn()
{
    int q0 = 0, q1 = 0, ones = 0, zeros = 0;
    int ret = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr1[i] == '?')
            q0 += arr2[i] == '0', q1 += arr2[i] == '1';

        if(arr1[i] == '1' && arr2[i] == '0')
            ones++;

        if(arr1[i] == '0' && arr2[i] == '1')
            zeros++;
    }

    if(zeros >= ones)
    {
        //  printf("fsf %d\n",zeros);
        //ret += ones;
        ret += zeros;// - ones;
        ret += q0 + q1;
    }
    else
    {
        ones -= zeros;
        ret+=zeros;
        if(q1 >= ones)
        {
            ret += 2 * ones;
            q1 -= ones;
            return ret + q1 + q0;
        }
        else
            return -1;
    }
    return ret;
}

