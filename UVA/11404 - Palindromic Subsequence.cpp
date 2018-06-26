#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int fn(int left, int right);
int comp(const string &help, const string &help2);
void reset();

string arr;
int dp[1005][1005];
string got[1005][1005];
int length;

int main()
{
    char input[1005];
    int l, m;
    while(gets(input))
    {
        arr = string (input);

        length = arr.length();
        reset();
        fn(0, length - 1);
        string result = got[0][length - 1];
        l = result.length();

        if(result[l - 1] == '0')
        {
            string helper = " ";
            m = l - 1;
            int taty = 0;
            for(int i = l - 3; i >= 0; i--)
            {
                if(m > l - 1)
                    result += helper;
                result[m++] = result[i];
                taty++;
            }
            if(taty == 0)
            {
                result.resize(l - 1);

            }
        }
        else
        {
            result += result;
            m = l;
            for(int i = l - 1; i >= 0; i--)
            {
                result[m] = result[i];
                m++;
            }
        }

        char arr2[500];
        int i;
        for(i = 0; i < result.length(); i++)
            arr2[i] = result[i];
        arr2[i] = '\0';
        printf("%s\n", arr2);
    }

    return 0;
}

int fn(int left, int right)
{
    int &ret = dp[left][right];

    if(left == right)
    {
        string r;
        r += arr[left];
        char ahmed = '0';
        ret = fn(left + 1, right - 1) + 1;
        r += got[left + 1][right - 1];
        r += ahmed;
        got[left][right] = r;

        return ret;
    }

    if(left > right)
        return ret = 0;

    if(ret != -1)
        return ret;

    int x1, x2;

    if(arr[left] == arr[right])
    {
        string r;
        r += arr[left];
        ret = fn(left + 1, right - 1) + 1;
        r += got[left + 1][right - 1];
        got[left][right] = r;

        return ret;
    }

    string help;
    string help2;

    x1 = fn(left + 1, right);
    help2 = got[left + 1][right];

    x2 = fn(left, right - 1);
    help = got[left][right - 1];

    if(x1 > x2)
    {
        got[left][right] = help2;
        return ret = x1;
    }
    else if(x2 > x1)
    {
        got[left][right] = help;
        return ret = x2;
    }

    if(x1 == x2)
    {
        if(comp(help, help2) == 2)
            got[left][right] = help2;
        else
            got[left][right] = help;
        return ret = x2;
    }

}

void reset()
{
    for(int i = 0; i < length; i++)
        for(int j = 0; j < length; j++)
            dp[i][j] = -1;
}

int comp(const string &help, const string &help2)
{
    int x1 = help.length();
    int x2 = help2.length();

    if(help[x1 - 1] != '0' && help2[x2 - 1] != '0')
    {
        if(help2 < help)
            return 2;
        else
            return 1;
    }

    if(help[x1 - 1] == '0' && help2[x2 - 1] == '0')
    {
        if(help2 < help)
            return 2;
        else
            return 1;
    }

    if(help[x1 - 1] == '0' && help2[x2 - 1] != '0')
        return 2;

    if(help[x1 - 1] != '0' && help2[x2 - 1] == '0')
        return 1;
}

