#include <stdio.h>
#include <stdlib.h>

char diverge(char c);

int flag = 0;
int stop = 0;

int main()
{
    char desired[999];
    char total[999];
    scanf("%s", desired);
    scanf("%s", total);

    first_search(total, desired);
    printf("%d", flag);

    return 0;
}

void first_search(char total[], char desired[])
{
    int n = 0;
    while(total[n] != '\0' && stop == 0)
    {
        if(total[n] == desired[0]  || total[n] == diverge(desired[0])  )
        {
            total[n] = 'e';
            second_search(total, desired);
        }

        n++;
    }
}


void second_search(char total[], char desired[])
{
    int n = 1;
    int m = 0;
    int innerflag = 0;
    while(desired[n] != '\0')
    {
        m = 0;
        innerflag = 0;
        while(total[m] != '\0')
        {
            if(desired[n] == total[m] || diverge(desired[n]) == total[m])
            {
                total[m] = 'e';
                innerflag++;
                break;
            }
            m++;
        }

        if(innerflag == 0)
        {
            stop = -1;
            return;
        }
        n++;
    }

    flag++;
}

char diverge(char c)
{
    if(c == '6')
        return '9';
    else
    {
        if(c == '9')
            return '6';
        else
        {
            if(c == '5')
                return '2';
            else if(c == '2')
                return '5';
            else
                return c;
        }
    }
}
