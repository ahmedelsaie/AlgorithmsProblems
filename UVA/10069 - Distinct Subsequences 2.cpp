#include <stdio.h>
#include <cstring>

const int max1 = 100;

struct bigint
{
    char array1[max1];
    int l = max1;
};

char mains[10005];
char target[105];
int target_1, main_l;


bigint dp[10005][2];
void initialize(bigint& target, int x);
void print(bigint& x);
bigint add(bigint& x, bigint& y);
bigint fn();
void turn(bool& key);

int main()
{
    int cases;
    bigint result;

    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
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
        initialize(dp[i][1], 1);

    for(int j = 0; j < 1; j++)
        initialize(dp[main_l][j], 0);

    bool switch1 = false;
    bool firstrun = true;

    for(int j = target_1 - 1; j >= 0; j--)
    {
        turn(switch1);
        for(int i = main_l - 1; i >= 0; i--)
        {
            if(mains[i] == target[j])
                dp[i][!switch1] = add(dp[i + 1][1], dp[i + 1][0]);
            else
                dp[i][!switch1] = dp[i + 1][!switch1];
        }

        if(firstrun)
        {
            turn(firstrun);
            initialize(dp[main_l][1], 0);
        }
    }

    return dp[0][!switch1];
}

void turn(bool& key)
{
    if(key)
        key = false;
    else
        key = true;
}

void initialize(bigint& target, int x)
{
    target.array1[max1 - 1] = x;
    target.l = max1 - 1;
}

void print(bigint& x)
{
    for(int i = x.l; i < max1; i++)
        printf("%d", x.array1[i]);
}

bigint add(bigint& x, bigint& y)
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
