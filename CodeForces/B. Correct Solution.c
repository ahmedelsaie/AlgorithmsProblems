#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no;
    char array[99];
    char ans[99];

    scanf("%s", array);
    scanf("%s", ans);

    no = count(array);
    bsort(array, no);
    check(array, no);

    if(strcmp(array, ans) == 0)
        printf("OK");
    else
        printf("WRONG_ANSWER");

    return 0;
}

void check(char array[], int no)
{
    int n = 1;
    if(no > 1)
    {
        if(array[0] == '0')
        {
            while(array[n] != '\0')
            {
                if(array[n] != '0')
                {
                    array[0] = array[n];
                    array[n] = '0';
                    break;
                }
                n++;
            }
        }
    }
}

int count(char array[])
{
    int n = 0;
    while(array[n] != '\0')
        n++;

    return n;
}

void bsort(char array[], int index)
{
    char swap;
    int counter, counter2;

    for(counter = 0; counter < index - 1; counter++)
        for(counter2 = 0; counter2 < index - 1; counter2++)
            if(array[counter2] > array[counter2 + 1])
            {
                swap = array[counter2];
                array[counter2] = array[counter2 + 1];
                array[counter2 + 1] = swap;
            }
}

