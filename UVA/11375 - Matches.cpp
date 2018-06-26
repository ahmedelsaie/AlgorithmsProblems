#include <stdio.h>
#include <cstring>
const int max = 500;

struct bigint
{
    char array[max];
    int l = max;
};

void initialize(bigint &target, int x);
void print(bigint &x);
bigint add(bigint &x, bigint &y);
bigint fn(int left);

bigint dp[2000];
bool visited[2000];
bigint one;
int array[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    initialize(one, 1);
    bigint ans, temp;
    int x;
    memset(visited, false, sizeof(visited));

    while(scanf("%d", &x) != EOF)
    {
        initialize(ans, 0);
        for(int i = 1; i < 10; i++)
        {
            temp = fn(x - array[i]);
            ans = add(ans, temp);
        }

        if(x >= 6)
            ans = add(ans, one);
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

    bool &flag = visited[left];
    if(flag)
        return dp[left];

    flag = true;
    bigint ret, temp;

    initialize(ret, 1);


    for(int i = 0; i < 10; i++)
    {
        temp = fn(left - array[i]);
        ret = add(temp, ret);
    }

    return dp[left] = ret;

}

void initialize(bigint &target, int x)
{
    target.array[max - 1] = x;
    target.l = max - 1;
}

void print(bigint &x)
{
    for(int i = x.l; i < max; i++)
        printf("%d", x.array[i]);
}

bigint add(bigint &x, bigint &y)
{
    int num1, num2, temp = 0;
    bigint ans;
    int i;
    for(i = max - 1; i >= x.l || i >= y.l; i--)
    {
        if(i >= x.l)
            num1 = x.array[i];
        else
            num1 = 0;

        if(i >= y.l)
            num2 = y.array[i];
        else
            num2 = 0;
        temp = temp + num1 + num2;
        ans.array[i] = temp % 10;
        temp = temp / 10;
    }
    if(temp == 0)
        ans.l = i + 1;
    else
    {
        ans.array[i] = temp;
        ans.l = i;
    }
    return ans;
}
