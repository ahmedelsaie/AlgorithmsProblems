#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
void fn(double accum, int level, int indx, int msk);

double p[20][20];
double ans[20];
int x;
char county[20][105];

int main()
{
    for(int i = 0; i < 16; i++)
        scanf("%s", county[i]);

    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++)
            scanf("%d", &x) , p[i][j] = (double)x / 100;


    memset(ans, 0, sizeof(ans));
    fn(1, 0, 0, (1 << 16) - 1);
    for(int i = 0; i < 16; i++)
        printf("%-10s p=%.2lf%\n", county[i], ans[i] * 100);

    return 0;
}

void fn(double accum, int level, int indx, int msk)
{
    if(level == 4)
    {
        int i;
        for(i = 0; i < 16; i++)
            if(getbit(msk, i))
                break;
        ans[i] += accum;
        return;
    }

    if(indx >= 16)
    {
        int i;
        for(i = 0; i < 16; i++)
            if(getbit(msk, i))
                break;
        return fn(accum, level + 1, i, msk);
    }

    int i, j;
    for(i = indx + 1; i < 16; i++)
        if(getbit(msk, i))
            break;

    for(j = i + 1; j < 16; j++)
        if(getbit(msk, j))
            break;

    fn(accum * p[indx][i], level, j, setbit(msk, i, 0));
    fn(accum * p[i][indx], level, j, setbit(msk, indx, 0));

    return ;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
