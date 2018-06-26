#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll unsigned long long
using namespace std;

struct bigint
{
    static const int max1 = 105;
    char array[max1];
    int l = max1;

    void operator += (bigint x)
    {
        int n1, n2, i, tmp = 0;
        for(i = max1 - 1; i >= x.l || i >= l; i--)
        {
            n1 = n2 = 0;
            if(i >= x.l)
                n1 = x.array[i];

            if(i >= l)
                n2 = array[i];

            tmp = tmp + n1 + n2;
            array[i] = tmp % 10;
            tmp = tmp / 10;
        }

        if(tmp == 0)
            l = i + 1;
        else
            array[i] = tmp, l = i;
    }

    bigint operator + (bigint x)
    {
        int num1, num2, temp = 0;
        bigint ans;
        int i;
        for(i = max1 - 1; i >= x.l || i >= l; i--)
        {
            if(i >= x.l)
                num1 = x.array[i];
            else
                num1 = 0;

            if(i >= l)
                num2 = array[i];
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

    void operator = (int x)
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

bigint dp[301][301][2];
int visited[301][301][2];
int n, m_depth;
int cases = 1;
bigint fn(int index, int open, bool depth);


int main()
{
    bigint x;
//   bigint.test();

//  printf("%d\n", x.test());

    //freopen("brackets.in", "r", stdin);
    ///freopen("brackets.out", "w", stdout);
    memset(visited, -1, sizeof(visited));
    bigint ans;
    while(true)
    {
        scanf("%d %d", &n, &m_depth);
        if(n == 0 && m_depth == 0)
            break;
        n = 2 * n;
        ans = fn(0, 0, 0);
        ans.print();
        printf("\n");
        cases++;
    }

    return 0;
}


bigint fn(int index, int open, bool depth)
{
    // printf("%d %d\n", index, open);
    if(open < 0 || open > m_depth)
    {
        bigint ret;
        ret = 0;
        //inti(ret, 0);
        return ret;
    }

    if(index == n)
    {
        bigint ret;
        if(open == 0 && depth)
        {
            ret = 1;
            return ret;
        }
        ret = 0;
        return ret;
    }

    bigint& ret = dp[index][open][depth];
    int& flag = visited[index][open][depth];
    if(flag == cases)
        return ret;
    flag = cases;
    bigint tmp, fin;
    tmp = 0;
    //7 inti(tmp, 0);


    bool new_depth = depth;
    if(open == m_depth)
        new_depth = 1;

    if(open > m_depth)
        new_depth = 0;

    tmp += fn(index + 1, open + 1, new_depth);
    //fin = add(fin, tmp);

    tmp += fn(index + 1, open - 1, new_depth);
    //fin = add(fin, tmp);

    ret = tmp;
    return tmp;
}

