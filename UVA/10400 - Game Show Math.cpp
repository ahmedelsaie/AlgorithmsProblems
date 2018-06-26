#include <stdio.h>
#include <cstring>
int fn(int value, int i);
bool check(int x);
void trace(int value, int i);
int dp[64009][102];
int n, target;
int arr[105];
int correct = 32000;

int main()
{
    int cases, ans;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &target);

        memset(dp, -1, sizeof(dp));
        ans = fn(32000, 0);
        if(ans)
        {
            printf("%d", arr[0]);
            trace(arr[0] + correct, 1);
            printf("=%d", target);
        }
        else
            printf("NO EXPRESSION");

        printf("\n");
    }

    return 0;
}

void trace(int value, int i)
{
    int new_value = value - correct;

    if(i == n)
        return ;

    if(check(new_value * arr[i]) && dp[new_value * arr[i] + correct][i + 1] == 1)
    {
        printf("*%d", arr[i]);
        trace(new_value * arr[i] + correct, i + 1);
        return ;
    }

    if(check(new_value + arr[i]) && dp[new_value + arr[i] + correct][i + 1] == 1)
    {
        printf("+%d", arr[i]);
        trace(new_value + arr[i] + correct, i + 1);
        return ;
    }

    if(check(new_value - arr[i]) && dp[new_value - arr[i] + correct][i + 1] == 1)
    {
        printf("-%d", arr[i]);
        trace(new_value - arr[i] + correct, i + 1);
        return ;
    }

    if(arr[i] != 0 && check(new_value / arr[i]) && new_value % arr[i] == 0 && dp[new_value / arr[i] + correct][i + 1] == 1)
    {
        printf("/%d", arr[i]);
        trace(new_value / arr[i] + correct, i + 1);
        return ;
    }
}

int fn(int value, int i)
{
    int &ret = dp[value][i];
    if(ret != -1)
        return ret;

    int new_value = value - correct;
    int send;

    if(i == n)
    {
        if(new_value == target)
            return ret = 1;
        return ret = 0;
    }

    ret = 0;
    if(check(new_value * arr[i]))
    {
        send = new_value * arr[i];
        send += correct;
        ret = ret | fn(send, i + 1);
    }

    if(check(new_value + arr[i]))
    {
        send = new_value + arr[i];
        send += correct;
        ret = ret | fn(send, i + 1);
    }

    if(check(new_value - arr[i]))
    {
        send = new_value - arr[i];
        send += correct;
        ret = ret | fn(send, i + 1);
    }

    if(arr[i] != 0 && check(new_value / arr[i]) && new_value % arr[i] == 0)
    {
        send = new_value / arr[i];
        send += correct;
        ret = ret | fn(send, i + 1);
    }

    return ret;
}

bool check(int x)
{
    if(x >= -32000 && x <= 32000)
        return true;
    return false;
}
