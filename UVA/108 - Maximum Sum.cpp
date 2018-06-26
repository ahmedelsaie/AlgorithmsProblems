#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int trav(int start, int interval);
int max(int m1, int m2, int temp);

int total[10050];
int m, n;
const int inf = 100000000;

int main()
{
    int input;
    int sum = 0;
    int r = 0;
    int total_max;

    while(scanf("%d", &m) != EOF)
    {
        sum = 0;
        n = m;
        total_max = -1 * inf;

        total[0] = 0;
        for(int i = 1; i <= m * n; i++)
        {
            scanf("%d", &input);
            sum = sum + input;
            total[i] = sum;
        }

        for(int start = 0; start < n; start++)
        {
            for(int interval = 0; interval + start < n; interval++)
            {
                r = trav(start, interval);
                if(r > total_max)
                    total_max = r;
            }
        }
        printf("%d\n", total_max);
    }
    return 0;
}

int trav(int start, int interval)
{
    int sum, m1 = 0, m2 = 0, temp = -1 * inf;

    m1 = total[start + interval + 1] - total[start];
    start = start + n;

    for(int row = 1; row < m; row++)
    {
        m2 = total[start + interval + 1] - total[start];

        sum = m1 + m2;
        if(sum < m1)
        {
            if(m1 > temp)
                temp = m1;
        }

        if(sum >= m2)
            m1 = sum;
        else
            m1 = m2;

        start = start + n;
    }
    return max(m1, m2, temp);
}

int max(int m1, int m2, int temp)
{
    int max_value = temp;

    if(max_value < m1)
        max_value = m1;

    if(max_value < m2)
        max_value = m2;

    return max_value;
}

