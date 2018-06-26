#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#define ll long long
using namespace std;
int small();
int big();
bool not_equal();

int s, l, array[105], array2[105];

int main()
{
    scanf("%d %d", &l, &s);
    if(small() && big())
    {
        for(int i = 0; i < l; i++)
            printf("%d", array[i]);
        printf(" ");
        for(int i = 0; i < l; i++)
            printf("%d", array2[i]);
    }
    else
        printf("-1 -1");

    return 0;
}

int small()
{
    int tmp_s = s - 1;
    if(s == 0 && l == 1)
    {
        array[0] = 0;
        return 1;
    }
    array[0] = 1;
    for(int i = 1; i < l; i++)
        array[i] = 0;
    for(int i = l - 1; i > 0 && tmp_s > 0; i--)
        array[i] = min(9, tmp_s), tmp_s -= array[i];

    if(tmp_s > 0)
        array[0] += min(8, tmp_s), tmp_s -= min(8, tmp_s);

    return (tmp_s == 0);
}

int big()
{
    int tmp_s = s;
    for(int i = 0; i < l; i++)
    {
        array2[i] = min(9, tmp_s), tmp_s -= min(9, tmp_s);
        if(i == 0 && array2[i] == 0 && l > 1)
            return 0;
    }

    return (tmp_s == 0);
}

bool not_equal()
{
    for(int i = 0; i < l; i++)
        if(array[i] != array2[i])
            return 1;
    return 0;
}
