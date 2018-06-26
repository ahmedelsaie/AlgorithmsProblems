#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

template <typename type>
void merge_sort(int start, int last, type array, type swap);
void sec_and_third(vector<int>& first, vector<int>& sec, int i, int top);
bool check(int i, int top);
bool contain(int i, int top);
int fn(int i, int top);

int array[55][55], sizes[55];
int dp[3025][51], visited[3025][51];
pair<int, int> sorted[3025], help[3025];

int n, k = 0, cases = 1;
const int inf = 99999999;

int main()
{
    int ans;
    memset(visited, -1, sizeof(visited));

    while(scanf("%d", &n) != EOF)
    {
        k=0;
        for(int i = 0; i < n; i++)
        {
            int t = 0, prev = -1, x;
            scanf("%d", &sizes[i]);
            for(int j = 0; j < sizes[i]; j++)
            {
                scanf("%d", &x);
                if(x != prev)
                    array[i][t] = x, sorted[k].first = array[i][t], sorted[k].second = i, k++, t++;
                prev = x;
            }
        }
        merge_sort(0, k - 1, sorted, help);
        ans = inf;
        for(int j = 0; j < n; j++)
            ans = min(ans, fn(0, j));

        printf("Case %d: %d\n", cases, ans);
        cases++;
    }

    return 0;
}

int fn(int i, int top)
{
    if(i == k)
        return 0;

    int& flag = visited[i][top];
    int& ret = dp[i][top];
    if(flag == cases)
        return ret;

    flag = cases, ret = inf;
    vector<int>first, sec;
    sec_and_third(first, sec, i, top);

    int tmp = 0;
    tmp = first.size() + 2 * sec.size();

    ///if top contains it
    if(contain(i, top))
    {
        int is_end = check(i, top);
        if(!is_end && first.size() + sec.size() != 0)
            tmp += 1;

        ///top will remsin the same
        ret = min(ret, fn(i + first.size() + sec.size() + 1, top) + tmp + (!is_end) * (first.size() + sec.size() != 0));

        ///get the sec and third
        for(int j = 0; j < first.size(); j++)
            ret = min(ret, fn(i + first.size() + sec.size() + 1, first[j]) + tmp);

        for(int j = 0; j < sec.size(); j++)
            ret = min(ret, fn(i + first.size() + sec.size() + 1, sec[j]) + tmp - 1);
    }
    else
    {
        ///if top doesn't include desired no remove
        if(array[top][0] < sorted[i].first)
            tmp += 1;

        ///top remains the same
        ret = min(ret, fn(i + first.size() + sec.size(), top) + tmp + 1);

        ///get the sec and third
        for(int j = 0; j < first.size(); j++)
            ret = min(ret, fn(i + first.size() + sec.size(), first[j]) + tmp);

        for(int j = 0; j < sec.size(); j++)
            ret = min(ret, fn(i + first.size() + sec.size(), sec[j]) + tmp - 1);
    }

    return ret;
}

void sec_and_third(vector<int>& first, vector<int>& sec, int i, int top)
{
    for(int j = i; j < k && sorted[j].first == sorted[i].first; j++)
    {
        if(sorted[j].second != top)
        {
            int tmp = sorted[j].second;
            if(array[tmp][0] == sorted[i].first)
                first.push_back(sorted[j].second);
            else
                sec.push_back(sorted[j].second);
        }
    }
}

bool check(int i, int top)
{
    return (array[top][0] == sorted[i].first);
}

bool contain(int i, int top)
{
    for(int j = i; j < k && sorted[i].first == sorted[j].first; j++)
        if(sorted[j].second == top)
            return true;
    return false;
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

        else if(swap[p1].first > array[p2].first)
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
