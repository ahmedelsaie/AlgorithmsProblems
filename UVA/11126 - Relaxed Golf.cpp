#include <stdio.h>
#include <cstring>

int abs(int x);
int fn(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int top_discard, int top_draw, int left);
bool can(int x, int y);

int dp[6][6][6][6][6][6][6][13][17];
int array[8][8];
int draw[20];

int main()
{
    int cases, ans, p = 1;
    scanf("%d", &cases);

    while(cases--)
    {
        for(int i = 1; i <= 5; i++)
            scanf("%d %d %d %d %d %d %d", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5], &array[i][6]);

        for(int i = 1; i <= 17; i++)
            scanf("%d", &draw[i]);

        for(int i = 1; i <= 17; i++)
            draw[i]--;

        for(int i = 1; i <= 5; i++)
        {
            array[i][0]--;
            array[i][1]--;
            array[i][2]--;
            array[i][3]--;
            array[i][4]--;
            array[i][5]--;
            array[i][6]--;
        }

        memset(dp, -1, sizeof(dp));
        ans = fn(5, 5, 5, 5, 5, 5, 5, draw[17], 16, 51);
        printf("Case #%d: ", p);

        if(ans)
            printf("Yes");
        else
            printf("No");

        printf("\n");
        p++;
    }
    return 0;
}

int fn(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int top_discard, int top_draw, int left)
{
    if(left == 0)
        return true;

    int &ret = dp[c1][c2][c3][c4][c5][c6][c7][top_discard][top_draw];
    if(ret != -1)
        return ret;
    ret = 0;


    if(c1 && can(top_discard, array[c1][0]) == 1 && !ret)
        ret = ret | fn(c1 - 1, c2, c3, c4, c5, c6, c7, array[c1][0], top_draw, left - 1);

    if(c2 && can(top_discard, array[c2][1]) == 1 && !ret)
        ret = ret | fn(c1, c2 - 1, c3, c4, c5, c6, c7, array[c2][1], top_draw, left - 1);

    if(c3 && can(top_discard, array[c3][2]) == 1 && !ret)
        ret = ret | fn(c1, c2, c3 - 1, c4, c5, c6, c7, array[c3][2], top_draw, left - 1);

    if(c4 && can(top_discard, array[c4][3]) == 1 && !ret)
        ret = ret | fn(c1, c2, c3, c4 - 1, c5, c6, c7, array[c4][3], top_draw, left - 1);

    if(c5 && can(top_discard, array[c5][4]) == 1 && !ret)
        ret = ret | fn(c1, c2, c3, c4, c5 - 1, c6, c7, array[c5][4], top_draw, left - 1);

    if(c6 && can(top_discard, array[c6][5]) == 1 && !ret)
        ret = ret | fn(c1, c2, c3, c4, c5, c6 - 1, c7, array[c6][5], top_draw, left - 1);

    if(c7 && can(top_discard, array[c7][6]) == 1 && !ret)
        ret = ret | fn(c1, c2, c3, c4, c5, c6, c7 - 1, array[c7][6], top_draw, left - 1);

    if(top_draw && !ret)
        ret = ret | fn(c1, c2, c3, c4, c5, c6, c7, draw[top_draw], top_draw - 1, left - 1);

    return ret;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

bool can(int x, int y)
{
    return abs(x - y) == 12 || abs(x - y) == 1;
}
