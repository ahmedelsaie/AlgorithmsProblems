#include <iostream>
#include <stdio.h>
using namespace std;

int array[100009];
int n, k;
void fn();

int main()
{
    scanf("%d %d", &n, &k);

    fn();

    for(int i = 1; i <= n; i++)
    {
        if(i > 1)
            printf(" ");
        printf("%d", array[i]);
    }
    return 0;
}

void fn()
{
    int indx = 1;
    int low, high;

    k--;
    if(k % 2 == 0)
    {
        low = 1, high = n;
        while(k)
        {
            array[indx] = low, array[indx + 1] = high;
            low += 1, high -= 1;
            indx += 2, k -= 2;
        }
    }
    else
    {
        low = 1, high = n;
        k++;
        while(k)
        {
            array[indx + 1] = low, array[indx] = high;
            low += 1, high -= 1;
            indx += 2, k -= 2;
        }
    }

    for(int i = low; i <= high; i++)
        array[indx] = i, indx++;
    return;
}
