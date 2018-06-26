#include <stdio.h>
#include <cstring>

int badness(int a, int b);
int min(int x, int y);
int fn(int taken, int skip, int i);
void reset();

const int inf = 99999999;
int guests;
int chops;
int dp[1010][5005];
int visited[1010][5005];
int arr[5005];
int cases;

int main()
{
    memset(visited, -1, sizeof(visited));
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d", &guests, &chops);
        guests += 8;

        for(int i = 0; i < chops; i++)
            scanf("%d", &arr[i]);

        //reset();
        printf("%d\n", fn(0, 0, chops - 1));
    }
    return 0;
}

int fn(int taken, int skip, int i)
{
    if(taken > skip)
        return inf;

    if(taken == guests)
        return 0;

    if(i < 0)
        return inf;

    int &ret = dp[taken][skip];
    int &flag = visited[taken][skip];

    if(flag == cases)
        return ret;
    flag = cases;

    ret = inf;
    int temp = inf;

    if(i - 1 >= 0)
        temp = badness(arr[i], arr[i - 1]) + fn(taken + 1, skip, i - 2);
    ret = min(ret, temp);

    temp = fn(taken, skip + 1, i - 1);
    ret = min(ret, temp);

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int badness(int a, int b)
{
    int ret = a - b;
    ret = ret * ret;
    return ret;
}

void reset()
{
    for(int i = 0; i < guests + 1; i++)
        for(int j = 0; j < chops + 1; j++)
            dp[i][j] = -1;
}
