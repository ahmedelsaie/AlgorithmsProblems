#include <stdio.h>

long long box(int i);
long long fn();

int array[105][105];
int n_boxes;
int mod;

int main()
{
    int cases, x;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d", &mod, &n_boxes);
        for(int i = 0; i < n_boxes; i++)
        {
            scanf("%d", &array[i][0]);
            x = array[i][0];
            for(int j = 1; j <= x; j++)
                scanf("%d", &array[i][j]);
        }
        printf("%lld\n", fn());

    }
    return 0;
}

long long fn()
{
    long long ret = 0;
    for(int i = 0; i < n_boxes; i++)
        ret = (ret + box(i)) % mod;

    return ret;
}

long long box(int i)
{
    int x = array[i][0];
    long long ret = 1;

    for(int j = 1; j <= x; j++)
        ret = ret * array[i][j] % mod;
    return ret;
}
