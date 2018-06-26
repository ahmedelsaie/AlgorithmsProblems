#include <stdio.h>
#include <stdlib.h>

int rightway(int array[], int start, int end, int noofstations);
int leftway(int array[], int start, int end, int noofstations);

int main()
{
    int noofstations;
    int start;
    int end;
    int counter;

    scanf("%d", &noofstations);
    int array[noofstations];

    for(counter = 0; counter < noofstations; counter++)
    {
        scanf("%d", &array[counter]);
    }

    scanf("%d%d", &start, &end);

    int right;
    right = rightway(array, start, end, noofstations);
    int left = leftway(array, start, end, noofstations);

    if(right <= left)
        printf("%d", right);
    else
        printf("%d", left);
    return 0;
}

int rightway(int array[], int start, int end, int noofstations)
{
    start = start--;
    end = end--;
    int way = 0;
    while(start != end)
    {

        way = array[start] + way;
        start++;
        if(start == noofstations)
            start = 0;
    }

    return way;
}

int leftway (int array[], int start, int end, int noofstations)
{
    start = start--;
    end = end--;
    int way = 0;

    while(start != end)
    {
        if(start == 0)
            start = noofstations;

        start--;
        way = array[start] + way;
    }

    return way;
}


