#include <stdio.h>
#include <cstring>
struct block
{
    int type, size;
};

int pre_process(int length);
bool find(int start, int type);
void pre_process2(int length);
int min(int x, int y);
int fn(int i, int left, int prev, int mask);
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int get_size(int type, int start);

const int inf = 999999;
int n;
int input[105];
block array[105];
bool isexist[105];
int dp[102][50][9][257];

int main()
{
    int ans, moves;
    int p = 1;

    while(true)
    {
        scanf("%d %d", &n, &moves);
        if(n == 0 && moves == 0)
            break;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &input[i]);
            input[i] -= 25;
        }
        n = pre_process(n);
        pre_process2(n);
        memset(dp, -1, sizeof(dp));

        ans = fn(0, moves, 9, 0);
        printf("Case %d: %d\n\n", p++, ans);
    }
    return 0;
}

int fn(int i, int left, int prev, int mask)
{
    if(left < 0)
        return inf;
    if(i == n)
        return 0;

    int &ret = dp[i][left][prev][mask];
    if(ret != -1)
        return ret;
    ret = inf;
    int temp, target;

    // printf("state %d %d\n",i,prev);
    if(array[i].type == prev)
    {
        // printf("ahmed\n");
        temp = fn(i + 1, left, prev, setbit(mask, prev, 1));
        ret = min(temp, ret);
    }
    else
    {
        /////delete sent after
        if(isexist[i])
        {
            //   printf("vf %d\n",i);
            // update(new_n1,new_n2,new_n3,new_n4,new_n5,new_n6,new_n7,new_n8,array[i].type);
            temp = fn(i + 1, left - array[i].size, prev, mask);
            ret = min(ret, temp);
        }
        else
        {
            temp = fn(i + 1, left - array[i].size, prev, mask);
            ret = min(ret, temp + 1);
        }

        /////delete sent before

        if(getbit(mask, array[i].type))
        {
            temp = fn(i + 1, left - array[i].size, prev, mask);
            ret = min(ret, temp);
        }
        else
        {
            temp = fn(i + 1, left - array[i].size, prev, setbit(mask, array[i].type, 1));
            ret = min(ret, temp + 1);
        }


        /////lraved
        temp = fn(i + 1, left, array[i].type, setbit(mask, array[i].type, 1));
        ret = min(ret, temp + 1);


    }
    return ret;

}

int pre_process(int length)
{
    int ret = 0;
    int before = 50;
    int size = 0;

    for(int i = 0; i < length; i++)
    {
        if(input[i] != before)
        {
            array[ret].type = input[i];
            array[ret].size = get_size(input[i], i);
            ret++;
            before = input[i];
        }
        before = input[i];

    }
    return ret;
}

int get_size(int type, int start)
{
    int ret = 0;
    int before = type;
    for(int i = start; i < n; i++)
    {
        if(input[i] != before)
            break;
        else
            ret++;
        before = input[i];
    }
    return ret;
}

void pre_process2(int length)
{
    int ret = 0;
    int before = input[0];
    int size = 0;

    for(int i = 0; i < length; i++)
    {
        isexist[i] = find(i, array[i].type);
    }
}

bool find(int start, int type)
{
    for(int i = start + 1; i < n; i++)
        if(array[i].type == type)
            return true;
    return false;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
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

