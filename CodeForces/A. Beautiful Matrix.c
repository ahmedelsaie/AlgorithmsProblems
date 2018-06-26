#include <stdio.h>
#include <stdlib.h>

int array[5][5];

int main()
{
    int counter, counter2;
    for(counter = 0; counter < 5; counter++)
    {
        for(counter2 = 0; counter2 < 5; counter2++)
        {
            scanf("%d", &array[counter][counter2]);
        }
    }

    printf("%d", operator());
    return 0;
}

int operator()
{
    int flag = 0;
    int ans, ans2;
    int counter, counter2;

    for(counter = 0; counter < 5; counter++)
    {
        for(counter2 = 0; counter2 < 5; counter2++)
        {
            if(array[counter][counter2] == 1)
            {
                flag = 1;
                ans = counter;
                ans2 = counter2;
                break;
            }
        }
        if(flag == 1)
            break;

    }

    ans = ans - 2;
    ans = abs(ans);
    ans2 = ans2 - 2;
    ans2 = abs(ans2);
    return ans + ans2;




}



int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
