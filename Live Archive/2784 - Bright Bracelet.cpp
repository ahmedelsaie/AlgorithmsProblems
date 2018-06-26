#include <stdio.h>

struct brace
{
    char faces[9];
};

void reset();
int min(int x, int y);
int cntbit(int mask);
int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);
int fn(int mask, char last, char first, int m);
int get_face(int x);

int values[8];
brace kolia[15];
int dp[9][9][2050];
int n;
const int inf = 100000000;

int main()
{
    int ans;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < 8; i++)
            scanf("%d", &values[i]);

        for(int i = 0; i < n; i++)
            scanf("%s", &kolia[i].faces);

        reset();
        ans = fn((1 << n) - 1, 'A', 'A', 0);

        if(ans >= inf)
            printf("impossible\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}

int fn(int mask, char last, char first, int m)
{
    if(m == n)
    {
        if(first == last)
            return values[first - 'A'];
        else
            return inf;
    }


    int &ret = dp[first - 'A'][last - 'A'][mask];
    if(ret != -1)
        return ret;
    ret = inf;
    int ans;
    bool flag = false;
    char help;
    if(m == 0)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 8; j++)
            {
                flag = true;
                int new_mask = mask;
                new_mask = setbit(new_mask, i, 0);
                help = kolia[i].faces[get_face(j)];
                ans = fn(new_mask, kolia[i].faces[j], help, m + 1);
                ret = min(ans, ret);
            }
    }
    else
    {
        for(int i = 0; i < n; i++)
            if(getbit(mask, i))
                for(int j = 0; j < 8; j++)
                    if(kolia[i].faces[j] == last)
                    {
                        help = kolia[i].faces[get_face(j)];
                        flag = true;
                        int new_mask = mask;
                        new_mask = setbit(new_mask, i, 0);
                        ans = fn(new_mask, help, first, m + 1) + values[last - 'A'];
                        ret = min(ans, ret);
                    }
    }

    if(flag == false)
        return inf;
    else
        return ret;
}

int get_face(int x)
{
    if(x + 4 < 8)
        return x + 4;
    else
        return 7 - x;
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

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 2050; k++)
                dp[i][j][k] = -1;
}
