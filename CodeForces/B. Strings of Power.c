#include <stdio.h>
#include <stdlib.h>

double noofheavy = 0;
double flag = 0;

int main()
{
    char array[999999];
    scanf("%s", array);

    simplify(array);

    printf("%.0lf", flag);

    return 0;
}

void simplify(char array[])
{
    int indicator = 0;
    int n = 0;
    int counter;
    int m = 0;
    char ref[] = "heavy";
    char ref2[] = "metal";
    char key[6];

    while(array[n] != '\0')
    {
        m = 0;
        if(array[n] == 'h')
        {
            indicator = 1;
            for(counter = n + 1; counter < n + 5; counter++)
            {
                if(array[counter] == ref[m + 1])
                    indicator++;
                else
                    break;
                m++;
            }


            if(indicator == 5)
            {

                n = n + 5;
                noofheavy++;
            }
            else
                n = n + indicator;
        }
        /////////////////////////////////////////////////////////////////////
        else
        {
            if(array[n] == 'm' && noofheavy > 0 )
            {
                indicator = 1;
                m = 0;

                for(counter = n + 1; counter < n + 5; counter++)
                {
                    if(array[counter] == ref2[m + 1])
                        indicator++;
                    else
                        break;
                    m++;
                }


                if(indicator == 5)
                {
                    n = n + 5;
                    flag = flag + noofheavy;
                }
                else
                    n = n + indicator;
            }
            else
                n++;
        }
    }

}


