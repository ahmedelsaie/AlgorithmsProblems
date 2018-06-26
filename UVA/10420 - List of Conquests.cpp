#include <stdio.h>
#include <cstring>

struct lady
{
    char country[80];
};

void merge(int start, int end);
void merge_sort(int start, int last);
void fn(int i);

lady array[2010];
lady help[2020];
int no;
char input[80];

int main()
{
    scanf("%d", &no);

    gets(input);
    for(int i = 0; i < no; i++)
    {
        gets(input);
        fn(i);
    }

    char curr[80];
    int freq = 0;
    merge_sort(0, no - 1);
    strcpy(curr, array[0].country);

    array[no].country[0] = '\0';

    for(int i = 0; i <= no; i++)
    {
        if(strcmp(curr, array[i].country) != 0)
        {
            printf("%s %d\n", curr, freq);
            if(i == no)
                break;
            freq = 1;
            strcpy(curr, array[i].country);
        }
        else
            freq++;
    }
    return 0;
}

void fn(int i)
{
    char *first;
    first = strtok(input, " ");
    strcpy(array[i].country, first);
    return ;
}

void merge_sort(int start, int last)
{
    if(start == last)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle);
    merge_sort(middle + 1, last);
    merge(start, last);
    return;
}

void merge(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = array[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            array[main_p] = array[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            array[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(strcmp(help[p1].country, array[p2].country) < 0)
        {
            array[main_p] = help[p1];
            p1++;
        }
        else
        {
            array[main_p] = array[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

