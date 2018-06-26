#include <stdio.h>
#include <cstring>
struct block
{
    int type, size;
};

int fn(int start, int end, int accum);
int pre_process(int length);
int max(int x, int y);

int n;
int input[300];
int dp[205][205][205];
int visited[205][205][205];
block array[250];
int cases;

int main()
{
    int p = 1;
    scanf("%d", &cases);
    memset(visited, -1, sizeof(visited));
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &input[i]);

        n = pre_process(n);

        printf("Case %d: %d\n", p++, fn(0, n, 0));
    }

    return 0;
}

int pre_process(int length)
{
    int ret = 0;
    int before = input[0];
    int size = 0;

    for(int i = 0; i <= length; i++)
    {
        if(input[i] != before)
        {
            array[ret].type = before;
            array[ret].size = size;
            ret++;
            size = 0;
            before = input[i];
            i--;
        }
        else
            size++;
    }
    return ret;
}

int fn(int start, int end, int accum)
{
    if(start == n || end < start)
        return 0;

    int &flag = visited[start][end][accum];
    int &ret = dp[start][end][accum];

    if(flag == cases)
        return ret;

    flag = cases;
    ret = 0;
    int temp;


    temp = accum + array[start].size;
    temp = temp * temp;
    temp += fn(start + 1, end, 0);
    ret = max(ret, temp);
    int new_accum = accum + array[start].size;

    for(int i = start + 1; i <= end; i++)
    {
        if(array[i].type == array[start].type)
        {
            temp = fn(i, end, new_accum) + fn(start + 1, i - 1, 0);
            ret = max(ret, temp);
        }
    }
    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
