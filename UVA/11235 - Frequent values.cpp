#include <stdio.h>

struct block
{
    int start, end, val;
};

void merge_sort(int start, int last, block array[]);
void merge(int start, int end, block array[]);
void compress();
int max(int x, int y);
int fn();
int fix(int i);

int array[100009];
block comp[100009];
block help[100009];

int n, req, n_block;
int start, end;
bool flag;

int main()
{
    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        scanf("%d", &req);

        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        compress();
        merge_sort(0, n_block - 1, comp);

        for(int i = 0; i < req; i++)
        {
            scanf("%d %d", &start, &end);
            start--;
            end--;
            printf("%d\n", fn());
        }
    }
    return 0;
}

int fn()
{
    flag = false;
    int ret = 0;

    for(int i = 0; i < n_block; i++)
    {
        ret = max(fix(i), ret);
        if(fix(i) < ret && flag)
            break;
    }

    return ret;
}

int fix(int i)
{
    flag = true;
    if(comp[i].start >= start && comp[i].end <= end)
        return comp[i].val;

    flag = false;
    int delay = 0;
    if(comp[i].start < start)
        delay = start - comp[i].start;

    if(comp[i].end > end)
        delay += comp[i].end - end;

    if(comp[i].val - delay < 0)
        return 0;

    return comp[i].val - delay;
}

void compress()
{
    int accum = 0;
    int start = 0;
    int prev = array[0];
    int i;

    n_block = 0;

    for(i = 0; i < n; i++)
    {
        if(array[i] == prev)
            accum++;
        else
        {
            comp[n_block].val = accum;
            comp[n_block].start = start;
            comp[n_block].end = i - 1;

            n_block++;
            accum = 1;
            start = i;
            prev = array[i];
        }
    }

    comp[n_block].val = accum;
    comp[n_block].start = start;
    comp[n_block].end = i - 1;
    n_block++;

    return;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void merge_sort(int start, int last, block array[])
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle, array);
    merge_sort(middle + 1, last, array);
    merge(start, last, array);
    return;
}

void merge(int start, int end, block array[])
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = array[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            array[main_p] = array[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            array[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1].val > array[p2].val)
        {
            array[main_p] = help[p1];
            p1++;
        }
        else
        {
            array[main_p] = array[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}
