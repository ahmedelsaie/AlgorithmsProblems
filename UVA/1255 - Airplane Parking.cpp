#include <stdio.h>
#include <cstring>

struct time
{
    int arr, depart;
};
time array[350];

time help[350];
void merge_sort(int start, int last);
void merge(int start, int end);
bool compare(time x, time y);
int get(int current, int last_time);
int fn(int bigger, int current);
int max(int x, int y);

int dp[305][305];
int n;
const int inf = 9999999;

int main()
{
    array[302].depart = 2147483647;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &array[i].arr, &array[i].depart);
        memset(dp, -1, sizeof(dp));
        merge_sort(0, n - 1);

        printf("%d\n", fn(302, 0));
    }

    return 0;
}

int fn(int bigger, int current)
{
    if(current >= n)
        return 0;

    int &ret = dp[bigger][current];
    if(ret != -1)
        return ret;

    ret = -1 * inf;
    ret = max(ret, fn(bigger, current + 1));

    if(array[current].depart <= array[bigger].depart)
    {
        int t = get(current, array[current].depart);
        ret = max(ret, fn(current, current + 1) + 1 + fn(bigger, t));
    }

    return ret;
}

int get(int current, int last_time)
{
    for(int i = current + 1; i < n; i++)
        if(array[i].arr >= last_time)
            return i;
    return 9999999;
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

        if(compare(help[p1], array[p2]))
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

bool compare(time x, time y)
{
    if(x.arr < y.arr)
        return true;

    if(x.arr > y.arr)
        return false;

    if(x.depart > y.depart)
        return true;

    return false;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
