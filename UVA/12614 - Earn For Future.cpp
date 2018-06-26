#include <stdio.h>
int max(int x,int y);
int main()
{
    int cases,n,x,ans;
    scanf("%d",&cases);

    for(int i=0;i<cases;i++)
    {
        ans=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
           scanf("%d",&x);
           ans=max(ans,x);
        }
        printf("Case %d: %d\n",i+1,ans);
    }

    return 0;
}

int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
