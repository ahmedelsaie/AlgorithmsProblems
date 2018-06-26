#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int get(int i, int j);
void process();
int fn();

int array[4][1005], n, l, ans, cases;
char input[1005];
char indx[] = {'A', 'C', 'G', 'T'};

int main()
{
    ///A C G T
    scanf("%d", &cases);
    while(cases--)
    {
        memset(array, 0, sizeof(array));

        scanf("%d %d", &n, &l);
        for(int i = 0; i < n; i++)
            scanf("%s", input), process();

        ans = fn();
        printf("%s\n%d\n", input, ans);
    }

    return 0;
}

int fn()
{
    int ret = 0, tmp, h, t;
    for(int i = 0; i < l; i++)
    {
        tmp = 99999999;
        for(int j = 0; j < 4; j++)
        {
            int h = get(i, j);
            if(h < tmp)
                tmp = h, t = j;
        }

        input[i] = indx[t];
        ret += tmp;
    }

    return ret;
}

int get(int i, int j)
{
    int ret = 0;
    for(int k = 0; k < 4; k++)
        if(k != j)
            ret += array[k][i];
    return ret;
}

void process()
{
    int tmp;
    for(int i = 0; i < l; i++)
    {
        ///A C G T
        switch (input[i])
        {
        case'A':
            tmp = 0;
            break;
        case'C':
            tmp = 1;
            break;
        case'G':
            tmp = 2;
            break;
        case'T':
            tmp = 3;
            break;
        }
        array[tmp][i]++;
    }
}
