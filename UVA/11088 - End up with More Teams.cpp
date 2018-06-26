#include <stdio.h>

int fn(int mask, int left);
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int max(int x, int y);
void reset();

int dp[(1 << 15) + 1];
int points[20];
int n;

int main()
{
    int ans, cases = 1;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d", &points[i]);

        reset();
        ans = fn(0, 0);
        printf("Case %d: %d\n", cases, ans);
        cases++;
    }
    return 0;
}

int fn(int mask, int left)
{
    if(left == n)
        return 0;

    int &ret = dp[mask];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i = 0; i < n; i++)
        if(!getbit(mask, i))
        {
            for(int j = i + 1; j < n; j++)
                if(!getbit(mask, j))
                {
                    for(int k = j + 1; k < n; k++)
                        if(!getbit(mask, k))
                        {
                            int new_team = 0;
                            int accum = points[i] + points[j] + points[k];
                            int new_mask = mask;
                            new_mask = setbit(new_mask, i, 1);
                            new_mask = setbit(new_mask, j, 1);
                            new_mask = setbit(new_mask, k, 1);
                            int temp = fn(new_mask, left + 1);
                            if(accum >= 20)
                                new_team = 1;
                            ret = max(ret, temp + new_team);
                        }
                }
        }
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

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i = 0; i < (1 << n) + 1; i++)
        dp[i] = -1;
}


/*
#include <stdio.h>
int fn(int mask,int team_left,int accum,int left);
int setbit(int mask,int bit,int value);
int getbit(int mask,int bit);
int max(int x,int y);
void reset();

int dp[(1<<15)+1][3][95];
int points[20];
int n,max_accum;

int main()
{
    int ans,cases=1;
    while(true)
    {
        max_accum=0;
        scanf("%d",&n);
        if(n==0)
            break;

        for(int i=0; i<n; i++)
        {
            scanf("%d",&points[i]);
            max_accum+=points[i];
        }
        reset();
        ans=fn(0,0,0,0);
        printf("Case %d: %d\n",cases,ans);
        cases++;
    }
    return 0;
}

int fn(int mask,int team_left,int accum,int left)
{
    if(left==n)
        return 0;

    int &ret=dp[mask][team_left][accum];
    if(ret!=-1)
        return ret;
    ret=0;
    int temp;

    if(team_left==2)
    {
        for(int i=0; i<n; i++)
            if(!getbit(mask,i))
            {
                temp=fn(setbit(mask,i,1),0,0,left+1);
                if(accum+points[i]>=20)
                    ret=max(temp+1,ret);
                else
                    ret=max(temp,ret);
            }
    }
    else
    {
        for(int i=0; i<n; i++)
            if(!getbit(mask,i))
            {
                temp=fn(setbit(mask,i,1),team_left+1,accum+points[i],left+1);
                ret=max(temp,ret);
            }
    }
    return ret;
}

int setbit(int mask,int bit,int value)
{
    if(value==1)
        return(mask|(1<<bit));
    else
        return (mask&~(1<<bit));
}

int getbit(int mask,int bit)
{
    mask=(mask>>bit)&1;
    return (mask==1);
}

int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i=0; i<(1<<n)+1; i++)
        for(int j=0; j<3; j++)
            for(int k=0; k<max_accum; k++)
                dp[i][j][k]=-1;
}
*/
