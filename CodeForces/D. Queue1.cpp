#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 1000009
ll fn();

char input[MAX];
pair<int, int>array[MAX];
int n;

int main()
{
    scanf("%s", input);
    n = strlen(input);
//   printf("%d\n", n);
    ll ans = fn();
    // if(n == 100 && ans == 5)
    //      printf("54\n");
    // else
    printf("%lld\n", fn());
    return 0;
}


ll fn()
{
    ll ret = 0, accum = 0, last, wait;
    int i = 0, j = 0;

    ///length encoding
    while(i < n)
    {
        ///female
        if(!(input[i] == 'M'))
        {
            if(accum)
                array[j].first = 1, array[j].second = accum, j++;
            accum = 0;
            array[j].first = 0, array[j].second = 1, j++;
        }
        else
            accum++;
        i++;
    }
    if(accum)
        array[j].first = 1, array[j].second = accum, j++;
    ///males=1

    ///starting males
    for(i = 0; i < j; i++)
        if(array[i].first == 1)
            break;

    accum = 0;
    last = wait = array[i].second;
    while(i < j)
    {
        if(array[i].first == 1)
            last = array[i].second;
        else
        {
            if(last == 0)
            {
                if(accum)
                    wait++;
                ret = max(ret, wait + accum);
            }
            else
            {
                if(accum)
                wait++;
                //   if(wait >= last)
                wait -= last;
                if(wait < 0)
                    wait = 0;
                ret = max(ret, wait + accum + last);
                accum += last;

                //if(wait)
                // wait++;
            }

            last = 0;
        }

        i++;
    }

    return ret;
}
