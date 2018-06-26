#include <stdio.h>
#include <stdlib.h>

int fn(int left, int right);
void reset();

int n[60];
int dp[150][150];
int l;
int no;

int main()
{
    int counter;

    scanf("%d", &l);
    while(l != 0)
    {
        scanf("%d", &no);
        n[0] = 0;
        for(counter = 1; counter <= no; counter++)
            scanf("%d", &n[counter]);
        n[no + 1] = l;
        reset();
        printf("The minimum cutting is %d.\n", fn(0, no + 1));
        scanf("%d", &l);
    }

    return 0;
}

void reset()
{
    int counter, counter2;
    for(counter = 0; counter < 150; counter++)
        for(counter2 = 0; counter2 < 150; counter2++)
            dp[counter][counter2] = -1;

}

int fn(int left, int right)
{
    int counter, max, cost;

    if(dp[left][right] != -1)
        return dp[left][right];

    if(left + 1 == right)
        return 0;

    max = 2147483647;
    for(counter = left + 1; counter < right; counter++)
    {
        cost = fn(left, counter) + fn(counter, right) + n[right] - n[left];
        if(cost < max)
            max = cost;
    }

    dp[left][right] = max;
    return max;
}



