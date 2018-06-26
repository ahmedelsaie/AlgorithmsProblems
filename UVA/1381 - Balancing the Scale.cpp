#include <stdio.h>
#include <cstring>
#define MAX 16

struct block
{
    int mask, sum;
};

///FUCNTIONS
int setbit(int mask, int bit, int value);
int make_mask(int i, int j, int k, int l);
int get_sum(int x, int i, int j, int k, int l);
void merge_sort(int start, int last);
void merge(int start, int end);
void get(int index);
void gen(int i);
int fn();

///ARRAYS
block array[43680];
block help[43680];
int input[16];
int perm[24][4];
int accum[4];
bool check[4];
int arr[65536];

///VARIABLES
int idx, ans, cases = 1;

int main()
{
    idx = 0;
    memset(check, true, sizeof(check));
    gen(0);

    while(true)
    {
        scanf("%d", &input[0]);

        if(input[0] == 0)
            break;

        for(int i = 1; i < MAX; i++)
            scanf("%d", &input[i]);

        ans = fn();
        printf("Case %d: %d\n", cases++, ans);
    }

    return 0;
}

int fn()
{
    int ret = 0, sum;
    idx = 0;
    block tmp;

    for(int i = 0; i < MAX; i++)
        for(int j = i + 1; j < MAX; j++)
            for(int k = j + 1; k < MAX; k++)
                for(int l = k + 1; l < MAX; l++)
                {
                    tmp.mask = make_mask(i, j, k, l);

                    for(int x = 0; x < 24; x++)
                    {
                        tmp.sum = get_sum(x, i, j, k, l);
                        array[idx] = tmp;
                        idx++;
                    }
                }

    merge_sort(0, idx - 1);
    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < 43680; i++)
        get(i);

    for(int i = 0; i < 65536; i++)
    {
        int correct = 65536 - 1;
        int new_mask = ~ i;
        new_mask = new_mask & correct;

        if(new_mask > i)
            ret += arr[i] * arr[new_mask];
    }

    return ret;
}

void get(int index)
{
    int mask = array[index].mask;
    int sum = array[index].sum;
    int i = index + 1;

    while(i < 43680 && array[i].sum == sum)
    {
        if( (mask & array[i].mask) == 0)
            arr[mask | array[i].mask]++;
        i++;
    }

    return ;
}

int get_sum(int x, int i, int j, int k, int l)
{
    int sum = 0;
    int coff = 4;
    int tmp[4];

    tmp[0] = input[i];
    tmp[1] = input[j];
    tmp[2] = input[k];
    tmp[3] = input[l];

    for(int d = 0; d < 4; d++)
    {
        int a = perm[x][d];
        sum += coff * tmp[a];
        coff--;
    }

    return sum;
}

int make_mask(int i, int j, int k, int l)
{
    int mask = 0;
    mask = setbit(mask, i, 1);
    mask = setbit(mask, j, 1);
    mask = setbit(mask, k, 1);
    mask = setbit(mask, l, 1);
    return mask;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return (mask | (1 << bit));
    else
        return (mask & ~ (1 << bit));
}

void gen(int i)
{
    if(i == 4)
    {
        for(int j = 0; j < 4 ; j++ )
            perm[idx][j] = accum[j];
        idx++;
        return;
    }

    for(int j = 0; j < 4; j++)
    {
        if(check[j] == true)
        {
            accum[i] = j;
            check[j] = false;
            gen(i + 1);
            check[j] = true;
        }
    }
    return ;
}

void merge_sort(int start, int last)
{
    if(last <= start)
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

        if(help[p1].sum < array[p2].sum)
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
