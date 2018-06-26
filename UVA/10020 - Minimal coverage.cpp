#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define MAX 100000

struct seg
{
    int start, end1;
};

seg arr[MAX];
seg help[MAX];
seg ans[MAX];

int end1;
int n;

template <typename type>
void merge_sort(int start, int last, type arr, type swap);
bool comp(seg& i, seg& j);
int get_last(int i);
void fn();
int zero();
int before_zero();
int get(int i, int curr_end1);

int main()
{
    int x, y, cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &end1);
        n = 0;

        while(true)
        {
            scanf("%d %d", &x, &y);
            if(x == 0 && y == 0)
                break;
            arr[n].start = x;
            arr[n].end1 = y;
            n++;
        }

        fn();
        printf("\n");
        if(cases)
            printf("\n");

    }
    return 0;
}

void fn()
{
    merge_sort(0, n - 1, arr, help);
    int a = 0;
    int i = 0;
    int curr_end1 = 0;

    while(true)
    {
        int tmp = get(i, curr_end1);

        if(arr[tmp].end1 <= curr_end1)
            break;
        else
        {
            curr_end1 = arr[tmp].end1;
            ans[a] = arr[tmp];
            a++;
        }

        i = tmp + 1;

        if(curr_end1 >= end1 || i >= n)
            break;
    }


    if(curr_end1 < end1)
        printf("0");
    else
    {
        printf("%d\n", a);
        for(int i = 0; i < a; i++)
        {
            printf("%d %d", ans[i].start, ans[i].end1);
            if(i < a - 1)
                printf("\n");
        }
    }

    return ;
}

int get(int i, int curr_end1)
{
    int p = i;
    int val = arr[i].end1;

    while(i < n && arr[i].start <= curr_end1)
    {
        if(arr[i].end1 > val)
        {
            val = arr[i].end1;
            p = i;
        }
        i++;
    }

    return p;
}


template <typename type>
void merge_sort(int start, int last, type arr, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, arr, swap);
    merge_sort(middle + 1, last, arr, swap);

    ///MERGING  ///MERGING  ///MERGING  ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        swap[i] = arr[i];

    while(main_p <= last)
    {
        if(p1 > middle)
            arr[main_p] = arr[p2], p2++;

        else if(p2 > last)
            arr[main_p] = swap[p1], p1++;

        else if(comp(swap[p1] , arr[p2]))
            arr[main_p] = swap[p1], p1++;

        else
            arr[main_p] = arr[p2], p2++;

        main_p++;
    }
    return;
}

bool comp(seg& i, seg& j)
{
    if(i.start < j.start)
        return true;

    if(i.start > j.start)
        return false;

    if(i.end1 < j.end1)
        return true;

    return false;
}
