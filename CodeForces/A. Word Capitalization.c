#include <stdio.h>
#include <stdlib.h>

int main()
{
    char array[9999];

    scanf("%s", array);

    array[0] = toupper(array[0]);

    printf("%s", array);

    return 0;
}
