#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define MAX 105

int cnt(int x);
int fn(int start, int end);
int check(int start, int end, int i);
void trace(int start, int end);

char array[MAX];
int dp[MAX][MAX];
int visited[MAX][MAX];

int l, cases = 0;

int main()
{
    memset(visited, -1, sizeof(visited));

    while(gets(array))
    {
        //scanf("%s", array);
        l = strlen(array);
        fn(0, l), trace(0, l);
        printf("\n");
        cases++;
    }

    return 0;
}

void trace(int start, int end)
{
    if(start == l || end <= start)
        return ;

    int& ret = dp[start][end];
    if(ret == dp[start + 1][end] + 1) ///skip char
    {
        printf("%c", array[start]), trace(start + 1, end);
        return ;
    }

    for(int i = start + 1; i < end; i++) ///split int two parts
        if(ret == dp[start][i] + dp[i][end])
        {
            trace(start, i), trace(i, end);
            return;
        }

    ///the working algorithm
    for(int i = start + 1; i < end; i++)
    {
        int t = check(start, end, i);
        if(t != 0 && ret == cnt(t) + 2 + dp[start][i])
        {
            printf("%d(", t);
            trace(start, i);
            printf(")");
            return;
        }
    }

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
