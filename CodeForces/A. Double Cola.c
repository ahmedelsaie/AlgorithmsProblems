#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);

    int c=operator(x);
    switch (c)
    {
        case 1:
        printf("Sheldon");
        break;

         case 2:
        printf("Leonard");
        break;


         case 3:
        printf("Penny");
        break;

         case 4:
        printf("Rajesh");
        break;


         case 5:
        printf("Howard");
        break;
    }



    return 0;
}









int operator(int x)
{
    char array[999999];
    int n=1;
    int m=1;
    int counter;
    while(n<=x)
    {
        for(counter=0;counter<m;counter++)
        {

            array[n]='s';
            if(n==x)
            return 1;
             n++;
        }

         for(counter=0;counter<m;counter++)
        {
            array[n]='l';
            if(n==x)
            return 2;
             n++;
        }


         for(counter=0;counter<m;counter++)
        {
            array[n]='p';
            if(n==x)
            return 3;
             n++;
        }


         for(counter=0;counter<m;counter++)
        {
            array[n]='r';
            if(n==x)
            return 4;
             n++;
        }


         for(counter=0;counter<m;counter++)
        {
            array[n]='h';
            if(n==x)
            return 5;
             n++;
        }



        m=m*2;
    }
}
