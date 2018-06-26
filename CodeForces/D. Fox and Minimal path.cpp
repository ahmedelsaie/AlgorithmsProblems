#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 2005
ll fn(ll x);
void build(ll twos, ll length);

ll fn2(ll x);
void build2(ll twos, ll length);
int graph[MAX][MAX], last = 2;
ll n, track;

int main()
{
    scanf("%lld", &n);
    memset(graph, 0, sizeof(graph));
    if(n == 1)
    {
        printf("2\nNY\nYN\n");
        return 0;
    }
    if(n == 2)
    {
        printf("4\nNNYY\nNNYY\nYYNN\nYYNN\n");
        return 0;
    }

    track = n;

    ll big = fn(n) + 1;
    build(big - 1, big);

    while(n >= 1)
    {
        ll tmp = fn(n);
        build(tmp, big);
    }

    if(n == 1)
        build(0, 1);

    for(int i = 1; i <= last; i++)
        for(int j = 1; j <= last; j++)
        {
            if(graph[i][j])
                graph[j][i] = 1;

            if(graph[j][i])
                graph[i][j] = 1;
        }

    if(last > 1000)
    {
        last = 2;
        memset(graph, 0, sizeof(graph));
        n = track;

        ll big = fn2(n) + 1;
        build2(big - 1, big);


        while(n >= 1)
        {
            ll tmp = fn2(n);
            build2(tmp, big);
        }

        if(n == 1)
            build2(0, 1);

        for(int i = 1; i <= last; i++)
            for(int j = 1; j <= last; j++)
            {
                if(graph[i][j])
                    graph[j][i] = 1;

                if(graph[j][i])
                    graph[i][j] = 1;
            }
    }


    printf("%d\n", last);
    for(int i = 1; i <= last; i++)
    {
        for(int j = 1; j <= last; j++)
            printf("%s", graph[i][j] == 1 ? "Y" : "N");
        printf("\n");
    }

    return 0;
}

void build(ll twos, ll length)
{
    ll curr = 0;
    int first = 1, sec, third;
    bool f = 0;

    if(twos)
    {
        graph[1][last + 1] = graph[1][last + 2] = graph[1][last + 3] = 1;
        first = last + 1, sec = last + 2, third = last + 3, last += 3;
        twos--, curr++, f = 1;
    }

    while(twos)
    {
        graph[first][last + 1] = graph[first][last + 2] = graph[first][last + 3] = 1;
        graph[sec][last + 1] = graph[sec][last + 2] = graph[sec][last + 3] = 1;
        graph[third][last + 1] = graph[third][last + 2] = graph[third][last + 3] = 1;

        first = last + 1, sec = last + 2, third = last + 3;
        last += 3;
        twos--, curr++;
        f = 1;
    }

    if(curr < length - 1)
    {
        if(f == 0)
            graph[1][last + 1] = 1, last++;// printf("dfdfdf\n");
        else
            graph[last][last + 1] = graph[last - 1][last + 1] = graph[last - 2][last + 1] = 1, last++;

        f = 0;
        curr++;

        while(curr < length - 1)
        {
            graph[last][last + 1] = 1, last++;
            curr++;
        }
    }

    if(f == 1)
        graph[last][2] = graph[last - 1][2] = graph[last - 2][2] = 1;
    else
        graph[last][2] = 1;

    return ;
}

ll fn(ll x)
{
    if(x <= 1)
    {
        n--;
        return 0;
    }

    ll ret = 0;
    ll y = x;
    ll prev = 1;

    while(true)
    {
        if(3 * prev <= x)
            prev *= 3, ret++;
        else
            break;
    }

    n -= prev;
    return ret;
}

void build2(ll twos, ll length)
{
    ll curr = 0;
    int first = 1, sec;
    bool f = 0;

    if(twos)
    {
        graph[1][last + 1] = graph[1][last + 2] = 1;
        first = last + 1, sec = last + 2, last += 2;
        twos--, curr++, f = 1;
    }

    while(twos)
    {
        graph[first][last + 1] = graph[first][last + 2] = 1;
        graph[sec][last + 1] = graph[sec][last + 2] = 1;
        first = last + 1, sec = last + 2;
        last += 2;
        twos--, curr++;
        f = 1;
    }

    if(curr < length - 1)
    {
        if(f == 0)
            graph[1][last + 1] = 1, last++;// printf("dfdfdf\n");
        else
            graph[last][last + 1] = graph[last - 1][last + 1] = 1, last++;

        f = 0;
        curr++;

        while(curr < length - 1)
        {
            graph[last][last + 1] = 1, last++;
            curr++;
        }
    }

    if(f == 1)
        graph[last][2] = graph[last - 1][2] = 1;
    else
        graph[last][2] = 1;

    return ;
}

ll fn2(ll x)
{
    if(x <= 1)
    {
        n--;
        return 0;
    }

    ll ret = 0;
    ll y = x;
    ll prev = 1;

    while(true)
    {
        if(2 * prev <= x)
            prev *= 2, ret++;
        else
            break;
    }

    n -= prev;
    return ret;
}
