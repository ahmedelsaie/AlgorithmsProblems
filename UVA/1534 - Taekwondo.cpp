#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

void merge_sort(int start, int last, double arr[], int num);
void merge(int start, int end1, double arr[], int num);
double fn(int x, int y);

const double inf = 0x3f3f3f3f ;
double help[600];
double a[600];
double b[600];
int a_num, b_num;
double dp[505][505];
bool  visited[505][505];

int main()
{
    int cases;
    bool switch1;
    scanf("%d", &cases);
    while(cases--)
    {
        switch1 = false;
        scanf("%d %d", &a_num, &b_num);
        if(a_num > b_num)
        {
            int swap = a_num;
            a_num = b_num;
            b_num = swap;
            switch1 = true;
        }

        if(switch1)
        {
            for(int i = 0; i < b_num; i++)
                scanf("%lf", &b[i]);

            for(int i = 0; i < a_num; i++)
                scanf("%lf", &a[i]);
        }
        else
        {
            for(int i = 0; i < a_num; i++)
                scanf("%lf", &a[i]);

            for(int i = 0; i < b_num; i++)
                scanf("%lf", &b[i]);
        }
        merge_sort(0, a_num - 1, a, a_num);
        merge_sort(0, b_num - 1, b, b_num);
        memset(visited, false, sizeof(visited));
        printf("%.1lf", fn(0, 0));
        printf("\n");

    }
    return 0;
}

double fn(int x, int y)
{
    if(x == a_num)
        return 0;

    if(y == b_num)
        return inf;

    double &ret = dp[x][y];
    bool &flag = visited[x][y];
    if(flag)
        return ret;
    flag = true;
    ret = inf;

    ret = min(ret, fn(x + 1, y + 1) + fabs(a[x] - b[y]));

    ret = min(ret, fn(x, y + 1));

    return ret;
}

void merge_sort(int start, int last, double arr[], int num)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle, arr, num);
    merge_sort(middle + 1, last, arr, num);
    merge(start, last, arr, num);
    return;
}

void merge(int start, int end1, double arr[], int num)
{
    int middle = (end1 - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = arr[i];

    while(main_p <= end1)
    {
        if(p1 > middle)
        {
            arr[main_p] = arr[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end1)
        {
            arr[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1] > arr[p2])
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
