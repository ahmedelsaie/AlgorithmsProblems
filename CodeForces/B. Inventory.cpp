#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

int taken1[MAX], taken2[MAX], array[MAX], n, changes = 0;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for(int i = 0; i < n; i++)
    {
        if(taken2[array[i]])
            changes++;

        taken2[array[i]]++;
    }
    memset(taken1, 0, sizeof(taken1));
    int j = 1;

    for(int i = 0; i < n; i++)
    {
        if(taken1[array[i]] == 0 && array[i] <= n)
            taken1[array[i]]++;
        else
        {
            while(true)
            {
                if(taken1[j] == 0 && taken2[j] == 0)
                {
                    array[i] = j, taken1[j] = 1;
                    break;
                }
                else
                    j++;
            }
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);

    return 0;
}
