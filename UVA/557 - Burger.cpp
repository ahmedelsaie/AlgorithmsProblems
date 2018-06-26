#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long
#define type double

void inti();

type arr[MAX];
int n, cases;

int main()
{
    inti();

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        printf("%.4lf\n", n == 2 ? 0 : 1 - arr[n - 2]);
    }

    return 0;
}

void inti()
{
    arr[2] = .5;
    for(int i = 4; i <= 100000; i += 2)
    {
        type tmp1 = i * .25;
        tmp1 = tmp1 / (i / 2) * (i - 1);
        tmp1 = tmp1 / (i / 2);
        arr[i] = arr[i - 2] * tmp1;
    }
}


