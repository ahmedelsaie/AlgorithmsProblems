#include <stdio.h>
#include <stdlib.h>
struct word{char array [99999];
int no;};
struct word list[100];

int main()
{
    int n,counter;
    scanf("%d",&n);
    for(counter=0;counter<n;counter++)
    {
        scanf("%s",list[counter].array);
    }

    for(counter=0;counter<n;counter++)
    {
        count(counter);
    }


    for(counter=0;counter<n;counter++)
    {
        if(list[counter].no>10)
        {
            printf("%c%d%c\n",list[counter].array[0],list[counter].no-2,list[counter].array[list[counter].no-1]);
        }
        else
        {
            printf("%s\n",list[counter].array);
        }
    }

    return 0;
}



void count(int i)
{
    int no=0;
    while(list[i].array[no]!='\0')
    no++;
    list[i].no=no;

}
