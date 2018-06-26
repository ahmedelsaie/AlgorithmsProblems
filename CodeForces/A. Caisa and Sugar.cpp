#include <stdio.h>
int max(int x, int y);

int s, n;
int dollars[105];
int cents[105];
int fn();

int main()
{
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &dollars[i], &cents[i]);
    printf("%d\n", fn());
    return 0;
}


int fn()
{
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        if(cents[i] == 0 && dollars[i] <= s)
            ans = max(ans, 0);
        else if(dollars[i] + 1 <= s)
            ans = max(ans, 100 - cents[i]);
    }
    return ans;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
