#include <stdio.h>

int fn();
int abs(int x);
int min(int x, int y);

char road[2000005];
int n;
const int inf = 99999999;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        scanf("%s", road);
        printf("%d\n", fn());
    }
    return 0;
}

int fn()
{
    int lastd = inf;
    int lastr = inf;
    int ans = inf;
    int temp;
    for(int i = 0; i < n; i++)
    {
        if(road[i] == 'Z')
            return 0;
        if(road[i] == 'D')
        {
            lastd = i;
            temp = abs(lastd - lastr);
            ans = min(ans, temp);
        }

        if(road[i] == 'R')
        {
            lastr = i;
            temp = abs(lastd - lastr);
            ans = min(ans, temp);
        }
    }
    return ans;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
