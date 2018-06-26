#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int row, col;
char input[105][105];
bool check_update(int array[], int col);
int apply(int first);
int fn();

int main()
{
    scanf("%d %d", &row, &col);
    for(int i = 0; i < row; i++)
        scanf("%s", input[i]);

    printf("%d\n", fn());
    return 0;
}

int fn()
{
    int ret = col;
     for(int i = 0; i < col; i++)
    ret = min(ret, apply(i) + i);
   // printf("%d test", apply(1));
   // ret = min(ret, apply(1) + 1);
    return ret;
}

int apply(int first)
{
    int array[105], ret = 0;
    memset(array, 0, sizeof(array));
    array[row - 1] = 1;


    for(int j = first; j < col; j++)
    {
        if(!check_update(array, j))
            ret++;
    }

   // for(int i = 0; i < row - 1; i++)
     //   printf("%d ", array[i]);


 //   for(int i = 0; i < row - 1; i++)
     //   if(array[i] == 0)
         //   return 9999999;
    return ret;
}

bool check_update(int array[], int col)
{
    for(int i = 0; i < row - 1; i++)
    {
        if(array[i] == 0 && input[i][col] > input[i + 1][col])
            return 0;
    }

    for(int i = 0; i < row - 1; i++)
    {
        if(array[i] == 0 && input[i][col] < input[i + 1][col])
            array[i] = 1;
    }

    return 1;
}
