#include <stdio.h>

int cntbit(int mask);
void print();

int array[100];
int m;
int main()
{
    int a;
    int result;
    while(true)
    {
        scanf("%d", &a);

        if(!a)
            break;

        result = cntbit(a);

        printf("The parity of ");
        print();
        printf(" is %d (mod 2).\n", result);
    }

    return 0;
}

void print()
{
    for(int i = m - 1; i >= 0; i--)
        printf("%d", array[i]);
    return ;
}

int cntbit(int mask)
{
    int ret = 0;
    m = 0;
    while(mask)
    {
        if(mask % 2)
        {
            ret++;
            array[m] = 1;
        }
        else
            array[m] = 0;

        mask = mask / 2;
        m++;
    }
    return ret;
}
