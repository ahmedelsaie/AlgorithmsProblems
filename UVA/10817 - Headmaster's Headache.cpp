#include <stdio.h>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
#define inf 9999999

bool check(string in, int j, int cost[], int sub[], bool switch1);
int setbit(int mask, int bit, int value);
int min(int x, int y);
int fn(int mask1, int mask2, int app);

int working, applicants, subjects;
int working_cost[25];
int working_sub[25];
int applicants_cost[110];
int applicants_sub[110];
int mask1, mask2;
int dp[258][258][101];
bool visited[258][258][101];
int salary;
char input[100];

int main()
{
    while(true)
    {
        mask1 = 0;
        mask2 = 0;
        salary = 0;
        bool help;

        scanf("%d %d %d", &subjects, &working, &applicants);
        if(subjects == 0 && working == 0 && applicants == 0)
            break;

        for(int i = 0; i < working; i++)
        {
            gets(input);
            string str(input);
            help = check(str, i, working_cost, working_sub, true);
            if(!help)
                i--;
        }

        for(int i = 0; i < applicants; i++)
        {
            gets(input);
            string str(input);
            help = check(str, i, applicants_cost, applicants_sub, false);
            if(!help)
                i--;
        }

        memset(visited, false, sizeof(visited));
        salary += fn(mask1, mask2, 0);
        printf("%d\n", salary);
    }
    return 0;
}

int fn(int mask1, int mask2, int app)
{
    if(app > applicants)
        return inf;

    if(app == applicants)
    {
        if(mask1 == (1 << subjects) - 1 && mask2 == (1 << subjects) - 1)
            return 0;
        else
            return inf;
    }

    if(mask1 == (1 << subjects) - 1 && mask2 == (1 << subjects) - 1)
        return 0;


    bool &flag = visited[mask1][mask2][app];
    int &ret = dp[mask1][mask2][app];

    if(flag)
        return ret;
    flag = true;
    ret = inf;

    int new_mask = mask1 ^ mask2;
    new_mask = new_mask & applicants_sub[app];
    int new_mask2 = mask2 | new_mask;
    int new_mask1 = mask1 | applicants_sub[app];

    int temp;
    temp = fn(mask1, mask2, app + 1);
    ret = min(ret, temp);
    temp = fn(new_mask1, new_mask2, app + 1) + applicants_cost[app];
    ret = min(ret, temp);

    return ret;
}

bool check(string in, int j, int cost[], int sub[], bool switch1)
{
    bool flag = true;
    stringstream stream_str(in);

    int main;
    int i;
    int mask = 0;
    while(stream_str >> i)
    {
        if(flag)
            cost[j] = i;
        else
        {
            i--;
            mask = setbit(mask, i, 1);
        }

        flag = false;
    }
    if(flag)
        return false;


    sub[j] = mask;
    if(switch1)
    {
        int new_mask = mask1 ^ mask2;
        new_mask = new_mask & mask;
        mask2 = mask2 | new_mask;
        mask1 = mask1 | mask;
        salary += cost[j];
    }

    return true;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
