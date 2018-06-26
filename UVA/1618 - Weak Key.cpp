#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 5005

const int inf = 9999999;

///segment_tree
struct seg_tree
{
    int seg[4 * MAX], visited[4 * MAX], flag, cas;
    ///0 smallest

    void clear()
    {
        memset(visited, -1, sizeof(visited));
        cas = 0;
    }

    int get_query(int ql, int qh, int low, int high, int pos)
    {
        if(visited[pos] != cas)
            return (flag == 0 ? inf : -1 * inf);

        ///no overlap
        if (qh <= low || ql >= high)
            return (flag == 0 ? inf : -1 * inf);

        int no = (flag == 0 ? inf : -1 * inf);
        ///total overlap
        if(low >= ql && high <= qh)
            return (visited[pos] == cas ? seg[pos] : no);

        int mid = (low + high) / 2;

        ///partial overlap
        int p1 = get_query(ql, qh, low, mid, 2 * pos + 1);
        int p2 = get_query(ql, qh, mid, high, 2 * pos + 2);;
        return  (flag == 0 ? min(p1, p2) : max(p1, p2));
    }

    void update(int indx, int val, int low, int high, int pos)
    {
        visited[pos] = cas;
        if(indx == low && high == low + 1)
            seg[pos] = val;
        else
        {
            ///check in which part
            int mid = (low + high) / 2;

            if(indx >= low && indx < mid)
                update(indx, val, low, mid, 2 * pos + 1);
            else
                update(indx, val, mid, high, 2 * pos + 2);

            int no = (flag == 0 ? inf : -1 * inf);
            int p1 = visited[2 * pos + 1] == cas ? seg[2 * pos + 1] : no;
            int p2 = visited[2 * pos + 2] == cas ? seg[2 * pos + 2] : no;
            seg[pos] = (flag == 0 ? min(p1, p2) : max(p1, p2));
        }
    }

};

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int bin_search(int x);
int pre_process();
int fn();

int n, cases, array[MAX], sorted[MAX], help[MAX], k;
seg_tree lefts, leftb, rightb, rights;

int main()
{
    rightb.flag = leftb.flag = 1;
    rights.flag = lefts.flag = 0;

    lefts.clear(), leftb.clear();
    rights.clear(), rightb.clear();

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]), help[i] = array[i];

        pre_process();
        printf("%s", fn() == 1 ? "YES" : "NO");
        printf("\n");

    }

    return 0;
}

int fn()
{
    leftb.cas++, lefts.cas++;

    for(int i = 0; i < n; i++)
    {
        rights.cas++, rightb.cas++;
        for(int j = n - 1; j > i; j--)
        {
            if(array[i] < array[j])
            {
                int s = rights.get_query(help[i] + 1, help[j], 0, k, 0);
                int b = leftb.get_query(help[i] + 1, help[j], 0, k, 0);

                if(s != inf && b != -1 * inf && s < b)
                    return 1;
            }
            else if(array[i] > array[j])
            {
                int x = min(help[i], help[j]);
                int y = max(help[i], help[j]);
                int s = lefts.get_query(x + 1, y, 0, k, 0);
                int b = rightb.get_query(x + 1, y, 0, k, 0);

                if(s != inf && b != -1 * inf && s < b)
                    return 1;
            }

            rights.update(help[j], array[j], 0, k, 0);
            rightb.update(help[j], array[j], 0, k, 0);
        }


        lefts.update(help[i], array[i], 0, k, 0);
        leftb.update(help[i], array[i], 0, k, 0);
    }

    return 0;
}

int pre_process()
{
    merge_sort(0, n - 1, help, sorted);
    k = 0;
    int i = 0, prev = help[0];
    while(i < n)
    {
        if(prev != help[i])
            sorted[k++] = prev, prev = help[i];
        i++;
    }

    sorted[k++] = prev;

    for(int i = 0; i < n; i++)
        help[i] = bin_search(array[i]);
}

int bin_search(int x)
{
    int small = 0, big = k - 1, mid;
    while(big >= small)
    {
        mid = (small + big) / 2;

        if(sorted[mid] == x)
            return mid;

        if(sorted[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return -1;
}

///merge_sort
template <typename type>
void merge_sort(int start, int last, type array, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, array, swap);
    merge_sort(middle + 1, last, array, swap);

    ///MERGING  ///MERGING  ///MERGING  ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        swap[i] = array[i];

    while(main_p <= last)
    {
        if(p1 > middle)
            array[main_p] = array[p2], p2++;

        else if(p2 > last)
            array[main_p] = swap[p1], p1++;

        else if(swap[p1] < array[p2])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
