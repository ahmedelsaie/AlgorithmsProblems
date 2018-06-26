#include <stdio.h>
#include <cstring>
int length, main_depth;
const int max = 90;

struct bigint
{
    char array[max];
    int l = max;
};

void initialize(bigint &target, int x);
void print(bigint &x);
bigint add(bigint &x, bigint &y);
bigint fn(int prev_opened, int left, bool depth);

bigint dp[301][301][2];
bool visited[301][301][2];


int main()
{
    bigint ans;
    while(scanf("%d %d", &length, &main_depth) != EOF)
    {
        memset(visited, false, sizeof(visited));
        ans = fn(0, length, false);
        print(ans);
        printf("\n");
    }
    return 0;
}

bigint fn(int prev_opened, int left, bool depth)
{
    if(prev_opened > main_depth)
    {
        bigint x;
        initialize(x, 0);
        return x;
    }

    if(prev_opened > 2 * length)
    {
        bigint x;
        initialize(x, 0);
        return x;
    }

    if(left == 0)
    {
        bigint x;
        initialize(x, 1);

        if(depth && prev_opened == 0)
            return x;
        initialize(x, 0);
        return x;
    }

    bool &flag = visited[prev_opened][left][depth];
    bigint &ret = dp[prev_opened][left][depth];
    if(flag)
        return ret;

    flag = true;
    bigint x;
    bigint temp;
    initialize(x, 0);

    bool new_depth = depth;

    if(prev_opened > main_depth)
        new_depth = false;

    if(prev_opened == main_depth)
        new_depth = true;

    if(prev_opened > 0)
    {
        temp = fn(prev_opened - 1, left - 1, new_depth);
        x = add(x, temp);
    }

    temp = fn(prev_opened + 1, left - 1, new_depth);
    x = add(x, temp);

    return ret = x;
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
