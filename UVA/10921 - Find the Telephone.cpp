#include <stdio.h>
#include <cstring>

int convert(char x);

char input[35];

int main()
{
    int l;
    bool flag = true;
    while(gets(input))
    {
        l = strlen(input);

        for(int i = 0; i < l; i++)
        {
            if(input[i] == '-')
                printf("-");
            else
                printf("%d", convert(input[i]));
        }
        printf("\n");
    }
    return 0;
}

int convert(char x)
{
    if(x == '1')
        return 1;

    if(x == '0')
        return 0;

    if(x == 'A' || x == 'B' || x == 'C')
        return 2;

    if(x == 'D' || x == 'E' || x == 'F')
        return 3;

    if(x == 'G' || x == 'H' || x == 'I')
        return 4;

    if(x == 'J' || x == 'K' || x == 'L')
        return 5;

    if(x == 'M' || x == 'N' || x == 'O')
        return 6;

    if(x == 'P' || x == 'Q' || x == 'R' || x == 'S')
        return 7;

    if(x == 'T' || x == 'U' || x == 'V')
        return 8;

    if(x == 'W' || x == 'X' || x == 'Y' || x == 'Z')
        return 9;
}
