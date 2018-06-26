#include <stdio.h>
#include <cstring>
struct block
{
    int x, y, h;
};

int max(int x, int y);
void merge(int start, int end);
void merge_sort(int start, int last);
int fn(int last, int current);
bool compare(block x, block y);

block arr[205];
block help[205];
int dp[205][205];
int n;

int main()
{
    int x, y, z, cases = 1;
    arr[200].x = 0;
    arr[200].y = 0;
    arr[200].h = 0;

    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 0; i < 6 * n; i += 6)
        {
            scanf("%d %d %d", &x, &y, &z);
            arr[i].h = x;
            arr[i].x = y;
            arr[i].y = z;

            arr[i + 1].h = x;
            arr[i + 1].y = y;
            arr[i + 1].x = z;

            arr[i + 2].x = x;
            arr[i + 2].y = y;
            arr[i + 2].h = z;

            arr[i + 3].x = x;
            arr[i + 3].h = y;
            arr[i + 3].y = z;

            arr[i + 4].y = x;
            arr[i + 4].x = y;
            arr[i + 4].h = z;

            arr[i + 5].y = x;
            arr[i + 5].h = y;
            arr[i + 5].x = z;
        }
        merge_sort(0, 6 * n - 1);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: maximum height = %d\n", cases++, fn(200, 0));
    }

    return 0;
}

int fn(int last, int current)
{
    if(current == 6 * n)
        return 0;

    int &ret = dp[last][current];
    if(ret != -1)
        return ret;

    ret = 0;
    if(arr[last].x < arr[current].x && arr[last].y < arr[current].y)
        ret = max(ret, fn(current, current + 1) + arr[current].h);

    ret = max(ret, fn(last, current + 1));

    return ret;
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
        help[i] = arr[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            arr[main_p] = arr[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            arr[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(compare(help[p1], arr[p2]))
        {
            arr[main_p] = help[p1];
            p1++;
        }
        else
        {
            arr[main_p] = arr[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

bool compare(block x, block y)
{
    if(x.x < y.x)
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
