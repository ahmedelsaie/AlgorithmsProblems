#include <stdio.h>
#include <cstring>
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int min(int x, int y);
int abs(int x);
int check(int mask, int x);
int fn(int mask, int place);
void print(int mask, int place);
void pre_process();

int m = 53;
int r = 16;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int dp[65539][105];
int array[105], msks[70], ok[65539][70], indx[65539];
int n;
const int inf = 999999999;

int main()
{
    pre_process();

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    memset(dp, -1, sizeof(dp));
    fn(0, 0);
    print(0, 0);
    printf("\n");
    return 0;
}

int fn(int mask, int place)
{
    int& ret = dp[mask][place];
    if(ret != -1)
        return ret;

    if(place == n)
        return ret = 0;

    ret = inf;

    int k = indx[mask];

    ret = min(ret, fn(mask, place + 1) + abs(1 - array[place]));

    for(int i = 0; i < k; i++)
    {
        int new_mask = mask | msks[ok[mask][i]];
        ret = min(ret, fn(new_mask, place + 1) + abs(array[place] - ok[mask][i]));
    }

    return ret;
}

void print(int mask, int place)
{
    if(place == n)
        return ;

    int ret = inf;
    int element = 1, new_mask2 = mask;
    ret = min(ret, fn(mask, place + 1) + abs(1 - array[place]));

    int k = indx[mask];

    for(int i = 0; i < k; i++)
    {
        int new_mask = mask | msks[ok[mask][i]];
        ret = min(ret, dp[new_mask][place + 1] + abs(array[place] - ok[mask][i]));
        if(ret == dp[new_mask][place + 1] + abs(array[place] - ok[mask][i]))
        {
            element = ok[mask][i];
            new_mask2 = new_mask;
        }
    }

    printf("%d", element);

    if(place < n - 1)
        printf(" ");
    print(new_mask2, place + 1);
}

void pre_process()
{
    memset(indx, 0, sizeof(indx));

    int tmp_msk = 0;
    for(int i = 2; i <= m; i++)
    {
        tmp_msk = 0;
        for(int j = 0; j < r; j++)
            if(i % primes[j] == 0)
                tmp_msk = setbit(tmp_msk, j, 1);

        msks[i] = tmp_msk;
    }

    for(int i = 0; i < (1 << r); i++)
    {
        for(int j = 2; j <= m; j++)
        {
            if((i & msks[j]) == 0)
                ok[i][indx[i]] = j, indx[i]++;
        }
    }


    /*  if(i==0 && j==2)
          printf("hi %d\n",i & msks[j]);
      if(i & msks[j] == 0 && i == 0)
          printf("%d\n", i);

    printf("%d %d\n", indx[0], msks[2]);
    */
}

int check(int mask, int x)
{
    int new_mask = mask;
    for(int i = 0; i < 15; i++)
    {
        if(x % primes[i] == 0)
        {
            if(getbit(mask, i))
                return -1;
            else
                new_mask = setbit(new_mask, i, 1);
        }
    }

    return new_mask;
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

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
