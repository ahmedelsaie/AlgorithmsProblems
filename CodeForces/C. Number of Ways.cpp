#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll  long long
int n, h;
ll accum[500005];
int sec[500005];
int bin(int i);
ll get(int first, int last);
int s_n, f_n;
ll fn();

int main()
{
    scanf("%d", &n);
    accum[0] = 0;
    ll sum = 0;
    ll x;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &x);
        sum += x;
        accum[i] = sum;
    }

    // if(n==99999)
    //    printf("%lld\n",sum);
    //else

    printf("%lld\n", fn());
    return 0;
}

ll get(int first, int last)
{
    return accum[last] - accum[first - 1];
}

ll fn()
{
    //printf("%lld a\n", accum[n]);
    ll thirdy = accum[n] / 3;
    //printf("third %lld\n", thirdy);
    if(accum[n] != thirdy * 3)
        return 0;
    ll ret = 0;

    int j = 0;

    j = 0;
    for(int i = n; i >= 1; i--)
    {
        if(get(i, n) == thirdy)
            sec[j] = i, j++;
    }
    s_n = j;


    for(int i = 1; i <= n; i++)
    {
        if(get(1, i) == thirdy)
            ret += bin(i);
    }
    //  f_n = j;
    // printf("%d\n",j);


//printf("%d\n",j);
    // for(int i = 0; i < f_n; i++)
    //,printf("loop i %d %d\n",first[i],bin(first[i]));

    // for(int i = 0; i < f_n; i++)
    //   printf("/%d ", first[i]);

    // printf("\n");

    // for(int i = 0; i < s_n; i++)
    //      printf("//%d ", sec[i]);
    // printf("\n");


    //printf("%d\n", bin(1));
    return ret;
}

int bin(int i)
{
    //printf("i am in binary search %d\n",i);
    i += 2;
    if(i > n)
        return 0;

    int big = s_n, small = 0;
    int prev = -1;
    while(big >= small)
    {
        // printf("%d %d %d\n",small,middle,big);
        int middle = big - small;
        middle = middle / 2;
        middle = middle + small;
//printf("%d %d %d\n",small,middle,big);
        if(sec[middle] < i)
            big = middle - 1;
        else
            small = middle + 1 , prev = middle;

    }
    return prev + 1;
}
