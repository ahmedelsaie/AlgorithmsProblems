#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 10009

int check(int num, int p);
int shift(int place);
void fn();

int array[MAX], n;
int pos[MAX];

int main()
{
    fn();
    int x, cnt;

    while (scanf("%d", &x) == 1 && x > 0)
    {
        printf("%d:", x);
        cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(array[i] <= x) // && array[i] > 0)
                printf(" %d", array[i] - 1), cnt++;
            if(cnt == x)
                break;
        }

        printf("\n");
    }

    return 0;
}

void fn()
{
    n = 4;
    array[0] = 2, array[1] = 3, array[2] = 1;

    int j = 0;
    while(j < 9998)
    {
        for(int i = -1; i < n; i++)
        {
            if(check(n, i))
            {
                shift(i);
                //printf("%d\n", n);
                break;
            }
        }
        //
        j++;
    }
}

int shift(int place)
{
    for(int i = n + 1; i > place; i--)
        array[i] = array[i - 1], pos[array[i]] = i;;
    array[place + 1] = n;
    pos[n] = place + 1;
    n++;
}

int check(int num, int p)
{
    ///i am the end
    int curr = 1;

    int first = num - curr, sec = num - 2 * curr;

    while(first >= 1 && sec >= 1)
    {
        int b = pos[first];
        if(b == p)
            b = p + 1;
        if(b < p && pos[sec] < b)
            return 0;

        b = pos[first];
        if(b == p)
            b = p + 1;

        if(b > p && pos[sec] > b)
            return 0;
        curr++;
        first = num - curr, sec = num - 2 * curr;
    }

    return 1;
}
