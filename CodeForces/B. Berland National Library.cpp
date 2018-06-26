#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 1000009

bool visited[MAX];
int n, x, curr = 0, ans = 0;
char input[100];

int main()
{
    memset(visited, 0, sizeof(visited));
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s %d", input, &x);

        if(input[0] == '+')
            curr++, visited[x] = 1;
        else
        {
            if(visited[x] == 1)
                curr--, visited[x] = 0;
            else
                ans++;
        }
//printf("cur %d ans %d\n",curr,ans);
        ans = max(ans, curr);
    }

    printf("%d\n", ans);

    return 0;
}
