#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void gen(int i);
void bsort();
int n;
char arr[12];
char accum[12];
bool check[12];

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%s", arr);
        n = strlen(arr);
        bsort();
        for(int j = 0; j < n; j++)
            check[j] = true;

        gen(0);
        printf("\n");
    }
    return 0;
}

void gen(int i)
{
    char current;
    char prev = '1';

    if(i == n)
    {
        accum[i] = '\0';
        printf("%s\n",accum);
        return;
    }


    for(int j = 0; j < n; j++)
    {
        if(check[j] == true)
        {
            current = arr[j];
            if(current != prev)
            {
                accum[i] = arr[j];
                check[j] = false;
                gen(i + 1);
                check[j] = true;
                prev = current;
            }
        }
    }
}

void bsort()
{
    char swap;
    bool flag;
    for(int i = 0; i < n - 1; i++)
    {
        flag = true;
        for(int j = 0; j < n - 1; j++)
            if(arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}

