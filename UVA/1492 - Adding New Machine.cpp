#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define MAX 50009

struct area
{
    ll x1, y1, x2, y2;
};

int pre1();
template <typename type>
void merge_sort(int start, int last, type array, type swap);
ll get(int f, int s);
int get_indx(int x, int big);
int pre1();
ll fn();

area array[4 * MAX];
vector<int>add[4 * MAX], rem[4 * MAX];
int m, n, w_col, h_row;
int dist[4 * MAX], help[4 * MAX];

int main()
{
    while(scanf("%d %d %d %d", &w_col, &h_row, &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%lld %lld %lld %lld", &array[i].y1, &array[i].x1, &array[i].y2, &array[i].x2);

        ll ans = fn();
        for(int i = 0; i < n; i++)
            swap(array[i].y1, array[i].x1), swap(array[i].y2, array[i].x2);

        swap(w_col, h_row);
        if(m > 1)
            ans += fn();
        printf("%lld\n", ans);
    }
    return 0;
}

ll fn()
{
    int k = pre1();
    ll curr, last = get(0, w_col + 1), ret = 0, last_p = 1;
    set<int> x, y;

    w_col++;
    x.insert(0), x.insert(w_col);
    y.insert(0), y.insert(-1 * (w_col));

    for(int i = 0; i < k && dist[i] <= h_row; i++)
    {
        curr = last;
        for(int j = 0; j < rem[i].size(); j++)
        {
            int idx = rem[i][j];

            int small = *(y.upper_bound(-1 * array[idx].y1));
            small = -1 * small;
            int big = *(x.upper_bound(array[idx].y2));
            int tmp = get(array[idx].y2, big) + get(small, array[idx].y1);
            curr -= tmp;
            tmp = get(small, big);
            curr += tmp;

            x.erase(x.upper_bound(array[idx].y1 - 1));
            if(array[idx].y2 != array[idx].y1)
                x.erase(x.upper_bound(array[idx].y1 - 1));

            y.erase(y.upper_bound(-1 * (array[idx].y1 + 1)));
            if(array[idx].y2 != array[idx].y1)
                y.erase(y.upper_bound(-1 * (array[idx].y2 + 1)));
        }


        for(int j = 0; j < add[i].size(); j++)
        {
            int idx = add[i][j];

            int small = *(y.upper_bound(-1 * array[idx].y1));
            small = -1 * small;

            int big = *(x.upper_bound(array[idx].y2));

            int tmp = get(small, big);
            curr -= tmp;
            tmp = get(array[idx].y2, big) + get(small, array[idx].y1);
            curr += tmp;
            x.insert(array[idx].y2);
            if(array[idx].y2 != array[idx].y1)
                x.insert(array[idx].y1);

            y.insert(-1 * array[idx].y2);
            if(array[idx].y2 != array[idx].y1)
                y.insert(-1 * array[idx].y1);
        }
        ret += last * (dist[i] - last_p);
        last = curr;
        last_p = dist[i];
    }

    ret += last * (h_row + 1 - last_p);

    w_col--;
    return ret;
}

int pre1()
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        dist[j++] = array[i].x1;
        dist[j++] = array[i].x2 + 1;
    }
    merge_sort(0, j - 1, dist, help);

    int i = 0, k = 0, prev = dist[0];
    while(i < j)
    {
        if(prev != dist[i])
            dist[k++] = prev, prev = dist[i];
        i++;
    }

    dist[k++] = prev, prev = dist[i];
    for(int i = 0; i < k; i++)
        rem[i].clear(), add[i].clear();

    for(int i = 0; i < n; i++)
    {
        int tmp = get_indx(array[i].x1, k);
        add[tmp].push_back(i);


        tmp = get_indx(array[i].x2 + 1, k);
        rem[tmp].push_back(i);
    }

    return k;
}

int get_indx(int x, int big)
{
    int small = 0, mid;
    big--;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(dist[mid] == x)
            return mid;

        if(dist[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return -1;
}

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

ll get(int f, int s)
{
    if(s - f < m)
        return 0;
    ll tmp = s - f - 1;
    return tmp - m + 1;
}
