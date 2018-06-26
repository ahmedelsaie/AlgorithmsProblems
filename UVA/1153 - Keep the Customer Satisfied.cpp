#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 1000009

int fn();

priority_queue<ll> q;
pair<ll, ll> array[MAX];
int n, tc;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lld %lld", &array[i].second, &array[i].first);
        printf("%d\n", fn());

        if(tc)
            printf("\n");
    }

    return 0;
}

int fn()
{
    ///first days sec tons
    int ret = 0, i = 0;
    ll left = 0, prev = 0;
    sort(array, array + n);

    while(q.empty() == 0)
        q.pop();

    while(i < n)
    {
        left += array[i].first - prev;

        if(left >= array[i].second)
            left -= array[i].second, q.push(array[i].second), ret++;
        else if(q.empty() == 0)
        {
            if(left + q.top() >= array[i].second && array[i].second < q.top())
            {
                left -= array[i].second;
                left += q.top();
                q.pop();
                q.push(array[i].second);
            }
        }

        prev = array[i].first, i++;
    }

    return ret;

}
