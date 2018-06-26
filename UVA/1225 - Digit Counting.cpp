#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void fn(int y);

int checks[10];

int main()
{
    int cases, x;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &x);

        for(int j = 0; j < 10; j++)
            checks[j] = 0;

        for(int j = 1; j <= x; j++)
            fn(j);

        for(int j = 0; j < 10; j++)
        {
            printf("%d", checks[j]);
            if(j < 9)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}

void fn(int y)
{
    int temp;
    while(y != 0)
    {
        temp = y % 10;
        checks[temp]++;
        y = y / 10;
    }
    return ;
}


