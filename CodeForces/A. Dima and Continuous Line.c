#include <stdio.h>
#include <stdlib.h>
int x1[2000];
int x2[2000];
int no_points;

int main()
{
    int x,y,counter;
    scanf("%d",&no_points);
    scanf("%d",&x);
    for(counter=0;counter<no_points-1;counter++)
    {
        scanf("%d",&y);
        x1[counter]=x;
        x2[counter]=y;
        x=y;
    }

    sort();
/*
    for(counter=0;counter<no_points-1;counter++)
    {
        printf("%d %d\n",x1[counter],x2[counter]);

    }

*/

    if(check()==1)
    printf("yes");
    else
    printf("no");



    return 0;
}






void sort()
{
    int counter;
    int z;
    for(counter=0;counter<no_points;counter++)
    {
        if(x1[counter]>x2[counter])
        {
            z=x1[counter];
            x1[counter]=x2[counter];
            x2[counter]=z;
        }

    }

}




int check()
{
    int counter,counter2;
    for(counter=0;counter<no_points;counter++)
    {
        for(counter2=counter;counter2<no_points;counter2++)
        {
            if(x1[counter2]>x1[counter]  && x1[counter2]<x2[counter] && x2[counter2]>x2[counter] )
            return 1;
            else
            if(x1[counter]>x1[counter2]  && x1[counter]<x2[counter2] && x2[counter]>x2[counter2] )
            return 1;
        }

    }
    return 0;

}
