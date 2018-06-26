#include <stdio.h>
void draw_row(int diam);
void fn();

int n;

int main()
{
    scanf("%d",&n);
    fn();
    return 0;
}

void fn()
{
    for(int i=1; i<=n; i+=2)
    {
        draw_row(i);
        printf("\n");
    }

    for(int i=n-2; i>=1; i-=2)
    {
        draw_row(i);
        printf("\n");
    }
    return ;
}

void draw_row(int diam)
{
    for(int i=0; i<(n-diam)/2; i++)
        printf("*");

    for(int i=0; i<diam; i++)
        printf("D");

    for(int i=0; i<(n-diam)/2; i++)
        printf("*");

    return ;
}
