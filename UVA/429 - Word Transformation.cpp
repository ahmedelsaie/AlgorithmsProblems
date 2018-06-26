#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

struct word
{
    char arr[15];
    int l;
};
word array[210];

int min(int x, int y);
int fn(int current, int target);
bool check(int x, int y);
int find(char input[]);

int n;
int dp[201];
char first[15];
char sec[18];
char input[50];
const int inf = 9999999;
string start, to, line;

int main()
{
    int i = 0;
    int start, end, cases;
    scanf("%d", &cases);

    while(cases--)
    {
        i = 0;
        while(true)
        {
            scanf("%s", array[i].arr);
            if(array[i].arr[0] == '*')
                break;

            array[i].l = strlen(array[i].arr);
            i++;
        }
        n = i;
        gets(input);

        while (gets(input) && strlen(input))
        {
            sscanf(input, "%s %s", first, sec);
            start = find(first);
            end = find(sec);
            memset(dp, -1, sizeof(dp));
            printf("%s %s %d\n", first, sec, fn(start, end));
        }

        if(cases)
            printf("\n");
    }

    return 0;
}

int fn(int current, int target)
{
    if(current == target)
        return 0;

    int &ret = dp[current];
    if(ret != -1)
        return ret;

    ret = inf;
    int ans = inf;

    for(int i = 0; i < n; i++)
        if(check(current, i) && i != current)
            ans = min(ans, fn(i, target) + 1);

    return ret = ans;
}

int find(char input[])
{
    for(int i = 0; i < n; i++)
        if(strcmp(input, array[i].arr) == 0)
            return i;
    return -1;
}

bool check(int x, int y)
{
    if(array[x].l != array[y].l)
        return false;

    int length = array[x].l;
    int flag = 0;

    for(int i = 0; i < length; i++)
    {
        if(array[x].arr[i] != array[y].arr[i])
            flag++;
        if(flag > 1)
            return false;
    }

    return true;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
