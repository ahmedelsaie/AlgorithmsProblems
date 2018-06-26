#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int check(int length);
void fn(int curr, int length);
int s = 0, x;
int array[5000], accum[20];

int main()
{
    for(int i = 1; i <= 10; i++)
        fn(0, i);

    scanf("%d", &x);
    for(int i = 0; i < s; i++)
        if(array[i] == x)
        {
            printf("%d\n", i + 1);
            break;

        }
    //printf("%d\n", s);
    return 0;
}

void fn(int curr, int length)
{
    if(curr == length)
    {
        array[s] = check(length);
        s++;
        return;
    }

    accum[curr] = 4;
    fn(curr + 1, length);
    accum[curr] = 7;
    fn(curr + 1, length);
}

int check(int length)
{
    int ans = 0;
    for(int i = 0; i < length; i++)
    {
        ans = ans * 10 + (accum[i]);
    }

    return ans;
}
