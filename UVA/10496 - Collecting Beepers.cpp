#include <stdio.h>
#include <stdlib.h>

int fn(int mask[], int value, int current, int i);
int abs(int x);

int n;
int x[15];
int y[15];
int start_x;
int start_y;
int cas;

int main()
{
    int counter, counter2;
    int mask[20];

    scanf("%d", &cas);

    for(counter2 = 0; counter2 < cas; counter2++)
    {
        scanf("%d", &start_x);
        scanf("%d", &start_y);

        scanf("%d", &start_x);
        scanf("%d", &start_y);
        scanf("%d", &n);

        for(counter = 0; counter < n; counter++)
            scanf("%d %d", &x[counter], &y[counter]);

        for(counter = 0; counter < n; counter++)
            mask[counter] = 1;

        x[counter] = start_x;
        y[counter] = start_y;

        printf("The shortest path has length %d\n", fn(mask, 0, n, 0));
    }


    return 0;
}

int fn(int mask[], int value, int current, int i)
{
    int mask2[20];
    int counter;
    for(counter = 0; counter < n; counter++)
        mask2[counter] = mask[counter];
    int xe, ye;

    if(i == n)
    {
        xe = abs(x[n] - x[current]);
        ye = abs(y[n] - y[current]);


        return value + ye + xe;
    }

    int min = 2147483647;
    int r;

    for(counter = 0; counter < n; counter++)
    {
        if(mask2[counter] == 1)
        {
            mask2[counter] = 0;

            xe = abs(x[current] - x[counter]);
            ye = abs(y[current] - y[counter]);
            r = fn(mask2, value + xe + ye, counter, i + 1);
            mask2[counter] = 1;
            if(r < min)
                min = r;
        }
    }
    return min;

}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
