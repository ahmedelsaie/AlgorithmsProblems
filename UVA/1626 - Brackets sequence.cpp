#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int fn(int start, int end);
void trace(int start, int end);
int table();

char array[105];
int dp[105][105];
int visited[105][105];

int cases, l, ans;
const int inf = 99999999;

int main()
{
    memset(visited, -1, sizeof(visited));
    scanf("%d", &cases);
    getchar();

    while(cases--)
    {
        gets(array);
        gets(array);
        l = strlen(array);

        if(l == 0)
        {
            printf("\n");
            if(cases)
                printf("\n");
            continue;
        }
        ans = table();
        trace(0, l);

        printf("\n");
        if(cases)
            printf("\n");
    }

    return 0;
}

int table()
{
    int end;
    for(int start = l; start >= 0; start--)
        for(int len = 0; len <= l; len++)
        {
            end = start + len;
            if(end > l)
                continue;

            int& ret = dp[start][end];
            ret = inf;

            if(start >= end || start == l)
            {
                ret = 0;
                continue;
            }

            if(array[start] == ')' || array[start] == ']') ///jump one step && put ( or [
                ret = min(ret, dp[start + 1][end] + 1);
            else
            {
                ret = min(ret, dp[start + 1][end] + 1);///jump one step && put ) or ]


                for(int i = start + 1; i < end; i++)
                {
                    ///meet parts
                    if((array[start] == '(' && array[i] == ')') || (array[start] == '[' && array[i] == ']'))
                        ret = min(ret, dp[start + 1][i] + dp[i + 1][end]);

                    ///add at the beginning
                    if(array[i] == ']' || array[i] == ')')
                        ret = min(ret, dp[start][i] + dp[i + 1][end] + 1);

                    ///add at the end
                    if(array[start] == '[' || array[start] == '(')
                        ret = min(ret, dp[start + 1][i + 1] + dp[i + 1][end] + 1);
                }
            }
        }

    return dp[0][l];
}

void trace(int start, int end)
{
    if(start >= end || start == l)
        return ;

    int ret = inf;
    int mode, k;

    if(array[start] == ')' || array[start] == ']') ///jump one step && put ( or [
    {
        if(array[start] == ')')
            printf("(");
        else
            printf("[");
        printf("%c", array[start]);
        trace(start + 1, end);
        return ;
    }
    else
    {
        if(dp[start + 1] [end] + 1 <= ret) ///jump one step && put ) or ]
            mode = 0, ret = dp[start + 1] [end] + 1;

        for(int i = start + 1; i < end; i++)
        {
            ///meet parts
            if((array[start] == '(' && array[i] == ')') || (array[start] == '[' && array[i] == ']'))
            {
                if(dp[start + 1][i] + dp[i + 1][end] <= ret)
                    ret = dp[start + 1][i] + dp[i + 1][end], mode = 1, k = i;
            }

            ///add at the beginning
            if(array[i] == ']' || array[i] == ')')
            {
                if(dp[start][i] + dp[i + 1][end] + 1 <= ret)
                    ret = dp[start][i] + dp[i + 1][end] + 1, mode = 2, k = i;
            }

            ///add at the end
            {
                if(dp[start + 1][i + 1] + dp[i + 1][end] + 1 <= ret)
                    ret = dp[start + 1][i + 1] + dp[i + 1][end] + 1, mode = 3, k = i;
            }
        }
    }

    switch(mode)
    {
    ///jump one step && put ) or ]
    case 0:
        printf("%c", array[start]);
        if(array[start] == '(')
            printf("%c", ')');
        else
            printf("%c", ']');

        trace(start + 1, end);
        break;

    ///meet parts
    case 1:
        printf("%c", array[start]);
        trace(start + 1, k );
        printf("%c", array[k]);
        trace(k + 1, end);
        break;

    ///add at the beginning
    case 2:
        if(array[k] == ']')
            printf("%c", '[');
        else
            printf("%c", '(');

        trace(start, k);
        printf("%c", array[k]);
        trace(k + 1, end);
        break;

    ///add at the end
    case 3:
        printf("%c", array[start]);
        trace(start + 1, k + 1);
        if(array[start] == '(')
            printf("%c", ')');
        else
            printf("%c", ']');

        trace(k + 1, end);
        break;
    }
}

/*
int fn(int start, int end)
{
    int& ret = dp[start][end];
    int& flag = visited[start][end];
    if(flag == cases)
        return ret;
    ret = inf;
    flag = cases;

    if(start >= end || start == l)
    {
        ret = 0;
        return ret;

    }

    //  if(start == end)
    //    return 1;





    if(array[start] == ')' || array[start] == ']') ///jump one step && put ( or [
        ret = min(ret, fn(start + 1, end) + 1);
    else
    {
        ret = min(ret, fn(start + 1, end) + 1);///jump one step && put ) or ]

        for(int i = start + 1; i < end; i++)
        {
            ///meet parts
            if((array[start] == '(' && array[i] == ')') || (array[start] == '[' && array[i] == ']'))
                ret = min(ret, fn(start + 1, i) + fn(i + 1, end));

            ///add at the beginning
            if(array[i] == ']' || array[i] == ')')
                ret = min(ret, fn(start, i) + fn(i + 1, end) + 1);

            ///add at the end
            if(array[start] == '[' || array[start] == '(')
                ret = min(ret, fn(start + 1, i + 1) + fn(i + 1, end) + 1);
        }
    }
    return ret;
}
*/

