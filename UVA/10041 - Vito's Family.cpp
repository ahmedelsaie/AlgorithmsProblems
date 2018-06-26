#include <stdio.h>
int dist(int house);
int min(int x, int y);
int max(int x, int y);
void merge_sort(int start, int last);
void merge(int start, int end);
int abs(int x);
void fn();
const int inf = 9999999;
int no_rel;
int rel[505];
int help[505];
int min_rel, max_rel;
int ans;

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        max_rel = -1 * inf;
        min_rel = inf;
        scanf("%d", &no_rel);
        for(int j = 0; j < no_rel; j++)
        {
            scanf("%d", &rel[j]);
            min_rel = min(min_rel, rel[j]);
            max_rel = max(max_rel, rel[j]);
        }
        merge_sort(0, no_rel - 1);
        fn();
        printf("%d\n", ans);
    }
    return 0;
}

void fn()
{
    ans = inf;
    int temp;
    for(int i = rel[no_rel / 2]; i <= max_rel; i++)
    {
        temp = dist(i);
        if(temp >= ans)
            break;
        else
            ans = temp;
    }

    for(int i = rel[no_rel / 2]; i >= min_rel; i--)
    {
        temp = dist(i);
        if(temp >= ans)
            return;
        else
            ans = temp;
    }
}

int dist(int house)
{
    int ret = 0;
    for(int i = 0; i < no_rel; i++)
    {
        ret += abs(house - rel[i]);
        if(ret >= ans)
            break;
    }
    return ret;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
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
        help[i] = rel[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            rel[main_p] = rel[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            rel[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1] < rel[p2])
        {
            rel[main_p] = help[p1];
            p1++;
        }
        else
        {
            rel[main_p] = rel[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

