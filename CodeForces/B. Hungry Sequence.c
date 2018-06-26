#include <stdio.h>
#include <stdlib.h>
int array[999999];
int isprime(float x);
int main()
{
    int n;
    scanf("%d",&n);
    gen(n);
    int counter;
    for(counter=0;counter<n;counter++)
    {
        printf("%d ",array[counter]);

    }

    return 0;
}



int isprime(float x)
{
    int y;
    int counter;
    y=x;
    x=sqrt(x);

    for(counter=2;counter<=x;counter++)
    {

        if(y%counter==0)
        return 0;
    }
    return 1;


}





void gen(int n)
{
    int get=0;
    int num=3;
    while(get<n)
    {
        if(isprime(num)==1)
        {
            array[get]=num;
            get++;
        }
        num++;

    }



}
