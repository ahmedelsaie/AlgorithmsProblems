#include <stdio.h>
#include <cstring>
struct vec
{
    int array[130];
    int s;
};

char obj[130][11];
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int fn(int mask1, int mask2, vec main);
void update(vec &first, vec &sec, vec &main, int b);
int max(int x, int y);
int min(int x, int y);

const int inf = 9999999;
int dp[(1 << 11) + 1][(1 << 11) + 1];
int m, n;

int main()
{
    vec temp;
    while(true)
    {
        scanf("%d %d", &m, &n);

        if(n == 0 && m == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%s", obj[i]);

        for(int i = 0; i < n; i++)
            temp.array[i] = i;
        temp.s = n;

        memset(dp, -1, sizeof(dp));
        printf("%d\n", fn(0, 0, temp));
    }
    return 0;
}

int fn(int mask1, int mask2, vec main)
{
    if(main.s == 1)
        return 0;

    int &ret = dp[mask1][mask2];
    if(ret != -1)
        return ret;
    ret = inf;

    vec first, sec;
    int new_mask1, new_mask2, temp;

    for(int i = 0; i < m; i++)
    {
        if(!getbit(mask1, i))
        {
            update(first, sec, main, i);
            new_mask1 = setbit(mask1, i, 1);
            new_mask2 = setbit(mask2, i, 1);

            temp = max(fn(new_mask1, new_mask2, first), fn(new_mask1, mask2, sec)) + 1;
            ret = min(ret, temp);
        }
    }

    return ret;
}

void update(vec &first, vec &sec, vec &main, int b)
{
    int j, h;
    first.s = 0;
    sec.s = 0;

    for(int i = 0; i < main.s; i++)
    {
        j = main.array[i];
        if(obj[j][b] == '1')
        {
            h = first.s;
            first.array[h] = j;
            first.s++;
        }
        else
        {
            h = sec.s;
            sec.array[h] = j;
            sec.s++;
        }
    }
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
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
