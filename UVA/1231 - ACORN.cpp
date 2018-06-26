#include <stdio.h>
#include <cstring>

///FUCNTIONS
int max(int x,int y);
int fn();
int fix(int i);

///ARRAYS
int graph[2005][2005];
int graph_visited[2005][2005];
int dp[2005][2005];
int best[2005];

///VARIABLES
int trees, height, fall, cases;

int main()
{
    int x, y;
    memset(graph_visited, -1, sizeof(graph_visited));
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d %d", &trees, &height, &fall);

        for(int i = 1; i <= trees; i++)
        {
            scanf("%d", &x);
            for(int j = 0; j < x; j++)
            {
                scanf("%d", &y);

                if(graph_visited[i][fix(y)] == cases)
                    graph[i][fix(y)]++;
                else
                {
                    graph[i][fix(y)] = 1;
                    graph_visited[i][fix(y)] = cases;
                }
            }
        }
        printf("%d\n", fn());
    }
    return 0;
}

int fn()
{
    int g, ret = 0;
    memset(best, 0 , sizeof(best));

    for(int i = 1; i <= trees ; i++)
        dp[height + 1][i] = 0;

    for(int i = height; i >=1 ; i--)///HEIGHT
    {
        for(int j= 1; j <= trees; j++) ///TREES
        {
            g = 0;
            if(graph_visited[j][i] == cases)
                g = graph[j][i];

            dp[i][j] = dp[i+1][j] + g;

            if(i + fall <= height)
                dp[i][j] = max(best[i + fall] + g, dp[i][j]);

            best[i] = max(best[i], dp[i][j]);
        }
    }

    for(int i = 1; i <= trees; i++)
        ret=max(ret, dp[1][i]);

    return ret;
}

int fix(int i)
{
    i = height - i;
    return i + 1;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
