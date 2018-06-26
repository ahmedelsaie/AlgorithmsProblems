#include <stdio.h>
#include <cstring>
int check(int a, int b, int c);
int min(int x, int y);
int fn(int item, int a, int b);

int dp[33][641][641];
int visited[33][641][641];
int n, all;
int array[40];
int const inf = 9999999;
int cases;

int main()
{
    int ans, p = 1;
    scanf("%d", &cases);
    memset(visited, -1, sizeof(visited));

    while(cases--)
    {
        scanf("%d", &n);
        all = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
            all += array[i];
        }
        // reset();
        ans = fn(0, 0, 0);
        printf("Case %d: %d\n", p, ans);
        p++;
    }
    return 0;
}

int fn(int item, int a, int b)
{
    if(item == n)
        return check(a, b, all - (a + b));

    int &flag = visited[item][a][b];
    int &ret = dp[item][a][b];
    if(flag == cases)
        return ret;
    flag = cases;

    ret = inf;
    int temp;
    temp = check(a, b, all - (a + b));
    ret = min(temp, ret);

    temp = fn(item + 1, a + array[item], b);
    ret = min(temp, ret);

    temp = fn(item + 1, a, b + array[item]);
    ret = min(temp, ret);

    temp = fn(item + 1, a, b);
    ret = min(temp, ret);

    return ret;
}

int check(int a, int b, int c)
{
    int temp[3];
    temp[0] = a;
    temp[1] = b;
    temp[2] = c;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(temp[j] > temp[j + 1])
            {
                int swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
    return temp[2] - temp[0];
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
