#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#define ll long long
using namespace std;
struct block
{
    int x, id;
};

template <typename type>
void merge_sort(int start, int last, type array[], type swap[], bool (*comp)(type, type));
ll fn(int curr_t, int curr_s);
void trace(int curr_t, int curr_s);
bool comp1(block a, block b);
bool comp2(block a, block b);

int visited[4005][4005];
ll dp[4005][4005];
block teams[4005];
block shelters[4005];
block help[4005];

int cases = 0, n_teams, n_shelters;
const ll inf = 99999999999999;

int main()
{
    memset(visited, -1, sizeof(visited));
    while(scanf("%d", &n_teams) != EOF)
    {
        for(int i = 0; i < n_teams; i++)
            scanf("%d", &teams[i].x), teams[i].id = i;

        scanf("%d", &n_shelters);
        for(int i = 0; i < n_shelters; i++)
            scanf("%d", &shelters[i].x), shelters[i].id = i;

        merge_sort(0, n_teams - 1, teams, help, comp1);
        merge_sort(0, n_shelters - 1, shelters, help, comp1);

        printf("%lld\n", fn(0, 0));
        trace(0, 0);
        merge_sort(0, n_teams - 1, teams, help, comp2);

        for(int i = 0; i < n_teams; i++)
        {
            if(i)
                printf(" ");
            printf("%d", teams[i].x + 1);
        }
        printf("\n");

        cases++;
    }
    return 0;
}

void trace(int curr_t, int curr_s)
{
    if(curr_t == n_teams || curr_s == n_shelters)
        return ;

    ll& ret = dp[curr_t][curr_s];

    if(ret == dp[curr_t + 1][curr_s] + abs(teams[curr_t].x - shelters[curr_s].x))
        teams[curr_t].x = shelters[curr_s].id, trace(curr_t + 1, curr_s);
    else
        teams[curr_t].x = shelters[curr_s].id, trace(curr_t + 1, curr_s + 1);

    return;
}

ll fn(int curr_t, int curr_s)
{
    int& flag = visited[curr_t][curr_s];
    ll& ret = dp[curr_t][curr_s];
    if(flag == cases)
        return ret;
    flag = cases;
    ret = inf;

    if(curr_t == n_teams && curr_s == n_shelters)
        return ret = 0;

    if(curr_t == n_teams || curr_s == n_shelters)
        return ret = inf;

    ret = min(ret, fn(curr_t + 1, curr_s) + abs(teams[curr_t].x - shelters[curr_s].x));
    ret = min(ret, fn(curr_t + 1, curr_s + 1) + abs(teams[curr_t].x - shelters[curr_s].x));

    return ret;
}

template <typename type>
void merge_sort(int start, int last, type array[], type swap[], bool (*comp)(type, type))
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, array, swap, comp);
    merge_sort(middle + 1, last, array, swap, comp);

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

        else if(comp(swap[p1], array[p2]))
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

bool comp1(block a, block b)
{
    return a.x < b.x;
}

bool comp2(block a, block b)
{
    return a.id < b.id;
}
