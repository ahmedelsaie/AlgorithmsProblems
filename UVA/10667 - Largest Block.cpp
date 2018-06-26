#include <stdio.h>

int trav(int start, int interval);
int max(int m1, int m2, int temp);
void reset();
void block();

int total[10050];
int m, n;
int x1, y1, x2, y2;
const int inf = 100000;
int board[105][105];

int main()
{
    int input;
    int sum = 0;
    int r = 0;
    int total_max;
    int cases;
    int blockade;
    int h;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &m);
        n = m;
        reset();
        sum = 0;
        total_max = -1 * inf;
        total[0] = 0;
        scanf("%d", &blockade);
        int h = 1;

        for(int j = 0; j < blockade; j++)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            block();
        }

        for(int j = 0; j < m; j++)
            for(int k = 0; k < m; k++)
            {
                input = board[j][k];
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

void block()
{
    x1--;
    y1--;
    x2--;
    y2--;

    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            board[i][j] = -1 * inf;

}

void reset()
{
    for(int i = 0; i < m + 1; i++)
        for(int j = 0; j < m + 1; j++)
            board[i][j] = 1;
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
