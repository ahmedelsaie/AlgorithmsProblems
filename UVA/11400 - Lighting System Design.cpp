#include <stdio.h>
#include <cstring>
#define type long long

struct cat
{
    int lamp_cost, power_cost, n, v;
};

type min(type x, type y);
type fn(int last, int current);
void build_accum();
int get(int first, int last);
void merge_sort(int start, int last);
void merge(int start, int end);
void reset();

cat all[1005];
cat help[1005];
int accum[1005];
type dp[1005][1005];
int n;
const int inf = 9999999999;

int main()
{
    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 1; i <= n; i++)
            scanf("%d %d %d %d", &all[i].v, &all[i].power_cost, &all[i].lamp_cost, &all[i].n);

        merge_sort(1, n);
        build_accum();
        n++;
        //memset(dp,-1,sizeof(dp));
        reset();
        printf("%lld\n", fn(1, 1));
    }

    return 0;
}

type fn(int last, int current)
{
    if(current == n)
    {
        if(last == n)
            return 0;
        return inf;
    }
    type &ret = dp[last][current];
    if(ret != -1)
        return ret;
    ret = inf;

    type cost = get(last, current) * all[current].lamp_cost + all[current].power_cost;

    ret = min(ret, fn(last, current + 1));
    ret = min(ret, fn(current + 1, current + 1) + cost);

    return ret;
}

void build_accum()
{
    accum[0] = 0;
    int total = 0;
    for(int i = 1; i <= n; i++)
    {
        total += all[i].n;
        accum[i] = total;
    }
    return;
}

int get(int first, int last)
{
    return accum[last] - accum[first - 1];
}

type min(type x, type y)
{
    if(x < y)
        return x;
    else
        return y;
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
        help[i] = all[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            all[main_p] = all[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            all[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1].v < all[p2].v)
        {
            all[main_p] = help[p1];
            p1++;
        }
        else
        {
            all[main_p] = all[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

void reset()
{
    for(int i = 0; i < n + 2; i++)
        for(int j = 0; j < n + 2; j++)
            dp[i][j] = -1;
}

