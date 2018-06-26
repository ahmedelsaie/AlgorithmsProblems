#include <stdio.h>

bool check(int k);
void fn();

int n;
int array[1000000];
int ans;

int main()
{
    array[0] = 0;
    int cases;
    scanf("%d", &cases);

    for(int c = 0; c < cases; c++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &array[i]);

        fn();

        printf("Case %d: %d\n", c + 1, ans);
    }

    return 0;
}

void fn()
{
    int big = 0, small = 0;
    int mid;

    big = array[n];

    while(big > small)
    {
        mid = big - small;
        mid = small + .5 * mid;

        if(check(mid))
        {
            big = mid;
            ans = mid;
        }
        else
            small = mid + 1;
    }

    if(check(small))
        ans = small;

    if(check(big))
        ans = big;

    return ;
}

bool check(int k)
{
    int i = 0;
    while(i < n)
    {
        int diff = array[i + 1] - array[i];

        if(diff > k)
            return false;

        if(diff == k)
            k--;

        i++;
    }
    return true;
}
