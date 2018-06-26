#include <stdio.h>
#include <cstring>
#define inf  999999999

int fn(int t1, int t2, int t3, int t4, int t5, int t6, int left);
void mix(int i, int j, int &new_t1, int &new_t2, int &new_t3, int &new_t4, int &new_t5, int &new_t6, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6);
int min(int x, int y);

int energy[8][8];
int result[8][8];
int types;
int tubes;
int kinds[15];
int dp[12][12][12][12][12][12];
int visited [12][12][12][12][12][12];
char input[100];
int cases;

int main()
{
    int x;
    scanf("%d", &cases);
    memset(visited, -1, sizeof(visited));

    while(cases--)
    {
        scanf("%d", &types);
        for(int i = 1; i <= types; i++)
            for(int j = 1; j <= types; j++)
                scanf("%d %d", &result[i][j], &energy[i][j]);

        memset(kinds, 0, sizeof(kinds));

        scanf("%d", &tubes);
        for(int i = 0; i < tubes; i++)
        {
            scanf("%d", &x);
            kinds[x]++;
        }

        printf("%d\n", fn(kinds[1], kinds[2], kinds[3], kinds[4], kinds[5], kinds[6], tubes));

        input[0] = '1';
        if(cases)
            while(input[0] != '/')
                gets(input);
    }

    input[0] = '1';
    while(input[0] != '.')
        gets(input);

    return 0;
}

int fn(int t1, int t2, int t3, int t4, int t5, int t6, int left)
{
    if(left == 1)
        return 0;

    int &ret = dp[t1][t2][t3][t4][t5][t6];
    int &flag = visited[t1][t2][t3][t4][t5][t6];
    if(flag == cases)
        return ret;
    flag = cases;

    ret = inf;
    int temp = inf;
    int new_t1, new_t2, new_t3, new_t4, new_t5, new_t6;
    int help[8];
    help[1] = t1;
    help[2] = t2;
    help[3] = t3;
    help[4] = t4;
    help[5] = t5;
    help[6] = t6;

    for(int i = 1; i <= types; i++)
        if(help[i])
            for(int j = 1; j <= types; j++)
            {
                if(help[j] && i != j)
                {
                    mix(i, j, new_t1, new_t2, new_t3, new_t4, new_t5, new_t6, t1, t2, t3, t4, t5, t6);
                    temp = fn(new_t1, new_t2, new_t3, new_t4, new_t5, new_t6, left - 1) + energy[i][j];
                    ret = min(ret, temp);
                }
                if(i == j && help[j] > 1)
                {
                    mix(i, j, new_t1, new_t2, new_t3, new_t4, new_t5, new_t6, t1, t2, t3, t4, t5, t6);
                    temp = fn(new_t1, new_t2, new_t3, new_t4, new_t5, new_t6, left - 1) + energy[i][j];
                    ret = min(ret, temp);
                }
            }
    return ret;
}

void mix(int i, int j, int &new_t1, int &new_t2, int &new_t3, int &new_t4, int &new_t5, int &new_t6, int &t1, int &t2, int &t3, int &t4, int &t5, int &t6)
{
    new_t1 = t1;
    new_t2 = t2;
    new_t3 = t3;
    new_t4 = t4;
    new_t5 = t5;
    new_t6 = t6;

    int comp = result[i][j];

    if(i == 1)
        new_t1--;

    if(i == 2)
        new_t2--;

    if(i == 3)
        new_t3--;

    if(i == 4)
        new_t4--;

    if(i == 5)
        new_t5--;

    if(i == 6)
        new_t6--;

    if(j == 1)
        new_t1--;

    if(j == 2)
        new_t2--;

    if(j == 3)
        new_t3--;

    if(j == 4)
        new_t4--;

    if(j == 5)
        new_t5--;

    if(j == 6)
        new_t6--;

    if(comp == 1)
        new_t1++;

    if(comp == 2)
        new_t2++;

    if(comp == 3)
        new_t3++;

    if(comp == 4)
        new_t4++;

    if(comp == 5)
        new_t5++;

    if(comp == 6)
        new_t6++;
    return ;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
