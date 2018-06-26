#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 500

struct bigint
{
    static const int max1 = 105;
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

int bin_search(bool flag, bigint x);

bigint fib[MAX + 5];
bigint upper, lower;
char input[500], tmp;

int main()
{
    bool f1, f2;
    fib[1] = 1, fib[2] = 2;
    for(int i = 3; i <= MAX; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int j;
    while(true)
    {
        f1 = f2 = 0;
        scanf("%s", input), tmp = strlen(input), j = 105;
        for(int i = tmp - 1; i >= 0; i--)
            j--, lower.array[j] = input[i] - '0' , lower.l = j;
        if(tmp == 1 && input[0] == '0')
            f1 = 1;

        scanf("%s", input), tmp = strlen(input), j = 105;
        for(int i = tmp - 1; i >= 0; i--)
            j--, upper.array[j] = input[i] - '0' , upper.l = j;

        if(tmp == 1 && input[0] == '0')
            f2 = 1;
        if(f1 && f2)
            break;

        printf("%d\n", bin_search(1, upper) - bin_search(0, lower) + 1);
    }

    return 0;
}

int bin_search(bool flag, bigint x)
{
    int big = MAX, small = 1, mid, ret = -1;
    if(flag == 0)
        ret = 9999999;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(flag == 0)
            if(fib[mid] >= x && mid < ret)
                ret = mid;

        if(flag == 1)
            if(fib[mid] <= x && mid > ret)
                ret = mid;

        if(fib[mid] < x)
            small = mid + 1;
        else
            big = mid - 1;
    }

    return ret;
}

