#include <stdio.h>
#include <cstring>
const int max = 500;

struct bigint
{
    int arr[max];
    int l = max;
};

void initialize(bigint &target, int x);
void print(bigint &x);
bigint add(bigint &x, bigint &y);
bigint fn(int left);

bigint dp[1005];
int visited[1005];

int main()
{
    int x;
    bigint ans;
    memset(visited, -1, sizeof(visited));

    for(int i = 0; i < 1000; i++)
        fn(i);

    while(scanf("%d", &x) != EOF)
    {
        ans = fn(x);
        print(ans);
        printf("\n");
    }

    return 0;
}

bigint fn(int left)
{
    if(left < 0)
    {
        bigint temp;
        initialize(temp, 0);
        return temp;
    }

    if(left == 0)
    {
        bigint temp;
        initialize(temp, 1);
        return temp;
    }

    int &flag = visited[left];

    if(flag != -1)
        return dp[left];
    flag = 1;

    bigint ans, temp;
    initialize(ans, 0);

    temp = fn(left - 1);
    ans = add(ans, temp);

    temp = fn(left - 1);
    ans = add(ans, temp);

    temp = fn(left - 2);
    ans = add(ans, temp);

    temp = fn(left - 3);
    ans = add(ans, temp);

    return dp[left] = ans;
}

void initialize(bigint &target, int x)
{
    target.arr[max - 1] = x;
    target.l = max - 1;
}

void print(bigint &x)
{
    for(int i = x.l; i < max; i++)
        printf("%d", x.arr[i]);
}

bigint add(bigint &x, bigint &y)
{
    int num1, num2, temp = 0;
    bigint ans;
    int i;
    for(i = max - 1; i >= x.l || i >= y.l; i--)
    {
        if(i >= x.l)
            num1 = x.arr[i];
        else
            num1 = 0;

        if(i >= y.l)
            num2 = y.arr[i];
        else
            num2 = 0;
        temp = temp + num1 + num2;
        ans.arr[i] = temp % 10;
        temp = temp / 10;
    }
    if(temp == 0)
        ans.l = i + 1;
    else
    {
        ans.arr[i] = temp;
        ans.l = i;
    }
    return ans;
}
