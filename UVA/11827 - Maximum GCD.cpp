#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

void fn();
int max(int x, int y);
int GCD(int a, int b);
int check(string in);

int array[150];
int n;
string str;
int ans;
const int inf = 99999999;
char input[99999];

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        n = 0;
        while(true)
        {
            getline(cin, str, '\n');
            if(check(str) != -1)
                break;
        }
        fn();
        printf("%d\n", ans);
    }
    return 0;
}

int check(string in)
{
    int flag = 0;
    stringstream stream_str(in);

    int main;
    int i;
    n = 0;
    while(stream_str >> i)
    {
        array[n] = i;
        n++;
        flag++;
    }

    if(flag == 0)
        return -1;
    else
        return n;
}

int GCD(int a, int b)
{
    return !b ? a : GCD(b, a % b);
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void fn()
{
    ans = -1 * inf;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            ans = max(ans, GCD(array[i], array[j]));
}
