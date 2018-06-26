#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",ways(x));
    return 0;
}









int ways(int x)
{
    int keypressed=0;
    int ways=0;
    while(x>0)
    {
        ways=ways+x+keypressed*(x-1);
        keypressed++;
        x--;
    }
    return ways;
}
