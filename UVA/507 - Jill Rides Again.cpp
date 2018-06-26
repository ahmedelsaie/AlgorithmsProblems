#include <stdio.h>

void intializer();
void collect_positive();
void collect_negative();
void fn();
void get_max();

int arr[20050];
int p;
int m1, m2, m1x1, m1x2, m2x1, m2x2;
int stations;
int n, sum, max_nw, max_nwx1, max_nwx2;
int lastx1, lastx2;
int cases;
int max1;
int flag = 0;


int main()
{
    scanf("%d", &cases);

    for(int counter2 = 0; counter2 < cases; counter2++)
    {
        scanf("%d", &stations);

        for(int counter = 0; counter < stations - 1; counter++)
            scanf("%d", &arr[counter]);

        fn();
        get_max();


        if(flag > 0)
            printf("The nicest part of route %d is between stops %d and %d", counter2 + 1, lastx1, lastx2);
        else
            printf("Route %d has no nice parts", counter2 + 1);


        printf("\n");
    }

    return 0;
}

void get_max()
{
    max1 = max_nw;
    lastx1 = max_nwx1;
    lastx2 = max_nwx2;

    if(m1 > max1)
    {
        lastx1 = m1x1;
        lastx2 = m1x2;
        max1 = m1;
    }

    if(m1 == max1)
    {
        if(m1x2 - m1x1 > max_nwx2 - max_nwx1)
        {
            lastx1 = m1x1;
            lastx2 = m1x2;
            max1 = m1;
        }
    }

    if(m2 > max1)
    {
        lastx1 = m2x1;
        lastx2 = m2x2;
        max1 = m2;
    }

    if(m2 == max1)
    {
        if(m2x2 - m1x1 > max_nwx2 - max_nwx1)
        {
            lastx1 = m2x1;
            lastx2 = m2x2;
            max1 = m2;
        }
    }

    lastx1++;
    lastx2++;
}

void fn()
{
    intializer();

    while(p < stations - 1)
    {
        collect_negative();
        collect_positive();
        sum = m1 + m2 + n;

        if(sum >= m1)
        {
            if(sum >= max_nw)
            {
                if(sum > max_nw)
                {
                    max_nw = sum;
                    max_nwx1 = m1x1;
                    max_nwx2 = m2x2;
                }

                if(sum == max_nw)
                {
                    if(m2x2 - m1x1 > max_nwx2 - max_nwx2)
                    {
                        max_nw = sum;
                        max_nwx1 = m1x1;
                        max_nwx2 = m2x2;
                    }
                }

            }
        }
        else
        {
            if(m1 >= max_nw)
            {
                if(m1 > max_nw)
                {
                    max_nw = m1;
                    max_nwx1 = m1x1;
                    max_nwx2 = m1x2;
                }

                if(m1 == max_nw)
                {
                    if(m1x2 - m1x1 > max_nwx2 - max_nwx2)
                    {
                        max_nw = m1;
                        max_nwx1 = m1x1;
                        max_nwx2 = m1x2;
                    }
                }

            }
        }

        if(sum >= m2)
        {
            m1 = sum;
            m1x2 = m2x2;
        }
        else
        {
            m1 = m2;
            m1x1 = m2x1;
            m1x2 = m2x2;
        }
    }

}

void collect_negative()
{
    n = 0;
    while(p < stations - 1)
    {
        if(arr[p] < 0)
        {
            n = n + arr[p];
            p++;
        }
        else
            return;
    }
}

void collect_positive()
{
    m2 = 0;
    m2x1 = p;
    while(p < stations - 1)
    {
        if(arr[p] >= 0)
        {
            flag++;
            m2 = m2 + arr[p];
            m2x2 = p + 1;
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
    flag = 0;
    int found = 0;

    while(p < stations - 1)
    {
        if(found == 0 && arr[p] < 0)
        {
            p++;
            continue;
        }

        if(arr[p] >= 0)
        {
            if(found == 0)
                m1x1 = p;


            flag++;
            m1x2 = p + 1;
            found++;
            m1 = m1 + arr[p];
            p++;
            continue;
        }

        if(arr[p] < 0 && found > 0)
        {
            return;
        }
    }
}
