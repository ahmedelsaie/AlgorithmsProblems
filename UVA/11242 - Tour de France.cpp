#include <stdio.h>

void bsort();
void fn();

int rear, front;
int teeth_f[100];
int teeth_r[100];
float result[100];
int n = 0;
float max;

int main()
{
    while(true)
    {
        scanf("%d", &front);
        if(front == 0)
            break;

        scanf("%d", &rear);

        for(int i = 0; i < front; i++)
            scanf("%d", &teeth_f[i]);

        for(int i = 0; i < rear; i++)
            scanf("%d", &teeth_r[i]);

        fn();
        printf("%.2f\n", max);
    }

}

void fn()
{
    n = 0;
    max = 0;
    for(int i = 0; i < front; i++)
        for(int j = 0; j < rear; j++)
        {
            result[n] = (float)teeth_r[j] / (float)teeth_f[i];
            n++;
        }
    bsort();
    for(int i = 0; i < n - 1; i++)
        if(result[i] / result[i + 1] > max)
            max = result[i] / result[i + 1];
}

void bsort()
{
    float swap;

    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - 1; j++)
            if(result[j] < result[j + 1])
            {
                swap = result[j];
                result[j] = result[j + 1];
                result[j + 1] = swap;
            }
}
