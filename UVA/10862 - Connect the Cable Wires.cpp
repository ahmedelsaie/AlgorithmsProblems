#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct bigint
{
    static const int max1 = 1005;
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

bigint fn(int left, int state);
void tabular();

bigint dp[2005][2];

int main()
{
    int n;
    tabular();

    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        dp[n][0].print();
        printf("\n");
    }

    return 0;
}

void tabular()
{
    int state;
    for(int left = 0; left <= 2001; left++)
        for(state = 0; state <= 1; state++)
        {
            bigint& ret = dp[left][state];
            ret = 0;
            if(left == 0)
                ret = (state == 1);
            else
            {
                ///1 before Connected
                if(state)
                {
                    ret += dp[left - 1][1]; ///connect to before
                    ret += dp[left - 1][1]; ///connect to center
                    ret += dp[left - 1][0]; ///don't connect
                }
                else
                {
                    ret += dp[left - 1][1]; ///connect to center
                    ret += dp[left - 1][0]; ///don't connect
                }
            }
        }
}

bigint fn(int left, int state)
{
    if(left == 0)
        return state == 1;

    // bool& flag =1;
    bigint& ret = dp[left][state];
    // if(flag)
    return ret;
    //flag = true, ret = 0;

    ///1 before Connected
    if(state)
    {
        ret += fn(left - 1, 1); ///connect to before
        ret += fn(left - 1, 1); ///connect to center
        ret += fn(left - 1, 0); ///don't connect
    }
    else
    {
        ret += fn(left - 1, 1); ///connect to center
        ret += fn(left - 1, 0); ///don't connect
    }
    return ret;
}
