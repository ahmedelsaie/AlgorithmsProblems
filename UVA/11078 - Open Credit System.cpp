#include <stdio.h>

int max(int x, int y);
int min(int x, int y);
int fn();

int n;
int score[200000];

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            scanf("%d", &score[j]);
        int ans = fn();
        printf("%d\n", ans);

    }
    return 0;
}

int fn()
{
    int min_score = score[n - 1];
    int max_diff = -9999999;
    for(int i = n - 2; i >= 0; i--)
    {
        max_diff = max(max_diff, score[i] - min_score);
        min_score = min(min_score, score[i]);
    }
    return max_diff;
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
