#include <stdio.h>
#include <stdlib.h>
int target=0;
int mainflag=0;
unsigned long array[100000];
int main()
{
    int counter;
    scanf("%d",&target);



for(counter=0;counter<=target;counter++)
    array[counter]=counter*counter;

    for(counter=1;counter<target;counter++)
    {

     check(counter,0);         }



    printf("%d\n",mainflag);


    return 0;
}










void check(int x,int y)
{
    unsigned long p;
    int m=0;
    int n;
    int counter;
float ans;
    if (target<3)
    return ;
    else
    {
       if(y!=0)
        {
            counter=y+1;
            p=array[x]+array[y];
            ans=sqrt(p);
            counter=ans;
            if(array[counter]==p)
            mainflag++;







}

        else

            for(counter=x;counter<target;counter++)
            check(x,counter);




    }
}



