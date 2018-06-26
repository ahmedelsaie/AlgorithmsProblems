#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

int arr[MAX], n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);

    int ans = 0;

    for(int i = 0; i < n - 2; i++)
    {
        int x = arr[i], y = arr[i + 1], z = arr[i + 2];

        if(x + y > z && x + z > y && y + z > x)
        {
            ans = 1;
            break;
        }
    }

    printf("%s\n", ans == 1 ? "YES" : "NO");

    return 0;
}
