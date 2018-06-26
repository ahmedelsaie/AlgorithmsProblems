#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

double fn();
int cntbit(int mask);

char first[20], sec[20];
int l;

int main()
{
    scanf("%s %s", first, sec);
    l = strlen(first);
    printf("%.12lf\n", fn());
    return 0;
}

double fn()
{
    int f_pos = 0, f_neg = 0;
    int pos = 0, neg = 0, ques = 0;
    for(int i = 0; i < l; i++)
    {
        if(first[i] == '+')
            f_pos++;
        else
            f_neg++;

        if(sec[i] == '+')
            pos++;
        else if(sec[i] == '-')
            neg++;
        else
            ques++;
    }

    int res = f_pos - f_neg;
    double percen = 1, ret = 0;

    for(int i = 0; i < ques; i++)
        percen = percen * 0.5;

    for(int i = 0; i < (1 << ques); i++)
    {
     //   printf("%d\n", i);
        int ones = cntbit(i);
        int zeros = ques - ones;
        if(pos + ones - zeros - neg == res)
            ret += percen;
    }

    return ret;
}

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
    }
    return ret;
}
