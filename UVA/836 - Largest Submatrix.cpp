#include <stdio.h>
#include <cstring>

int trav(int start, int interval);
int max(int m1, int m2, int temp);
int to_digit(char c);

int total[10050];
int x;
const int inf = 100000;
char c[100];
int m, n;

int main()
{
    int input;
    int sum = 0;
    int r = 0;
    int total_max = -1 * inf;
    char c[1000];
    int cases;

    scanf("%d", &cases);
    getchar ();

    for(int i = 0; i < cases; i++)
    {
        sum = 0;
        x = 0;
        int h = 1;
        total[0] = 0;
        total_max = -1 * inf;
        scanf("%s", c);

        if(c[0] != '\0')
            n = strlen(c);
        m = n;
        for(int i = 0; i < n; i++)
        {
            input = to_digit(c[i]);
            sum = sum + input;
            total[h] = sum;
            h++;
        }


        for(int i = 1; i < n; i++)
        {
            scanf("%s", c);
            for(int j = 0; j < n; j++)
            {
                input = to_digit(c[j]);
                sum = sum + input;
                total[h] = sum;
                h++;
            }
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
        if(total_max == -1 * inf)
            printf("0\n");
        else
            printf("%d\n", total_max);
        if(i < cases - 1)
            printf("\n");

    }

    return 0;
}

int to_digit(char c)
{
    if(c == '1')
        return 1;

    if(c == '0')
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
