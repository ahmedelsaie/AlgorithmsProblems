#include <stdio.h>

void bsort();

int array[3];

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%d %d %d", &array[0], &array[1], &array[2]);
        bsort();
        printf("Case %d: %d\n", i + 1, array[1]);
    }
    return 0;
}

void bsort()
{
    int swap;
    bool flag;
    for(int i = 0; i < 2; i++)
    {
        flag = true;
        for(int j = 0; j < 2; j++)
            if(array[j] > array[j + 1])
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}
