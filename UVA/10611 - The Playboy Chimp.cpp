#include <stdio.h>

void fn(int x);

int n, q;
int height[50009];
int query[25009];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &height[i]);

    scanf("%d", &q);
    for(int i = 0; i < q; i++)
        scanf("%d", &query[i]);

    for(int i = 0; i < q; i++)
    {
        fn(query[i]);
        if(i < q)
            printf("\n");
    }

    return 0;
}

void fn(int x)
{
    int big, small, mid, ans;

    big = n - 1;
    small = 0;
    ans = 0;

    while(big >= small)
    {
        mid = big - small;
        mid = small + .5 * mid;

        if(height[mid] < x)
        {
            ans = height[mid];
            small = mid + 1;
        }
        else
            big = mid - 1;
    }

    if(ans > 0)
        printf("%d ", ans);
    else
        printf("X ");



    big = n - 1;
    small = 0;
    ans = 0;

    while(big >= small)
    {
        mid = big - small;
        mid = small + .5 * mid;

        if(height[mid] <= x)
            small = mid + 1;

        else
        {
            big = mid - 1;
            ans = height[mid];
        }
    }

    if(ans > 0)
        printf("%d", ans);
    else
        printf("X");

    return ;
}


