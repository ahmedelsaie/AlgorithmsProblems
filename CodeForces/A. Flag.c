#include <stdio.h>
#include <stdlib.h>

char flag[100][100];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    int counter, counter2;
    char x[999];
    for(counter = 0; counter < m; counter++)
    {
        scanf("%s", x);
        for(counter2 = 0; counter2 < n; counter2++)
        {
            flag[counter][counter2] = x[counter2];
        }
    }

    if(checkrows(m, n, 0) == 1 && checkcol(m, n) == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}

int checkrows(int m, int n, int no)
{
    int counter;
    for(counter = 0; counter < n - 1; counter++)
    {
        if(flag[no][counter] != flag[no][counter + 1])
            return 0;
    }
    if(no == m + 1)
        return 1;
    else
        return checkrows(m, n, no + 1);

}

int checkcol(int m, int n)
{
    int counter;

    for(counter = 0; counter < m - 1; counter++)
    {
        if(flag[counter][0] == flag[counter + 1][0])
            return 0;
    }

    return 1;
}

