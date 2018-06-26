#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int cnt(int x);
int fn(int start, int end);
int check(int start, int end, int i);

char array[205];
int dp[202][202];
int visited[202][202];

int l, cases;

int main()
{
    scanf("%d", &cases);
    memset(visited, -1, sizeof(visited));
    while(cases--)
    {
        scanf("%s", array);
        l = strlen(array);
        printf("%d\n", fn(0, l));
    }

    return 0;
}

int fn(int start, int end)
{
    if(start == l || end <= start)
        return 0;

    int& ret = dp[start][end];
    int& flag = visited[start][end];
    if(flag == cases)
        return ret;

    flag = cases;

    ret = end - start;
    ret = min(ret, fn(start + 1, end) + 1); ///skip char
    for(int i = start + 1; i < end; i++)
        ret = min(ret, fn(start, i) + fn(i, end)); ///split int two parts
    ///the working algorithm
    for(int i = start + 1; i < end; i++)
    {
        int t = check(start, end, i);
        if(t != 0)
            ret = min(ret, cnt(t) + 2 + fn(start, i));
    }

    return ret;
}

int check(int start, int end, int i)
{
    int j = i;
    if((end - start) % (i - start) != 0)
        return 0;

    while(j < end)
    {
        for(int k = start; k < i; k++)
            if(array[k] != array[j])
                return 0;
            else
                j++;
    }

    return (end - start) / (i - start);
}

int cnt(int x)
{
    int ret = 0;
    while(x)
    {
        x = x / 10;
        ret++;
    }
    return ret;
}
