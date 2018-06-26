#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
#define MAX 31

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int check(int msk, int l);
int build();
int fn();

vector<int> vec[MAX];
char arr[MAX];
int n, cases = 1;

int main()
{
    build();

    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        scanf("%s", arr);
        printf("Case %d: %d\n", cases++, fn());
    }

    return 0;
}

int fn()
{
    int ret = 0;
    for(int i = 0; i < vec[n].size(); i++)
    {
        int msk = vec[n][i];
        int f = 0;
        for(int j = 0; j < n; j++)
            if(arr[j] == '*' || (arr[j] - '0' == getbit(msk, j)))
                f++;
            else
                break;

        if(f == n)
            ret++;
    }

    return ret;
}

int build()
{
    int k;
    ///base case
    vec[1].push_back(0), vec[1].push_back(1);

    for(int bit = 2; bit <= 31; bit++)
    {
        k = 0;
        for(int i = 0; i < vec[bit - 1].size(); i++)
        {
            int msk = vec[bit - 1][i];
            msk = (msk << 1);
            int msk1 = setbit(msk, 0, 1);
            if(check(msk, bit))
                vec[bit].push_back(msk);

            if(check(msk1, bit))
                vec[bit].push_back(msk1);
        }

    }

}

int check(int msk, int l)
{
    if(l < 3)
        return 1;
    for(int t = 1; 3 * t <= l ; t ++)
    {
        int a = (1 << t) - 1;

        int m1 = msk;
        int m2 = (msk >> t);
        int m3 = (msk >> 2 * t);

        m1 &= a, m2 &= a, m3 &= a;

        if(m1 == m2 && m2 == m3)
            return 0;
    }

    return 1;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
