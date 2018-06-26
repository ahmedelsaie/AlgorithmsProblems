#include <stdio.h>
#include <math.h>


int main()
{
    int target,ans=0;
    int r,s;
    scanf("%d",&target);
    for(int i=1;i<target;i++)
    for(int j=i+1;j<target;j++)
    {
        r=(i*i)+(j*j);
        s=sqrt(r);
        if(s*s==r && s<=target)
            ans++;


        if(s>target)
            break;
    }

    printf("%d",ans);
    return 0;
}



