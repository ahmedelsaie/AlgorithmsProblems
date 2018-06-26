#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 100009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int fn();

pair<int, int>edges[2 * MAX], help[2 * MAX];
int visited[MAX], color[MAX], m, n, j = 0, x, y;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &color[i]);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        edges[j].first = x, edges[j].second = y, j++;
        edges[j].first = y, edges[j].second = x, j++;
    }

    printf("%d\n", fn());
    return 0;
}

int fn()
{
    int i = 0, prev = color[edges[0].first], cases = 0, a = 0, ret = 0, c = 99999999, curr_c = color[edges[0].first];

    merge_sort(0, 2 * m - 1, edges, help);
    memset(visited, -1, sizeof(visited));

    while(i < 2 * m)
    {
        if(color[edges[i].first] == prev)
        {
            if(visited[color[edges[i].second]] != cases && color[edges[i].second] != curr_c)
                visited[color[edges[i].second]] = cases, a++;
        }
        else
        {
            if(a >= ret)
            {
                if(a > ret)
                    ret = a, c = curr_c;
                else if(curr_c < c)
                    c = curr_c;
            }

            cases++, a = 0, curr_c = color[edges[i].first];

            if(color[edges[i].second] != curr_c)
                visited[color[edges[i].second]] = cases, a++;

            prev = curr_c;
        }

        i++;
    }

    if(a >= ret)
    {
        if(a > ret)
            ret = a, c = curr_c;
        else if(curr_c < c)
            c = curr_c;
    }

    if(ret == 0)
        for(int i = 1; i <= n; i++)
            c = min(c, color[i]);

    return c;
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

        else if(color[swap[p1].first] < color[array[p2].first])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
