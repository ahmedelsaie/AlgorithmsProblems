#include <stdio.h>
#include <cstring>
char mains[10005];
char target[105];
int target_1, main_l;

const int max1 = 100;

struct bigint
{
    int array1[max1];
    int l = max1;
};

bigint dp[10005][105];
void initialize(bigint &target, int x);
void print(bigint &x);
bigint add(bigint &x, bigint &y);
bigint fn();

int main()
{
    int cases;
    bigint result;

    scanf("%d", &cases);
    for(int counter = 0; counter < cases; counter++)
    {
        scanf("%s", mains);
        scanf("%s", target);
        main_l = strlen(mains);
        target_1 = strlen(target);
        result = fn();
        print(result);
        printf("\n");

    }
    return 0;
}

bigint fn()
{
    for(int i = 0; i <= main_l; i++)
        initialize(dp[i][target_1], 1);

    for(int j = 0; j < target_1; j++)
        initialize(dp[main_l][j], 0);


    for(int j = target_1 - 1; j >= 0; j--)
        for(int i = main_l - 1; i >= 0; i--)
        {
            if(mains[i] == target[j])
                dp[i][j] = add(dp[i + 1][j + 1], dp[i + 1][j]);
            else
                dp[i][j] = dp[i + 1][j];
        }
    return dp[0][0];
}

void initialize(bigint &target, int x)
{
    target.array1[max1 - 1] = x;
    target.l = max1 - 1;
}

void print(bigint &x)
{
    for(int i = x.l; i < max1; i++)
        printf("%d", x.array1[i]);
}

bigint add(bigint &x, bigint &y)
{
    int num1, num2, temp = 0;
    bigint ans;
    int i;
    for(i = max1 - 1; i >= x.l || i >= y.l; i--)
    {
        if(i >= x.l)
            num1 = x.array1[i];
        else
            num1 = 0;

        if(i >= y.l)
            num2 = y.array1[i];
        else
            num2 = 0;
        temp = temp + num1 + num2;
        ans.array1[i] = temp % 10;
        temp = temp / 10;
    }
    if(temp == 0)
        ans.l = i + 1;
    else
    {
        ans.array1[i] = temp;
        ans.l = i;
    }
    return ans;
}




