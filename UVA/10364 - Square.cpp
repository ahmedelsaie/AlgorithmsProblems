#include <stdio.h>

int getbit(int mask, int bit);
bool fn(int mask, int num, int length);
void pre_process();

int mask_length[(1 << 20) + 2];
int array[25];
bool dp[(1 << 20) + 1];
bool visited[(1 << 20) + 1];

int n;
int total = 0;

int main()
{
    int cases;
    scanf("%d", &cases);

    while(cases--)
    {
        total = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
            total += array[i];
        }

        if(total % 4 != 0)
            printf("no");
        else
        {
            pre_process();
            if(fn(0, 0, total / 4))
                printf("yes");
            else
                printf("no");
        }

        printf("\n");
    }

    return 0;
}

bool fn(int mask, int num, int length)
{
    if(num == 4)
    {
        if(mask == (1 << n) - 1)
            return 1;
        return 0;
    }

    bool &flag = visited[mask];
    bool &ret = dp[mask];
    if(flag)
        return ret;
    flag = true;
    ret = false;

    int submask_upper = ~(mask);
    int m = (1 << n) - 1;
    submask_upper = ( m & submask_upper);

    for(int j = submask_upper; j > 0; j = (j - 1)&submask_upper)
    {
        if(mask_length[j] == length)
            ret = ret | fn(j | mask, num + 1, length);
        if(ret == 1)
            break;
    }
    return ret;
}

void pre_process()
{
    int ans;
    for(int i = 0; i < (1 << n); i++)
    {
        visited[i] = false;

        ans = 0;
        for(int j = 0; j < n; j++)
            if(getbit(i, j))
                ans += array[j];
        mask_length[i] = ans;
    }
    dp[(1 << n)] = -1;
    return ;
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
