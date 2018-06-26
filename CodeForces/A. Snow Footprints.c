#include <stdio.h>
#include <stdlib.h>

int start, end, p;

int main()
{
    char array[1000];
    scanf("%d", &p);
    scanf("%s", array);

    check(array);
    printf("%d %d", start + 1, end + 1);

    return 0;
}

void check(char array[])
{
    int n = 0;
    int r = 0;
    int l = 0;

    while(array[n] != '\0')
    {
        if(array[n] == 'R')
            r++;
        else if(array[n] == 'L')
            l++;
        n++;

    }

    ////////////////////////////////////////////////
    /////////////////////////////////////////////////
    if(r == 0)
    {
        n = 0;
        while(array[n] != '\0')
        {
            if(array[n] == 'L')
            {
                end = n - 1;
                break;
            }
            else
                n++;
        }
        n = p;
        while(n > 0)
        {
            if(array[n] == 'L')
            {
                start = n;
                break;
            }
            else
                n--;
        }
    }

////////////////////////////////////////////////////
////////////////////////////////////////////////////
    if(l == 0)
    {
        n = 0;
        while(array[n] != '\0')
        {
            if(array[n] == 'R')
            {
                start = n;
                break;
            }
            else
                n++;
        }
        n = p;
        while(n > 0)
        {
            if(array[n] == 'R')
            {
                end = n + 1;
                break;
            }
            else
                n--;
        }
    }

    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    if(r != 0 && l != 0)
    {
        n = 0;
        while(array[n] != '\0')
        {

            if (array[n] == 'R' && array[n + 1] == 'L')
            {
                end = n;

                n = 0;
                while(array[n] != '\0')
                {
                    if(array[n] != '.')
                    {
                        start = n;
                        return;
                    }
                    else
                        n++;
                }
            }
            n++;
        }
    }


}
