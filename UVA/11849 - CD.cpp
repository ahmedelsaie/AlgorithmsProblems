#include <stdio.h>

int fn();

int jack[1000000];
int Jill[1000000];
int Jack_cds;
int Jill_cds;

int main()
{
    int input;
    while(true)
    {
        scanf("%d %d", &Jack_cds, &Jill_cds);
        if(Jack_cds == 0 && Jill_cds == 0)
            break;

        for(int i = 0; i < Jack_cds; i++)
        {
            scanf("%d", &input);
            jack[i] = input;
        }

        for(int i = 0; i < Jill_cds; i++)
        {
            scanf("%d", &input);
            Jill[i] = input;
        }
        printf("%d\n", fn());
    }

    return 0;
}

int fn()
{
    int ans = 0;
    int first, second;
    int j = 0;

    for(int i = 0; i < Jill_cds && j < Jack_cds;)
    {
        first = jack[i];
        second = Jill[j];
        if(first == second)
        {
            i++;
            j++;
            ans++;
            continue;
        }

        if(first > second)
        {
            j++;
            continue;
        }
        else
        {
            i++;
            continue;
        }
    }
    return ans;
}



