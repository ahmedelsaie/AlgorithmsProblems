#include <stdio.h>

char array[100005];

int main()
{
    int i = 0;
    bool flag = false;
    bool zero = false;

    scanf("%s", array);
    while(array[i] != '\0')
    {
        if(array[i] == '0')
        {
            zero = true;
            break;
        }
        i++;
    }

    if(zero)
        i = 0;
    else
        i = 1;

    while(array[i] != '\0')
    {
        if(array[i] == '0' && flag == false)
        {
            flag = true;
            i++;
            continue;
        }
        printf("%c", array[i]);
        i++;
    }

    return 0;
}
