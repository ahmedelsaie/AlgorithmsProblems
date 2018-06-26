#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
void fn(int r, int c, int left, int accum, bool dir);

int row, col, n;

int main()
{
    scanf("%d %d %d", &row, &col, &n);
    if(n > 1)
        printf("2");
    else
        printf("%d", row * col);
    fn(0, 0, n, 0, 1);

    return 0;
}

void fn(int r, int c, int left, int accum, bool dir)
{
    if(r >= row)
        return ;

    if(c >= col)
        return fn(r + 1, col - 1, left, accum, !dir);

    if(c < 0)
        return fn(r + 1, 0, left, accum, !dir);

    if(accum == 2 && left > 1)
    {
        if(left - 1 > 1)
            printf("\n2");
        else
            printf("\n%d", row * col - (2 * (n - 1)));
        return fn(r, c, left - 1, 0, dir);
    }

    printf(" %d %d", r + 1, c + 1);
    if(dir)
        return fn(r, c + 1, left, accum + 1, dir);
    else
        return fn(r, c - 1, left, accum + 1, dir);
}
