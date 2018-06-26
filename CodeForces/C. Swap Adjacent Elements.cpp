#include <bits/stdc++.h>
using namespace std;
#define MAX 200009
#define ll long long

int fn();

int n, sum[MAX], arr[MAX], can[MAX];
char input[MAX];

int main()
{
    memset(can, 0, sizeof(can));
    memset(sum, 0, sizeof(sum));

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    scanf("%s", input);

    for(int i = 1; i < n; i++)
        if(input[i - 1] == '0')
            can[i] = 0;
        else
            can[i] = 1;

    printf("%s\n", fn() == 1 ? "YES" : "NO");

    return 0;
}

int fn()
{
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + can[i];


    for(int i = 1; i <= n; i++)
    {
        int x = arr[i];
        int s = sum[x-1] - sum[i - 1];

        if(s < x - i)
            return 0;
    }

    return 1;
}
