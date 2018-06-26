#include <stdio.h>
int heights[100009];
int n;
int fn();
int abs(int x);

int main()
{
    heights[0] = 0;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &heights[i]);

    printf("%d\n", fn());
    return 0;
}

int fn()
{
    int energy = 0, money = 0, prev;
    for(int i = 0; i < n; i++)
    {
        energy += heights[i] - heights[i + 1];
        if(energy < 0)
        {
            money += abs(energy);
            energy = 0;
        }
    }

    return money;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
