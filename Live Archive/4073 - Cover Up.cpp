#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

double get_others(int new_mask, int mask, int level);
void preprocess();
void reset();
bool check(int new_mask, int level);
double proba(int mask, int level);
int cntbit(int mask);
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);

int n;
vector<int> masks[32768];
double dp[1000][30000];
int no[50];
char temp[50];

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
        {
            scanf("%s", temp);
            no[j] = strlen(temp);
        }
        reset();
        preprocess();
        printf("%.3f\n", proba(0, 0));
    }

    return 0;
}

double proba(int mask, int level)
{
    double ans = 0;
    if(cntbit(mask) == n)
        return 1;

    double& ret = dp[level][mask];
    if(ret == ret)
        return ret;


    for (std::vector<int>::iterator t = masks[mask].begin(); t != masks[mask].end(); t++)
    {
        int new_mask = *t;
        if(check((new_mask | mask), level))
            ans += proba(new_mask | mask, level + 1) * get_others(new_mask, mask, level);
    }
    return ret = ans;
}

bool check(int new_mask, int level)
{
    level++;
    for(int i = 0; i < n; i++)
        if(no[n - 1 - i] - level <= 0 && !getbit(new_mask, i))
            return false;
    return true;
}

void preprocess()
{
    for(int i = 0; i < (1 << n); i++)
    {
        int submask_upper = ~(i);
        int m = (1 << n);
        m--;
        submask_upper = ( m & submask_upper);

        for(int j = submask_upper; j > 0; j = (j - 1)&submask_upper)
            masks[i].push_back(j);
    }
    return ;
}

void reset()
{
    for(int i = 0; i < n + 10; i++)
        for(int j = 0; j < (1 << n) + 1; j++)
            dp[i][j] = NAN;

    for(int j = 0; j < (1 << n) + 1; j++)
        masks[j].clear();

    return ;
}

double get_others(int new_mask, int mask, int level)
{
    double ans = 1;
    for(int i = 0; i < n; i++)
    {
        if(!getbit(mask, i))
        {
            int t = no[n - 1 - i] - level;
            double temp = (double)t;
            temp = 1 / temp;
            if(!getbit(new_mask, i))
                temp = 1 - temp;
            ans = ans * temp;
        }
    }

    return ans;
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

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
    }
    return ret;
}
