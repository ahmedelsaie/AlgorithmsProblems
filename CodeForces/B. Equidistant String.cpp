#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 100009

char input[MAX];
int arr1[MAX], arr2[MAX], n, diff;

int main()
{
    scanf("%s", input);
    n = strlen(input);
    for(int i = 0; i < n; i++)
        arr1[i] = input[i] - '0';

    scanf("%s", input);
    for(int i = 0; i < n; i++)
        arr2[i] = input[i] - '0';

    diff = 0;
    for(int i = 0; i < n; i++)
        if(arr1[i] != arr2[i])
            diff++;

    if(diff % 2 != 0)
        printf("impossible\n");
    else
    {
        int first = 0, i = 0;

        while(i < n)
        {
            if(arr1[i] == arr2[i])
                printf("%d", arr1[i]);
            else
            {
                if(first < diff / 2)
                    printf("%d", !arr1[i]), first++;
                else
                    printf("%d", !arr2[i]);
            }

            i++;
        }
        printf("\n");
    }

    return 0;
}
