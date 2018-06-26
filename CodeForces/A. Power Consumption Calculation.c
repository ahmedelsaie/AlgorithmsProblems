#include <stdio.h>
#include <stdlib.h>

struct period
{
    int start;
    int end;
};

struct period shift[1000];

int calcu(int n, int p1, int p2, int p3, int t1, int t2);

int main()
{
    int n, p1, p2, p3, t1, t2;
    int counter;

    scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);

    for(counter = 0; counter < n; counter++)
    {
        scanf("%d %d", &shift[counter].start, &shift[counter].end);
    }

    printf("%d", calcu(n, p1, p2, p3, t1, t2));

    return 0;
}

int calcu(int n, int p1, int p2, int p3, int t1, int t2)
{
    int bet = 0;
    int bet2 = 0;
    int total = 0;
    int counter;

    for(counter = 0; counter < n; counter++)
    {
        if(counter == n - 1)
            total = total + ((shift[counter].end - shift[counter].start) * p1);
        else
        {
            total = total + ((shift[counter].end - shift[counter].start) * p1);
            bet = shift[counter + 1].start - shift[counter].end;
            bet = bet - t1;
            if(bet > 0)
            {
                bet2 = bet - t2;
                if(bet2 > 0)
                {
                    total = total + bet2 * p3;
                    total = total + t2 * p2;
                    total = total + t1 * p1;
                }
                else
                {
                    total = total + bet * p2;
                    total = total + t1 * p1;
                }
            }
            else
            {
                bet = shift[counter + 1].start - shift[counter].end;
                total = total + bet * p1;
            }
        }
    }

    return total;
}
