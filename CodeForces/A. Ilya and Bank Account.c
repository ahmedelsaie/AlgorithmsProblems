#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    if(x<0)
    {
        if(fun1(x)>fun2(x))
        printf("%d",fun1(x));
        else
        printf("%d",fun2(x));
    }
    else
    printf("%d",x);


    return 0;
}


int fun1(int x)
{
    return x/10;

}

int fun2(int x)
{
    int n=x%10;
    x=x/100;
    x=x*10;
    x=x+n;
    return x;
}
