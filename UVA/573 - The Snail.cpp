#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int fn();

int h, u, d, f;
bool flag;

int main()
{
    int ans;
    while(true)
    {
        flag = false;
        scanf("%d %d %d %d", &h, &u, &d, &f);
        if(h == 0)
            break;
        ans = fn();
        if(flag)
            printf("success on day %d\n", ans);
        else
            printf("failure on day %d\n", ans);
    }

    return 0;
}

int fn()
{
    double  position = 0;
    int days = 1;
    double  U = u;
    double decrease = U * (f * 1.0 / 100);

    while(true)
    {
        if(U >= 0)
            position += U;

        if(position > h)
            break;

        position -= (double)d;

        if(position < 0)
            break;

        U -= decrease;
        days++;
    }

    if(position < 0)
        flag = false;
    else
        flag = true;

    return days;
}


