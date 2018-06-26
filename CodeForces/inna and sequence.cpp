#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 1000009

int apply(int k);

int array[MAX], cut[MAX], n, n_cut;
pair<int, int> a[MAX], w[MAX];
const int inf = 999999999;

int main()
{
    scanf("%d %d", &n, &n_cut);

    for(int i = 0; i < n_cut; i++)
        scanf("%d", &cut[i]), cut[i]--;

    cut[n_cut] = inf, n_cut++;

    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    int i = 0, accum = 0, start, end, k = 0;

    while(i < n)
    {
        if(array[i] == -1)
        {
            if(accum)
                a[k].first = start, a[k].second = end, k++;


            k = apply(k);


            accum = 0;
        }
        else
        {
            if(i == 0 || array[i - 1] == -1)
                start = i, end = i + 1;
            else
                end++;
            accum++;
        }

        i++;
    }

    if(accum)
        a[k].first = start, a[k].second = end, k++;

    if(k == 0)
        printf("Poor stack!");
    else
    {
        for(int i = 0; i < k; i++)
            for(int j = a[i].first; j < a[i].second; j++)
                printf("%d", array[j]);
    }

    printf("\n");

    return 0;
}

int apply(int k)
{
    for(int i = 0; i < k; i++)
        w[i] = a[i];

    int b = 0, j = 0, accum = 0, last = w[0].first;
    int c = 0;

    while(b < k)
    {
        int diff = cut[j] - accum;
        if(last + diff < w[b].second)
        {
            if(diff)
                a[c].first = last, a[c].second = last + diff, c++;
            last += diff + 1 ;
            accum += diff + 1, j++;
        }
        else
        {
            if(last != w[b].second)
                a[c].first = last, a[c].second = w[b].second, c++;
            accum += w[b].second - last;

            last = w[b + 1].first;
            b++;
        }

    }

    return c;
}

