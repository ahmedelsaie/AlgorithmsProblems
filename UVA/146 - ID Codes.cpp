#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

bool fn();
void bsort(int start);

char arr[51];
int length;

int main()
{
    while(true)
    {
        scanf("%s", arr);
        length = strlen(arr);
        if(arr[0] == '#')
            break;

        if(fn())
            printf("%s\n", arr);
        else
            printf("No Successor\n");
    }

    return 0;
}

bool fn()
{
    for(int j = length - 1; j > 0; j--)
        for(int i = j; i >= 0; i--)
        {
            if(arr[i] < arr[j])
            {
                char swap = arr[j];
                arr[j] = arr[i];
                arr[i] = swap;
                bsort(i + 1);
                return true;
            }
        }

    return false;
}

void bsort(int start)
{
    char swap;
    int counter, counter2;
    for(counter = start; counter < length - 1; counter++)
        for(counter2 = start; counter2 < length - 1; counter2++)
            if(arr[counter2] > arr[counter2 + 1])
            {
                swap = arr[counter2];
                arr[counter2] = arr[counter2 + 1];
                arr[counter2 + 1] = swap;
            }

}
