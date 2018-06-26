#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 20009

int array[MAX], n, v[MAX];

int main()
{
    memset(v, 0, sizeof(0));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);


    int g = 0;
    int ret=0;
    int flag = 0;
    int i=0;
    while(g < n)
    {
             if(i == n)
            flag = !flag, i--,ret++;

        if(i < 0)
            flag = !flag, i++,ret++;

        if(v[i]==0 && array[i]<=g)
            v[i]=1,g++;

        if(flag == 0)
            i++;
        else
            i--;

    }

  //  if(i==0 || i==n-1)
    //    ret--;

    printf("%d\n",ret);
    return 0;
}
