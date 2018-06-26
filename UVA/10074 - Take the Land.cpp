#include <stdio.h>
#include <cstring>

int trav(int start, int interval);
int max(int m1, int m2, int temp);
int to_digit(int c);

int total[10050];
int x;
const int inf = 1000;
char c[100];

int m, n;

int main()
{
    int input;
    int sum = 0;
    int total_max = -1 * inf;
    int r;

    while(true)
    {
        sum = 0;
        x = 0;
        int h = 1;
        total[0] = 0;
        total_max = -1 * inf;

        scanf("%d %d", &m, &n);

        if(m == 0 && n == 0)
            break;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &input);
                input = to_digit(input);
                sum = sum + input;
                total[h] = sum;
                h++;
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
        if(total_max <= 0)
            printf("0\n");
        else
            printf("%d\n", total_max);
    }
    return 0;
}

int to_digit(int c)
{
    if(c == 0)
        return 1;

    if(c == 1)
        return -1 * inf;

    return -1;
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

