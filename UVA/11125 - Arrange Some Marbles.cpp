#include <stdio.h>
#include <cstring>

long long fn(int n1, int n2, int n3, int n4, int last_color, int last_size, int first_size, int first_color, int left);

long long dp[9][9][9][9][5][5][5][5];
bool visited[9][9][9][9][5][5][5][5];
int target;
int n;
int num_color;
int colors[6];

int main()
{
    memset(visited, false, sizeof(visited));
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        memset(colors, 0, sizeof(colors));

        target = 0;

        scanf("%d", &num_color);
        for(int j = 1; j <= num_color; j++)
        {
            scanf("%d", &colors[j]);
            target += colors[j];
        }

        printf("%lld", fn(colors[1], colors[2], colors[3], colors[4], 5, 0, 5, 0, target));
        printf("\n");
    }
    return 0;
}

long long fn(int n1, int n2, int n3, int n4, int last_color, int last_size, int first_size, int first_color, int left)
{
    if(left < 0)
        return 0;

    if(left == 0)
    {
        if(last_color != first_color && last_size != first_size)
            return 1;
        return 0;
    }

    long long &ret = dp[n1][n2][n3][n4][last_color][last_size][first_size][first_color];
    bool &flag = visited[n1][n2][n3][n4][last_color][last_size][first_size][first_color];
    if(flag)
        return ret;
    else
        flag = true;

    ret = 0;
    int curr_color;

    curr_color = 1;
    if(last_color != curr_color)
    {
        for(int i = 1; i <= n1 && i <= 3; i++)
        {
            if(left == target)
            {
                first_color = curr_color;
                first_size = i;
            }

            if(last_size != i)
                ret += fn(n1 - i, n2, n3, n4, curr_color, i, first_size, first_color, left - i);
        }
    }

    curr_color = 2;
    if(last_color != curr_color)
    {
        for(int i = 1; i <= n2  && i <= 3; i++)
        {
            if(left == target)
            {
                first_color = curr_color;
                first_size = i;
            }
            if(last_size != i)
                ret += fn(n1, n2 - i, n3, n4, curr_color, i, first_size, first_color, left - i);
        }
    }

    curr_color = 3;
    if(last_color != curr_color)
    {
        for(int i = 1; i <= n3  && i <= 3; i++)
        {
            if(left == target)
            {
                first_color = curr_color;
                first_size = i;
            }
            if(last_size != i)
                ret += fn(n1, n2, n3 - i, n4, curr_color, i, first_size, first_color, left - i);
        }
    }

    curr_color = 4;
    if(last_color != curr_color)
    {
        for(int i = 1; i <= n4  && i <= 3; i++)
        {
            if(left == target)
            {
                first_color = curr_color;
                first_size = i;
            }
            if(last_size != i)
                ret += fn(n1, n2, n3, n4 - i, curr_color, i, first_size, first_color, left - i);
        }
    }

    return ret;
}
