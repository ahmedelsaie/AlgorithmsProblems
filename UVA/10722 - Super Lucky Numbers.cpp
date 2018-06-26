#include <stdio.h>
#include <cstring>
const int max = 250;

struct bigint
{
    int array[max];
    int l = max;
};

void initialize(bigint &target, int x);
void print(bigint &x);
bigint add(bigint &x, bigint &y);
bool check (int i, int before);
bigint fn(int left, int before, bool flag, int base);

bigint dp[110][130][2][2];
bool visited[110][130][2][2];

int base, n;

int main()
{
    bigint ans;
    memset(visited, false, sizeof(visited));
    while(true)
    {
        scanf("%d %d", &base, &n);
        if(base == 0 && n == 0)
            break;

        ans = fn(n, false, true, base);
        print(ans);
        printf("\n");
    }

    return 0;
}

bigint fn(int left, int before, bool flag, int base)
{
    if(left < 0)
    {
        bigint ret;
        initialize(ret, 0);
        return ret;
    }

    if(left == 0)
    {
        bigint ret;
        initialize(ret, 1);
        return ret;
    }

    bool &v = visited[left][base][before][flag];

    if(v)
        return dp[left][base][before][flag];

    v = true;

    bigint ans, temp;
    initialize(ans, 0);

    if(!flag)
    {
        temp = fn(left - 1, 0, false, base);
        ans = add(ans, temp);
    }

    for(int i = 1; i < base; i++)
        if(check(i, before))
        {
            if(i == 1)
                temp = fn(left - 1, true, false, base);
            else
                temp = fn(left - 1, false, false, base);
            ans = add(ans, temp);
        }
    return dp[left][base][before][flag] = ans;
}

bool check (int i, int before)
{
    int x = i % 10;
    i = i / 10;

    int y = i % 10;
    i = i / 10;

    int z = i % 10;
    i = i / 10;

    if(before == 1)
    {
        if(z == 0 && y == 0 && x == 3)
            return false;
    }
    return true;
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
