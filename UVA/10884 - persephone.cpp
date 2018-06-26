#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 105

///BigInteger
struct bigint
{
    static const int max1 = 30;
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

bigint fn(int left, int prev_y , int y, int x, int before, int f1, int f2);
void pre_process();

bigint dp[MAX][MAX][MAX][2][2][2][2];
bigint res[MAX];
bool visited[MAX][MAX][MAX][2][2][2][2];

int main()
{
    bigint ans;
    int n, cases, p = 1;
    memset(visited, 0, sizeof(visited));
    pre_process();

    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);

        printf("Case #%d: ", p++);
        res[n].print();
        printf("\n");
    }
    return 0;
}

void pre_process()
{
    for(int n = 0; n <= 100; n++)
    {
        res[n] = 0;
        for(int i = 1; i < n - 2; i++)
            res[n] += fn(n - (2 + i), i, i, 0, 0, 0, 0);
    }
}

bigint fn(int left, int prev_y , int y, int x, int before, int f1, int f2)
{
    int l = left;

    if(left == 0)
    {
        if(x == 0 && y == 0)
            return 1;
        return 0;
    }

    if(left < 0 || (x == 0 && y == 0) || y == 0)
        return 0;

    bigint& ret = dp[left][prev_y][y][x][before][f1][f2];
    bool& flag = visited[left][prev_y][y][x][before][f1][f2];
    if(flag)
        return ret;
    flag = 1, ret = 0;

    ///working in the upper
    if(x == 0)
    {
        ///still going up
        if(!f1)
        {

            ret += fn(left - 1, prev_y, y + 1, x, 1, f1, f2); /// go up
            ret += fn(left - 1, prev_y, y, x + 1, 0, f1, f2); /// go right

            if(before == 0 && y - 1 >= 0)
                ret += fn(left - 1, prev_y, y - 1, x , 0, 1, f2); /// shift and go down
        }
        else
        {
            ret += fn(left - 1, prev_y, y - 1, x, 1, f1, f2); /// go down
            ret += fn(left - 1, prev_y, y, x + 1, 0, f1, f2); /// go right
        }

    }
    else
    {
        ///still going down
        if(!f2)
        {
            ret += fn(left - 1, y, y + 1, x, 1, f1, f2); /// go down
            ret += fn(left - 1, y, y, x - 1, 0, f1, f2); /// go right

            if(before == 0 && y - 1 >= 0 && prev_y - 1 > 0)
                ret += fn(left - 1, prev_y - 1, y - 1, x , 0, f1, 1); /// shift and go up
        }
        else
        {
            if(y - 1 >= 0 && prev_y - 1 > 0)
                ret += fn(left - 1, prev_y - 1, y - 1, x, 1, f1, f2); /// go up
            ret += fn(left - 1, y, y, x - 1, 0, f1, f2); /// go right
        }
    }

    return ret;
}
