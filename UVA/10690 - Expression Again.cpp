#include <stdio.h>
#include <cstring>
struct ans
{
    int large, small;
};
ans dp[52][52][5150];
bool visited[52][52][5150];

int array[150];
int n, total_sum, max_accum;
int x, y;
const int inf = 99999999;
void swap();
int max(int x, int y);
int min(int x, int y);
ans fn(int i, int left, int accum);
void reset();

int main()
{
    ans result;
    while(scanf("%d %d", &x, &y) != EOF)
    {
        max_accum = 0;
        total_sum = 0;

        for(int i = 0; i < x + y; i++)
        {
            scanf("%d", &array[i]);
            total_sum += array[i];
            array[i] += 50;
            max_accum += array[i];
        }
        swap();
        reset();
        //memset(visited, false, sizeof(visited));
        result = fn(0, 0, 0);
        printf("%d %d\n", result.large, result.small);

    }
    return 0;
}

ans fn(int skip, int taken, int accum)
{
    if(taken == x)
    {
        accum = accum + (-50 * x);
        int another = total_sum - accum;
        int result = another * accum;
        ans last;
        last.large = result;
        last.small = result;
        return last;
    }

    if(taken + skip == x + y || x + y - skip - taken < x - taken)
    {
        ans result;
        result.large = -1 * inf;
        result.small = inf;
        return result;
    }

    bool &flag = visited[skip][taken][accum];
    if(flag)
        return dp[skip][taken][accum];
    flag = true;

    ans choice1, choice2, last;
    int big, small;
    choice1 = fn(skip, taken + 1, accum + array[taken + skip]);
    choice2 = fn(skip + 1, taken, accum);

    big = max(choice1.large, choice2.large);
    small = min(choice1.small, choice2.small);
    last.large = big;
    last.small = small;

    return dp[skip][taken][accum] = last;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void swap()
{
    if(x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    return;
}

void reset()
{
    for(int i = 0; i < x + y + 1 - (x); i++)
        for(int j = 0; j < x + 1; j++)
            for(int k = 0; k < max_accum; k++)
                visited[i][j][k] = false;
}
