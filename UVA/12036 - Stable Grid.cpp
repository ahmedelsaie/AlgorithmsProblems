#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 105

int array[MAX], n, cases, x, t = 1;

int main()
{
    bool ans;
    scanf("%d", &cases);

    while(cases--)
    {
        memset(array, 0, sizeof(array));
        ans = 1;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &x);
                array[x]++;
                if(array[x] > n)
                    ans = 0;
            }

        printf("Case %d: %s\n", t++, ans == 1 ? "yes" : "no");
    }


    return 0;
}
