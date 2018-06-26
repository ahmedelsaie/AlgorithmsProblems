#include <stdio.h>

struct block
{
    int start;
    int end;
    int value;
};

int trav(int start, int interval);
int update(int start, int interval, int row);
int max(int &m1, int &m2, int &temp);
void input();

int board[155][155];
int total[10050];
int sum, total_max;
int m, n;
block m1, m2;
block temp;
const int inf = 100000000;
int prev;

int main()
{
    int cases, r;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &m);
        input();

        for(int start = 0; start < 2 * n; start++)
            for(int interval = 0; interval < n; interval++)
                if(start + interval < 2 * m)
                {
                    r = trav(start, interval);
                    if(r > total_max)
                        total_max = r;

                    int k = 2 * m + start;

                    for(int row = 1; row < n; row++)
                    {
                        r = update(k, interval, row);
                        if(r > total_max)
                            total_max = r;
                        k += 2 * m;
                    }
                }

        printf("%d\n", total_max);
    }
    return 0;
}

int trav(int start, int interval)
{
    m1.start = m1.end = m2.start = m2.end = 0;
    m1.value = m2.value = 0;
    temp.value = 0;
    block sum;

    m1.value = total[start + interval + 1] - total[start];
    m1.start = m1.end = 0;

    prev = m1.value;

    start = start + 2 * n;

    for(int row = 1; row < m; row++)
    {
        m2.value = total[start + interval + 1] - total[start];
        m2.start = m2.end = row;

        sum.value = m1.value + m2.value;
        sum.start = m1.start;
        sum.end = m2.end;

        if(sum.value < m1.value)
        {
            if(m1.value > temp.value)
                temp = m1;
        }

        if(sum.value >= m2.value)
            m1 = sum;
        else
            m1 = m2;

        start = start + 2 * n;
    }
    return max(m1.value, m2.value, temp.value);
}

int update(int start, int interval, int row)
{
    block sum;

    if(m1.start < row)
    {
        m1.value = m1.value - prev;
        m1.start++;
        if(m1.end < start)
            m1.end--;
    }

    if(temp.start < row)
    {
        temp.value = temp.value - prev;
        temp.start++;
        if(temp.end < start)
            temp.end--;
    }

    prev = total[start + interval + 1] - total[start];
    int help = start + (m - 1) * 2 * m;

    if(help >= 4 * m * m)
        m2.value = 0;
    else
        m2.value = total[help + interval + 1] - total[help];

    m2.start = m2.end = row + m - 1;
    sum.value = m1.value + m2.value;
    sum.start = m1.start;
    sum.end = m2.end;

    if(sum.value < m1.value)
    {
        if(m1.value > temp.value)
            temp = m1;
    }

    if(sum.value >= m2.value)
        m1 = sum;
    else
        m1 = m2;

    return max(m1.value, m2.value, temp.value);
}

void input()
{
    n = m;
    total[0] = 0;
    int h = 1;
    int x;
    sum = 0;
    total_max = -1 * inf;
    temp.value = 0;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &x);
            board[i][j] = x;
            board[i][j + m] = x;
            board[i + n][j] = x;
            board[i + n][j + m] = x;
        }

    for(int i = 0; i < 2 * m; i++)
        for(int j = 0; j < 2 * m; j++)
        {
            sum = sum + board[i][j];
            total[h] = sum;
            h++;
        }
}

int max(int &m1, int &m2, int &temp)
{
    int max_value = temp;

    if(max_value < m1)
        max_value = m1;

    if(max_value < m2)
        max_value = m2;

    return max_value;
}

