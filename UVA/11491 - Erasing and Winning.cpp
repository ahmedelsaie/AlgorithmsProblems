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
#define MAX 100009

void fn();
int check(int i);

char input[MAX];
int array[10][MAX], indx[MAX], last[MAX], ans[MAX], l, m;

int main()
{
    // freopen("c.out", "w", stdout);
    while(true)
    {
        scanf("%d %d", &l, &m);
        if(l + m == 0)
            break;

        scanf("%s", input);
        memset(indx, 0, sizeof(indx));
        memset(last, 0, sizeof(last));

        for(int i = 0; i < l; i++)
        {
            int tmp = input[i] - '0';
            array[tmp][last[tmp]] = i;
            last[tmp]++;
        }

        fn();

        for(int i = 0; i < l - m; i++)
            printf("%d", ans[i]);
        printf("\n");
    }


    return 0;
}

void fn()
{
    int g = 0, j = 0, i = 0;

    while(g < m && i < l)
    {
        for(int num = 9; num >= 0; num--)
        {
            if(indx[num] < last[num])
            {
                int tmp = array[num][indx[num]];
                if(tmp - i <= m - g)
                {
                    g += tmp - i;
                    ans[j++] = num;
                    i = tmp + 1;
                    indx[num]++;
                    check(i-1);
                    break;
                }
            }
        }
      // printf("%d\n", i);
    }

    if(i < l)
        for(int k = i; k < l; k++)
            ans[j++] = input[k] - '0';

}

int check(int i)
{
    for(int num = 0; num <= 9; num++)
    {
        int tmp = array[num][indx[num]];
        if(tmp < i)
        {
            while(array[num][indx[num]] <= i && indx[num] < last[num])
                indx[num]++;
        }
    }

}
