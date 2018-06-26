#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 200009
void fn();

char input[MAX];
pair<char, int> array[MAX];
int n;

int main()
{
    scanf("%s", input);
    n = strlen(input);
    fn();
    printf("\n");
    return 0;
}

void fn()
{
    int i = 0, accum = 0, total_accum = 0, j = 0;
    char prev = input[0];

    ///compress
    while(i < n)
    {
        if(input[i] == prev)
            accum++;
        else
        {
            array[j].first = prev;
            if(accum > 2)
                array[j].second = 2;
            else
                array[j].second = accum;
            j++;
            accum = 1;
            prev = input[i];
        }
        i++;
    }
    array[j].first = prev;
    if(accum > 2)
        array[j].second = 2;
    else
        array[j].second = accum;
    j++;

    ///check
    i = 0;
    while(i < j)
    {
        if(array[i].second < 2 || i == j - 1)
        {
            if(array[i].second == 2)
            {
                bool c = 0;
                for(int k = i - total_accum; k <= i; k++)
                {
                    if(c)
                        printf("%c", array[k].first);
                    else
                        printf("%c%c", array[k].first, array[k].first);
                    c = !c;
                }
            }
            else
            {
                bool c = 0;
                for(int k = i - total_accum; k < i; k++)
                {
                    if(c)
                        printf("%c", array[k].first);
                    else
                        printf("%c%c", array[k].first, array[k].first);
                    c = !c;
                }
                printf("%c", array[i].first);
            }

            total_accum = 0;
        }
        else
            total_accum++;
        i++;
    }

    return ;
}
