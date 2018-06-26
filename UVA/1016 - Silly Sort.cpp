#include <stdio.h>
#include <cstring>

struct cycle
{
    int smallest, no, sum;
};

struct element
{
    int x, pos1, pos2;
};

void merge_sort(int start, int last, element array[]);
void merge(int start, int end, element array[]);
void merge_sort2(int start, int last, element array[]);
void merge2(int start, int end, element array[]);
void merge_sort3(int start, int last, cycle array[]);
void merge3(int start, int end, cycle array[]);
cycle comp_cycle(int i);
int min(int x, int y);
int calc(cycle x);
cycle insert(cycle x, int new_smallest);

int fn();

element input[1005];
element help[1005];

cycle array[1005];
cycle help2[1005];
bool flags[1005];
int n;

int main()
{
    int cases = 1;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &input[i].x);
            input[i].pos1 = i;
        }

        merge_sort(0, n - 1, input);

        for(int i = 0; i < n; i++)
            input[i].pos2 = i;

        merge_sort2(0, n - 1, input);

        // for(int i=0; i<n; i++)
        //     printf("%d %d %d\n",input[i].x,input[i].pos1,input[i].pos2);
//
        //  printf("in the main\n");



        printf("Case %d: %d\n\n", cases++, fn());

    }
    return 0;
}

int fn()
{
    memset(flags, true, sizeof(flags));
    int cyc = 0;

    for(int i = 0; i < n; i++)
    {
        if(flags[i])
        {
            cycle x = comp_cycle(i);
            array[cyc] = x;
            cyc++;
        }
    }

    merge_sort3(0, cyc - 1, array);
    //for(int i=0; i<cyc; i++)
    //    printf("%d %d %d\n",array[i].smallest,array[i].no,array[i].sum);


    int ret = 0;
    int tmp1, tmp2;
    ret = calc(array[0]);
    int smallest = array[0].smallest;

    for(int i = 1; i < cyc; i++)
    {
        tmp1 = calc(array[i]);
        tmp2 = calc(insert(array[i], smallest)) + smallest + array[i].smallest;
        tmp1 = min(tmp1, tmp2);
        ret += tmp1;
    }

    return ret;
}

cycle insert(cycle x, int new_smallest)
{
    x.sum += new_smallest;
    x.smallest = new_smallest;
    x.no++;
    return x;
}

int calc(cycle x)
{
    int ret = 0;
    ret = x.no - 2;
    ret = ret * x.smallest;
    ret = ret + x.sum;
    return ret;
}


cycle comp_cycle(int i)
{
    flags[i] = false;

    cycle ret;
    ret.no = 1;
    ret.smallest = input[i].x;
    ret.sum = 0;
    int curr = input[i].pos2;
    flags[curr] = false;
    ret.sum += input[i].x;

    //  printf("cycle %d ",input[i].x);

    while(curr != i)
    {
        //  printf("%d ",input[curr].x);
        flags[curr] = false;
        ret.smallest = min(ret.smallest, input[curr].x);
        ret.sum += input[curr].x;
        ret.no++;
        curr = input[curr].pos2;
    }
    //printf("\n");

    flags[curr] = false;
    return ret;
}





int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}


void merge_sort(int start, int last, element array[])
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

void merge(int start, int end, element array[])
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

        if(help[p1].x < array[p2].x)
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

void merge_sort2(int start, int last, element array[])
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort2(start, middle, array);
    merge_sort2(middle + 1, last, array);
    merge2(start, last, array);
    return;
}

void merge2(int start, int end, element array[])
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

        if(help[p1].pos1 < array[p2].pos1)
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

void merge_sort3(int start, int last, cycle array[])
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort3(start, middle, array);
    merge_sort3(middle + 1, last, array);
    merge3(start, last, array);
    return;
}

void merge3(int start, int end, cycle array[])
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help2[i] = array[i];

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
            array[main_p] = help2[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help2[p1].smallest < array[p2].smallest)
        {
            array[main_p] = help2[p1];
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


