#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long


int const inf=99999999;
int fn();
int check(int sec);

int water[MAX],tanks[MAX];
int n_tanks,n_waters,v[500];

int main()
{
    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d %d",&n_tanks,&n_waters);
        for(int i=0;i<n_waters;i++)
            scanf("%d",&water[i]),water[i]--;

        printf("%d\n",fn());
    }

    return 0;
}

int fn()
{
    int ret=inf;

    int s=0,b=n_tanks;

    while(b>=s)
    {
        int mid=(b+s)/2;

        int c=check(mid);
        if(c)
            ret=min(ret,mid),b=mid-1;
        else
            s=mid+1;
    }


    return ret;
}

int check(int sec)
{
    memset(v, 0, sizeof(v));

    for(int i = 0; i < n_waters; i++)
    {
        for(int j = 0; j < sec; j++)
        {
            int b = water[i] + j;
            b = min(b, n_tanks - 1);
            int s = water[i] - j;
            s = max(0, s);
            v[b] = v[s] = 1;
        }
    }

    for(int i = 0; i < n_tanks; i++)
        if(v[i] == 0)
            return 0;

    return 1;
}
