#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long
#define mod 1000000000

ll fn(int start, int end);

char array[305];
ll dp[305][305];
int visited[305][305];

int l, cases = 0;

int main()
{
    memset(visited, -1, sizeof(visited));
    while(scanf("%s", array) != EOF)
    {
        l = strlen(array);
        printf("%lld\n", fn(0, l));
        cases++;
    }

    return 0;
}

ll fn(int start, int end)
{

    if(start + 1 == l || start + 1 == end)
        return 1;
    if(array[start] != array[end - 1])
        return 0;

    ll& ret = dp[start][end];
    int& flag = visited[start][end];
    if(flag == cases)
        return ret;

    flag = cases;
    ret = 0;

    for(int i = start + 2; i < end; i++)
        if(array[start] == array[i])
            ret = (ret + fn(start + 1, i) * fn(i, end)) % mod;

    return ret;
}
