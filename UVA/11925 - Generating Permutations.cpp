#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 305

void pre_process();
bool check();
void fn();

int places[MAX], perm[MAX], arr[90009], n, start, end1, curr;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 1; i <= n; i++)
            scanf("%d", &perm[i]);

        pre_process();
        printf("\n");
    }

    return 0;
}

void pre_process()
{
    int j = 0;
    for(int i = 1; i <= n; i++)
    {
        places[perm[i]] = i;
        if(perm[i] == i)
            j++;
        arr[i] = i;
    }
    if(j != n)
        fn();
}

void fn()
{
    int steps = 0;
    int c = 0;
    int  global_change = 0, local_change = 0;
    bool f;
    curr = 1;
    start = 2, end1 = n;

    while(!check() && steps <= 2 * n * n )
    {
        f = 0;

        if(places[curr] < places[arr[start]] || c == n - 1 || curr == perm[n])
        {
            printf("2");
            arr[end1 + 1] = curr, curr = arr[start];
            start++, end1++;
            f = 1;
            steps++;
            c = 0;
        }
        else
        {
            printf("1"), printf("2");
            arr[end1 + 1] = arr[start];
            start++, end1++;
            local_change++;
            steps += 2;
            c++;
        }
    }

    if(curr == perm[n])
        printf("2");
}

bool check()
{
    int j = 1;
    for(int i = start; i <= end1; i++)
        if(arr[i] != perm[j])
            return false;
        else
            j++;

    return true;
}
