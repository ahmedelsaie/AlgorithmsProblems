#include <stdio.h>

void intializer();
void collect_positive();
void collect_negative();
void fn();
void get_max();

int array[10050];
int p;
int m1, m2;
int stations;
int n, sum, max_nw;
int max1;

int main()
{
    scanf("%d", &stations);
    while(stations != 0)
    {
        for(int counter = 0; counter < stations; counter++)
            scanf("%d", &array[counter]);

        fn();
        get_max();

        if(max1 > 0)
            printf("The maximum winning streak is %d.", max1);

        else
            printf("Losing streak.");

        printf("\n");
        scanf("%d", &stations);
    }

    return 0;
}

void get_max()
{
    max1 = max_nw;

    if(m1 >= max1)
    {
        max1 = m1;
    }

    if(m2 >= max1)
    {
        max1 = m2;
    }
}

void fn()
{
    intializer();

    while(p < stations)
    {
        collect_negative();
        collect_positive();
        sum = m1 + m2 + n;

        if(sum >= m1)
        {
            if(sum >= max_nw)
            {
                max_nw = sum;
            }
        }
        else
        {
            if(m1 >= max_nw)
            {
                max_nw = m1;
            }
        }

        if(sum >= m2)
        {
            m1 = sum;

        }
        else
        {
            m1 = m2;

        }
    }

}

void collect_negative()
{
    n = 0;
    while(p < stations)
    {
        if(array[p] < 0)
        {
            n = n + array[p];
            p++;
        }
        else
            return;
    }
}

void collect_positive()
{
    m2 = 0;

    while(p < stations)
    {
        if(array[p] >= 0)
        {

            m2 = m2 + array[p];

            p++;
        }
        else
            return;
    }
}

void intializer()
{
    p = 0;
    max_nw = 0;
    sum = 0;
    m1 = 0;
    m2 = 0;
    max1 = 0;

    int found = 0;
    while(p < stations - 1)
    {
        if(found == 0 && array[p] < 0)
        {
            p++;
            continue;
        }

        if(array[p] >= 0)
        {

            found++;
            m1 = m1 + array[p];
            p++;
            continue;
        }

        if(array[p] < 0 && found > 0)
        {

            return;
        }
    }
}
