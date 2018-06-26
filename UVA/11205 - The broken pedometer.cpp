#include <stdio.h>
#include <cstring>

struct pack
{
    int mask;
    int n;
};

void fill(int x);
int fn();
bool duplicate();
void merge(int start, int end);
void merge_sort(int start, int last);
void merge2(int start, int end);
void merge_sort2(int start, int last);
int setbit(int mask, int bit, int value);
int cntbit(int mask);
int min(int x, int y);

pack gen[40000];
pack help2[40000];
int main_symbol[105];
int new_symbol[105];
int help[105];
int symbols;
int leds;
int input[25];

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d %d", &leds, &symbols);
        for(int j = 0; j < symbols; j++)
        {
            for(int k = 0; k < leds; k++)
                scanf("%d", &input[k]);
            fill(j);
        }
        int ans = fn();
        printf("%d", ans);
        if(i < cases)
            printf("\n");
    }
    return 0;
}

int fn()
{
    int ret = 9999;
    for(int i = 0; i < (1 << leds); i++)
    {
        gen[i].mask = i;
        gen[i].n = cntbit(i);
    }
    merge_sort2(0, (1 << leds) - 1);


    for(int i = 0; i < (1 << leds); i++)
    {
        for(int j = 0; j < symbols; j++)
            new_symbol[j] = (main_symbol[j] & gen[i].mask);
        merge_sort(0, symbols - 1);
        if(duplicate())
            return gen[i].n;
    }
    return ret;
}

bool duplicate()
{
    int prev = new_symbol[0];
    for(int i = 1; i < symbols; i++)
    {
        int t = (prev ^ new_symbol[i]);
        if(t == 0)
            return false;
        prev = new_symbol[i];
    }
    return true;
}

void merge_sort2(int start, int last)
{
    if(start == last)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort2(start, middle);
    merge_sort2(middle + 1, last);
    merge2(start, last);
    return;
}

void merge2(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help2[i] = gen[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            gen[main_p] = gen[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            gen[main_p] = help2[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help2[p1].n < gen[p2].n)
        {
            gen[main_p] = help2[p1];
            p1++;
        }
        else
        {
            gen[main_p] = gen[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

void merge_sort(int start, int last)
{
    if(start == last)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle);
    merge_sort(middle + 1, last);
    merge(start, last);
    return;
}

void merge(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = new_symbol[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            new_symbol[main_p] = new_symbol[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            new_symbol[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1] < new_symbol[p2])
        {
            new_symbol[main_p] = help[p1];
            p1++;
        }
        else
        {
            new_symbol[main_p] = new_symbol[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
    }
    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

void fill(int x)
{
    int mask = 0;
    for(int i = 0; i < leds; i++)
        if(input[i])
            mask = setbit(mask, i, 1);
    main_symbol[x] = mask;
}
