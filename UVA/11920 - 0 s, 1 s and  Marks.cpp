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

int fn();

char arr[MAX], arr2[MAX];
int total[MAX], l, tc, cases = 1;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", arr2);
        l = strlen(arr2);
        printf("Case %d: %d\n", cases++ , fn());
    }

    return 0;
}

int fn()
{
    int ret = 1;
    int i = 0, j = 0, accum = 0;
    char prev = arr2[i];
    while(i < l)
    {
        if(prev == arr2[i])
            accum++;
        else
        {
            if(prev != '?')
                ret = max(ret, accum);
            arr[j] = prev;
            total[j++] = accum;
            accum = 1, prev = arr2[i];
        }

        i++;
    }

    if(prev != '?')
        ret = max(ret, accum);
    arr[j] = prev;
    total[j++] = accum;

    int start = 0;
    if(arr[0] == '?')
        start = 1;

    int end = j;
    if(arr[j - 1] == '?')
        end -= 1;

    for(int i = start; i < end; i++)
    {
        if(arr[i] == '?')
        {
            if(arr[i - 1] == arr[i + 1])
            {
                if(total[i] % 2) ///odd
                    ret = max(ret, total[i - 1]), ret = max(ret, total[i + 1]);
                else
                    ret = max(ret, 2);

            }
            else
            {
                ///work here
                if(total[i] == 1)
                {
                    if(total[i - 1] <= total[i + 1])
                        ret = max(ret, total[i - 1] + 1);
                    else
                        ret = max(ret, total[i + 1] + 1), total[i + 1]++;
                }
                else if(total[i] % 2 == 0)
                    ret = max(ret, total[i - 1]), ret = max(ret, total[i + 1]);
                else
                    ret = max(ret, 2);


            }
        }
        else
            ret = max(ret, total[i]);
    }

    if(j == 1 && arr[0] == '?')
        ret = 1;

    return ret;


}
