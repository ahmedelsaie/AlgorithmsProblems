#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void fn();

int main_t, main_r, main_h;
int tr[21][21];
int rh[21][21];
int ht[21][21];

int ans[5];
int max1 = 2147483647;
int got = 0;

int main()
{
    int counter, counter2;

    while(scanf("%d", &main_t) != EOF)
    {

        scanf("%d %d", &main_r, &main_h);

        for(counter = 0; counter < main_t; counter++)
        {
            for(counter2 = 0; counter2 <= main_r; counter2++)
                scanf("%d", &tr[counter][counter2]);
        }


        for(counter = 0; counter < main_r; counter++)
        {
            for(counter2 = 0; counter2 <= main_h; counter2++)
                scanf("%d", &rh[counter][counter2]);
        }


        for(counter = 0; counter < main_h; counter++)
        {
            for(counter2 = 0; counter2 <= main_t; counter2++)
                scanf("%d", &ht[counter][counter2]);
        }

        got = 0;
        max1 = 2147483647;
        fn();

        if(got != 0)
            printf("%d %d %d :%d", ans[0], ans[1], ans[2], max1);
        else
            printf("Don't get married!");
        printf("\n");

    }

    return 0;
}

void fn()
{
    int h, t, r;
    int price;

    for(t = 0; t < main_t; t++)
    {
        for(r = 1; r <= main_r; r++)
        {
            if(tr[t][r] == 0)
            {
                for(h = 1; h <= main_h; h++)
                {
                    if(rh[r - 1][h] == 0 && ht[h - 1][t + 1] == 0)
                    {
                        got++;
                        price = tr[t][0] + rh[r - 1][0] + ht[h - 1][0];
                        if(price < max1)
                        {
                            max1 = price;
                            ans[0] = t;
                            ans[1] = r - 1;
                            ans[2] = h - 1;
                        }
                    }
                }
            }
        }
    }
}
