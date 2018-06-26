#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int input[1005], array[1005], help[1005], res[1005];
char str[1005];
int n;
void fn();
void apply(int incr, int rotate);

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    fn();
    for(int i = 0; i < n; i++)
        printf("%d", res[i]);
    printf("\n");
    return 0;
}

void fn()
{
    for(int i = 0; i < n; i++)
        input[i] = str[i] - '0';

    for(int i = 0; i < n; i++)
        res[i] = input[i];

   // apply(0, 3);
    //return;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 10; j++)
            apply(j, i);

}

void apply(int incr, int rotate)
{
    for(int i = 0; i < n; i++)
        help[i] = (input[i] + incr) % 10;

    for(int i = 0; i < n; i++)
    {
        int j = (i + rotate) % n;
        array[j] = help[i];
    }

  //  for(int i = 0; i < n; i++)
   //     printf("%d", array[i]);
   // printf("\n");

    for(int i = 0; i < n; i++)
    {
        if(res[i] < array[i])
            return;
        if(res[i] > array[i])
            break;;
    }



    for(int i = 0; i < n; i++)
        res[i] = array[i];
}



