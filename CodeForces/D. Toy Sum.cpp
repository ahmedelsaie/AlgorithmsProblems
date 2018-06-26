#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009
#define ll long long

int taken[MAX], a[MAX], n, k = 0, ans[MAX], x;
int d1[MAX],d2[MAX];
int g = 0;
int m = 1000000;
int m2 = m - 1;

int main()
{
    memset(d2, 0, sizeof(d2));
    memset(d1, 0, sizeof(d1));

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &x), d1[x] = 1, d2[m - x] = 1;

    for(int i = 0; i <= m / 2; i++)
        g += d1[i] && d1[m - i + 1];
//printf("%d\n",g);

    for(int i = 0; i <= m; i++)
    {
        if(g && !d2[i] && !d2[m2 - i])
        {
            g--, d2[i] = d2[m2 - i] = 0;
            ans[k++] = i, ans[k++] = m2 - i;
        }
        else if(!d2[i] && d2[m2 - i])
            ans[k++] = i, d2[i] = 1;
        else if(d2[i] && !d2[m2 - i])
            ans[k++] = m2-i, d2[m2 - i] = 1;
    }

    printf("%d\n", k);

    for(int i = 0; i < k; i++)
        printf("%d ", m-ans[i]);
    printf("\n");

    return 0;
}
