#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

///BigInteger
struct bigint
{
    static const int max1 = 215;
    char array[max1];
    int l = max1;

    bigint()
    {

    }

    bigint(int x)
    {
        *this = x;
    }

    void operator += (bigint x)
    {
        *this = add(x, *this);
    }

    bigint operator + (bigint x)
    {
        return add(x, *this);
    }

    bigint add(bigint& x, bigint& y)
    {
        int num1, num2, temp = 0;
        bigint ans;
        int i;
        for(i = max1 - 1; i >= x.l || i >= y.l; i--)
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

    bigint operator = (int x)
    {
        if(x == 0)
        {
            array[max1 - 1] = x;
            l = max1 - 1;
        }
        else
        {
            char tmp;
            int y;
            int j = max1 - 1;
            while(x)
            {
                y = x % 10;
                tmp = '0' + y;
                array[j] = y;
                x = x / 10;
                j--;
            }

            l = j + 1;
        }
        return *this;
    }

    bool operator == (bigint& x)
    {
        return comp(*this, x) == 0;
    }

    bool operator != (bigint& x)
    {
        return comp(*this, x) != 0;
    }

    bool operator < (bigint& x)
    {
        return comp(*this, x) < 0;
    }

    bool operator <= (bigint& x)
    {
        return comp(*this, x) <= 0;
    }

    bool operator > (bigint& x)
    {
        return comp(*this, x) > 0;
    }

    bool operator >= (bigint& x)
    {
        return comp(*this, x) >= 0;
    }

    int comp(bigint& x, bigint& y)
    {
        if(x.l < y.l)
            return 1;
        if(y.l < x.l)
            return -1;
        int ret = 0;

        for(int i = x.l; i < max1; i++)
            if(x.array[i] < y.array[i])
                return -1;
            else if(x.array[i] > y.array[i])
                return 1;

        return ret;
    }

    void print ()
    {
        for(int i = l; i < max1; i++)
            printf("%d", array[i]);
    }
};

bigint fn(int left, int pane, int direction);
bigint dp[1005][4][2];
bool visited[1005][4][2];

int main()
{
    bigint ans;
    int n;
    memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= 1000; i++)
        fn(i, 0, 0);

    while(scanf("%d", &n) != EOF)
    {
        ans = fn(n, 1, 0);
        ans.print();
        printf("\n");
    }

    return 0;
}

bigint fn(int left, int pane, int direction)
{
    if(pane == 3 || pane == -1)
        return (left == 0);

    if(left < 0)
        return 0;

    bigint& ret = dp[left][pane][direction];
    bool& flag = visited[left][pane][direction];
    if(flag)
        return ret;
    flag = 1, ret = 0;

    ///going down
    if(direction == 0)
    {
        ret += fn(left, pane + 1, direction);

        ///shift
        ret += fn(left - 1, pane - 1, !direction);
    }

    ///going up
    if(direction == 1)
    {
        ret += fn(left, pane - 1, direction);

        ///shift
        ret += fn(left - 1, pane + 1, !direction);
    }

    return ret;
}
