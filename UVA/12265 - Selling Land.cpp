#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

struct node
{
    int h, s, best;
};

int bin_search(int val, int end1);
int fn();
int check(int x);

node work[MAX];
int r, c, ans[MAX], big;
int val[2004][2004];
char input[2004][2004];
const int inf = 99999999;

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%d %d", &r, &c);
        for(int i = 1; i <= r; i++)
            scanf("%s", input[i]);

        for(int i = 1; i <= r; i++)
            for(int j = c; j >= 1; j--)
                input[i][j] = input[i][j - 1];


        for(int j = 1; j <= c; j++)
        {
            val[0][j] = 0;
            for(int i = 1; i <= r; i++)
                val[i][j] = input[i][j] == '#' ? 0 : val[i - 1][j] + 1;
        }

        fn();

        for(int i = 1; i <= big; i++)
            if(ans[i] != 0)
                printf("%d x %d\n", ans[i], i);
    }
    return 0;
}

int fn()
{
    big = 0;
    int indx;
    work[0].best = -inf;
    work[0].h = 0;
    work[0].s = 0;
    indx = 1;

    for(int i = 1; i <= r; i++)
    {
        indx = 1;
        for(int j = 1; j <= c; j++)
        {
            ///get the vale
            int tmp = val[i][j];

            if(tmp == 0)
            {
                indx = 1;
                continue;
            }

            ///the same length
            if(tmp == work[indx - 1].h)
            {
                work[indx].h = tmp;
                work[indx].best = work[indx - 1].best + 2 * (j - work[indx - 1].s);
                work[indx].s = j;
                indx++;
            }
            else if(tmp > work[indx - 1].h)
            {
                ///bigger than before
                work[indx].h = tmp;
                work[indx].s = j;
                work[indx].best = max(work[indx - 1].best + 2 * (j - work[indx - 1].s) , 2 * tmp + 2);
                indx++;
            }
            else
            {
                ///smaller than me
                int tmp2 = bin_search(tmp, indx);
                int f = 2 * tmp + 2;
                int h = 0;
                ///
                if(work[tmp2].h == tmp)
                    h = work[tmp2].best + 2 * (j - work[tmp2].s);
                else if(work[tmp2].h < tmp)// && tmp2 + 1 < indx)
                {
                    int h1 = work[tmp2].best + 2 * (j - work[tmp2].s);
                    int h2 = 0;
                    if(tmp2 + 1 < indx)
                        h2 = 2 * (j - work[tmp2 + 1].s + 1) + 2 * tmp;
                    h = h1;
                    if(h2 > h1)
                        h = h2, tmp2++;

                }
                else
                    h = 2 * (j - work[tmp2].s + 1) + 2 * tmp;

                work[tmp2 + 1].h = tmp;
                work[tmp2 + 1].s = j;
                work[tmp2 + 1].best = max(h, f);

                indx = tmp2 + 2;
            }

            ans[work[indx - 1].best]++;
            big = max(big, work[indx - 1].best);
        }

    }

}

int check(int x)
{
    int i = x - 1;
    if(work[i].h != work[x].h)
        return x;
    while(i >= 0)
    {
        if(work[i].h == work[x].h)
            i--;
        else
            break;
    }

    return i + 1;
}

int bin_search(int val, int end1)
{
    for(int i = end1 - 1; i >= 1; i--)
        if(work[i].h <= val)
            return i;
    if(end1 >= 1)
        return 1;

    return 0;
    int small = 1, big = end1 - 1, mid, ret = inf, j = end1 - 1;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(work[mid].h > val && work[mid].h < ret)
            ret = work[mid].h, j = mid;

        if(work[mid].h >= val)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return j;
}


