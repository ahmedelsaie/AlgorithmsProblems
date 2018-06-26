#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void fn(int n, int h);

int arr[200];
int main_n;
int main_h;

int hs[200];
int ns[200];

int main()
{
    int noofcases, counter;

    while(scanf("%d", &noofcases) != EOF)
    {
        for(counter = 0; counter < noofcases; counter++)
            scanf("%d %d", &ns[counter], &hs[counter]);

        for(counter = 0; counter < noofcases; counter++)
        {
            main_n = ns[counter];
            main_h = hs[counter];
            fn(0, 0);
            if(counter < noofcases - 1)
                printf("\n");
        }
    }

    return 0;
}

void fn(int n, int h)
{
    int counter;
    if(n == main_n)
    {
        if(h == main_h)
        {
            for(counter = 0; counter < n; counter++)
                printf("%d", arr[counter]);
            printf("\n");
        }
        return;
    }

    arr[n] = 0;
    fn(n + 1, h);

    if(h < main_h)
    {
        arr[n] = 1;
        fn(n + 1, h + 1);
    }

    return;
}

