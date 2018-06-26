#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

///merge_sort
template <typename type>
void merge_sort(int start, int last, type array, type swap);
bool check(pair<int, int> x, pair<int, int> y);
void fn(int x);
int solve();

pair<int, int> array[1005], help[1005];
bool visited[1005];
int n, p = 1;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == -1)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d %d", &array[i].first, &array[i].second);
        printf("Case %d: %d\n", p++, solve());
    }

    return 0;
}

int solve()
{
    merge_sort(0, n - 1, array, help);
    memset(visited, 0, sizeof(visited));
    int ret = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            ret++, visited[i] = 0, fn(i);
    }

    return ret;
}

void fn(int x)
{
    for(int i = x + 1; i < n; i++)
    {
        if(array[x].second < array[i].first && visited[i] == false)
        {
            visited[i] = true;
            fn(i);
            break;
        }
    }
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

        else if(check(swap[p1], array[p2]))
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

bool check(pair<int, int> x, pair<int, int> y)
{
    if(x.first != y.first)
        return x.first < y.first;

    return x.second < y.second;
}
