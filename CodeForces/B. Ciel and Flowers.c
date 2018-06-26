#include <stdio.h>
#include <stdlib.h>
struct flo{
           int flono;
           int bono;
           int leftno;
           }
           ;
           struct flo input[3];
           int mainflag=0;
int main()
{
    scanf("%d %d %d",&input[0].flono,&input[1].flono,&input[2].flono);
    calc();
    printf("%d",mainflag);
    return 0;
}



int ifoneonlyzeroleft()
{
    int flag=0;
    int counter;
    for(counter=0;counter<3;counter++)
    {
        if(input[counter].leftno!=0)
        flag++;
    }
    if(flag==2)
    return 1;
    else
    return 0;
}



void calc()
{
   int counter;
    for(counter=0;counter<3;counter++)
    {
        input[counter].leftno=input[counter].flono%3;
        input[counter].bono=input[counter].flono/3;
    }

    ///////////////////////////////////////////////////////////////////
    if(ifoneonlyzeroleft()==1)
    {
        for(counter=0;counter<3;counter++)
    {
        if(input[counter].leftno==0 && input[counter].flono>0)
        {
            input[counter].leftno=input[counter].leftno+3;
            input[counter].bono--;

        }
    }
    }
    /////////////////////////////////////////////////////////////////////////
  for(counter=0;counter<3;counter++)
  mainflag=mainflag+input[counter].bono;
  ///////////////////////////////////////////////////////////////////////////////////

while(input[0].leftno>0 && input[1].leftno>0 && input[2].leftno>0)
{
    mainflag++;
    input[0].leftno--;
    input[1].leftno--;
    input[2].leftno--;
}


}

