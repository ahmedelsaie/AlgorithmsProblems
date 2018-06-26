#include <stdio.h>

bool check(int i, int j);
int abs(int x);
int min(int x, int y);
void fn(int i);
int optimal_dist();
int max(int x, int y);

int array[92][8];
int accum[9];
int input[9];
int sol;

int main()
{
    sol = 0;
    fn(0);
    int cases = 1;
    while(scanf("%d", &input[0]) != EOF)
    {
        for(int i = 1; i < 8; i++)
            scanf("%d", &input[i]);

        int ans = optimal_dist();
        printf("Case %d: %d\n", cases, ans);
        cases++;
    }
    return 0;
}

int optimal_dist()
{
    int temp;
    int ret = 10;
    for(int i = 0; i < 92; i++)
    {
        temp = 0;

        for(int j = 0; j < 8; j++)
            if(input[j] != array[i][j])
                temp++;

        ret = min(ret, temp);
    }
    return ret;
}

void fn(int i)
{
    if(i == 8)
    {
        for(int i = 0; i < 8; i++)
            array[sol][i] = accum[i];
        sol++;
        return ;
    }

    for(int j = 1; j <= 8; j++)
    {
        if(check(i, j))
        {
            accum[i] = j;
            fn(i + 1);
        }
    }
}

bool check(int i, int j)
{
    for(int k = 0; k < i; k++)
        if(accum[k] == j || abs(accum[k] - j) == abs(k - i))
            return false;
    return true;
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

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
