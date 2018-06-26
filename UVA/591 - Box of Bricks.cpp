#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int arr[55], n;

int main()
{
    int sum, ans, cases = 1;
    while(true)
    {
        sum = 0, ans = 0;
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]), sum += arr[i];

        sum = sum / n;
        for(int i = 0; i < n; i++)
            if(arr[i] < sum)
                ans += sum - arr[i];
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", cases++, ans);
    }

    return 0;
}
