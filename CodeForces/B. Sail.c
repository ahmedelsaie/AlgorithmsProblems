#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,sx,sy,ex,ey;
    char array[99999];
    scanf("%d%d%d%d%d",&t,&sx,&sy,&ex,&ey);
    scanf("%s",array);
    printf("%d",wind(sx,sy,ex,ey,array));



    return 0;
}



int wind(int sx,int sy,int ex,int ey,char array[])
{
    int i=0;
    int n=0;
    int s=0;
    int e=0;
    int w=0;

    int N=0;
    int S=0;
    int E=0;
    int W=0;

    int sxex=ex-sx;
    int syey=ey-sy;
    if(sxex>0)
    e=sxex;
    else
    {
        sxex=sxex*-1;
        w=sxex;
    }

    if(syey>0)
    n=syey;
    else
    {
        syey=syey*-1;
        s=syey;
    }

    while(array[i]!='\0')
    {
        if(array[i]=='E')
        E++;
        if(array[i]=='S')
        S++;
        if(array[i]=='W')
        W++;
        if(array[i]=='N')
        N++;

        if(W>=w && N>=n && S>=s && E>=e)
        return i+1;
        i++;
    }
    return -1;



}
