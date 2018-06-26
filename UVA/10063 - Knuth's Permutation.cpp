#include <stdio.h>
#include <cstring>

void rotate(int x);
void swap(int x, int y);
void fn(int i);

char work[20];
int l;

int main()
{
    bool check = false;
    while(scanf("%s", work) != EOF)
    {
        if (check)
            printf("\n");
        else
            check = true;

        l = strlen(work);
        fn(0);
    }
    return 0;
}

void fn(int i)
{
    if(i == l)
    {
        printf("%s\n", work);
        return ;
    }
    rotate(i);
    fn(i + 1);

    for(int j = 0; j < i; j++)
    {
        swap(j, j + 1);
        fn(i + 1);
    }
    return ;
}

void rotate(int x)
{
    char c = work[x];
    for(int i = x; i >= 1; i--)
        work[i] = work[i - 1];
    work[0] = c;
}

void swap(int x, int y)
{
    char help = work[x];
    work[x] = work[y];
    work[y] = help;
    return;
}
