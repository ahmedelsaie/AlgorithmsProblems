#include <bits/stdc++.h>
using namespace std;
#define MAX 3000009
#define ll long long

int fn();

int arr[MAX], sum[MAX], n, big = 0, k;

int main()
{
    memset(arr, 0, sizeof(arr));

    scanf("%d %d", &n, &k);
    for(int i = 0, x; i < n; i++)
        scanf("%d", &x), arr[x]++, big = max(big, x);

    sum[0] = 0;
    for(int i = 1; i <= big * 2; i++)
        sum[i] = sum[i - 1] + arr[i];

    printf("%d\n", fn());

    return 0;
}

int fn()
{
    int ret = 1;

    for(int i = 1; i <= big; i++)
    {
      //  i = 3;
        int flag = 1;
        int prev = min(k, i - 1);

        if(sum[i - 1])
            continue;
        //printf("%d\n",i);

        for(int j = i; j <= big + i; j += i, prev += i)
        {
          //  printf("%d %d\n", j, sum[j - 1] - sum[prev] );
            if(sum[j - 1] - sum[prev] != 0)
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1)
            ret = max(ret, i);

       // break;
    }

    return ret;
}
