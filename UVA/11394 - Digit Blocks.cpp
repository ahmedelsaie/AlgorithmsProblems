#include <stdio.h>
#include <cstring>

long long power(long long pow);
int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);
long long fn(int mod, int mask, int left);
void reset();
void bsort();

long long dp[(1 << 16)][5];
long long dp_power[20];
bool visited[(1 << 16)][5];
int value(char c);
char array[20];
int l;

int main()
{
    memset(dp_power, -1, sizeof(dp_power));
    while(true)
    {
        scanf("%s", array);
        if(array[0] == '#')
            break;
        l = strlen(array);

        memset(visited, false, sizeof(visited));
        bsort();

        printf("%lld\n", fn(0, 0, 0) - 1);
    }
    return 0;
}

long long fn(int mod, int mask, int left)
{
    //printf("%d %d %d\n",mod,mask,left);
    if(left == l)
    {
        if(mod == 0)
            return 1;
        return 0;
    }

    long long &ret = dp[mask][mod];
    bool &flag = visited[mask][mod];
    if(flag)
        return ret;
    flag = true;
    ret = 0;
    if(mod == 0)
        ret = fn(0, 0, l);

    char prev = 'p';
    long long p = power(left);

    for(int i = 0; i < l; i++)
    {
        if(!getbit(mask, i) && prev != array[i])
        {
            // printf("%d\n",value(array[i]));
            long long r = mod + p * value(array[i]);
            r = r % 5;
            ret += fn(r, setbit(mask, i, 1), left + 1);
            prev = array[i];
        }
        // prev=array[i];
    }
    return ret;

}

long long power(long long pow)
{
    long long &ret = dp_power[pow];
    if(ret != -1)
        return ret;
    ret = 1;
    for(int i = 1; i < pow; i++)
        ret = ret * 16;
    return ret;
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

int value(char c)
{
    if(c == '1')
        return 1;
    if(c == '2')
        return 2;
    if(c == '3')
        return 3;
    if(c == '4')
        return 4;
    if(c == '5')
        return 5;
    if(c == '6')
        return 6;
    if(c == '7')
        return 7;
    if(c == '8')
        return 8;
    if(c == '9')
        return 9;
    if(c == 'A')
        return 10;
    if(c == 'B')
        return 11;
    if(c == 'C')
        return 12;
    if(c == 'D')
        return 13;
    if(c == 'E')
        return 14;
    if(c == 'F')
        return 15;
}

void bsort()
{
    int swap;
    bool flag;
    for(int i = 0; i < l - 1; i++)
    {
        flag = true;
        for(int j = 0; j < l - 1; j++)
            if(array[j] > array[j + 1])
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}
