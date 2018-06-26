#include <stdio.h>
#include <stdlib.h>
int istrue(int x);
int isbefore1(int x);
int isbefore14(int x);

int main()
{
    int x;
    scanf("%d",&x);
    if(istrue(x)==1)
    printf("YES\n");
    else
    printf("NO");
    return 0;
}












int isbefore1(int x)
{
    if(x==0)
    return 0;
    else
    {
        x=x/10;
        if(x%10==1)
        return 1;
        else
        return 0;
    }

}


int isbefore14(int x)
{
    if(x==0)
    return 0;
    else
    {
        x=x/10;
        if(x%10==4)
        {
            x=x/10;
            if(x%10==1)
            return 1;
            else
            return 0;


        }
        else
    return 0;
    }

}



int istrue(int x)
{

    if(x==0)
    return 0;
    else
    {while(x!=0)
    {
        if(x%10==4 || x%10==1)
        {
            if(x%10==4)
            {if(isbefore1(x)==1 || isbefore14(x)==1 )
             x=x/10;
             else
             return 0;
            }
            else
            x=x/10;
        }
        else
        return 0;
    }
    return 1;

}
}


