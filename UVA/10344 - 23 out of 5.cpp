#include <stdio.h>

void fn(int i, int result);
void gen(int i);

int n = 5;
int accum[6];
bool check[6];
int array[6];
bool flag;

int main()
{
    for(int i = 0; i < 6; i++)
        check[i] = true;
    while(true)
    {
        flag = false;

        for(int i = 0; i < 5; i++)
            scanf("%d", &array[i]);

        if(array[0] == 0 && array[1] == 0 && array[2] == 0 && array[3] == 0 && array[4] == 0)
            break;

        gen(0);

        if(flag)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}

void fn(int i, int result)
{
    if(i == 5)
    {
        if(result == 23)
            flag = true;
        return ;
    }

    fn(i + 1, result + accum[i + 1]);
    fn(i + 1, result - accum[i + 1]);
    fn(i + 1, result * accum[i + 1]);

    return;
}

void gen(int i)
{
    int current;
    int prev = -1;

    if(i == n)
    {
        fn(0, accum[0]);
        return;
    }

    for(int j = 0; j < n; j++)
    {
        if(flag)
            return;
        if(check[j] == true)
        {
            current = array[j];
            if(current != prev)
            {
                accum[i] = array[j];
                check[j] = false;
                gen(i + 1);
                check[j] = true;
                prev = current;
            }
        }
    }
    return ;
}
