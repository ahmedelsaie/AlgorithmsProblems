#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;
#define ll unsigned long long
#define MAX 14
struct card
{
    char  x[3];
};

template <typename type>
void merge_sort(int start, int last, type arr, type swap);
bool compare(card x, card y);
ll fn(int fours, int threes, int twos, int ones, int prev);
void trace(int fours, int threes, int twos, int ones, char prev, ll with_me);
void update(int& fours, int& threes, int& twos, int& ones, int& grp);
ll check(int fours, int threes, int twos, int ones, int grp);
int get_grp(int i);
void start(int& fours, int& threes, int& twos, int& ones);

ll dp[MAX][MAX][MAX][MAX][5];
bool visited[MAX][MAX][MAX][MAX][5];
card arr[60];
card help[60];
bool taken[50];

int n;
ll target;

int main()
{
    int fours, threes, twos, ones, cases = 1;
    memset(visited, 0, sizeof(visited));

    while(true)
    {
        scanf("%d %llu", &n, &target);

        if(n == 0 && target == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%s", arr[i].x);

        merge_sort(0, n - 1, arr, help);
        start(fours, threes, twos, ones);
        ll ans = fn(fours, threes, twos, ones, 0);

        memset(taken, 0, sizeof(taken));

        printf("Case %d:", cases++, ans);

        if(ans < target)
            printf(" Not found");
        else
            target--, trace(fours, threes, twos, ones, '0', 0);
        printf("\n");
    }

    return 0;
}

void trace(int fours, int threes, int twos, int ones, char prev, ll with_me)
{
    if(fours == 0 && threes == 0 && twos == 0 && ones == 0)
        return ;

    ll accum = 0, tmp = 0;
    int grp;

    for(int i = 0; i < n; i++)
    {
        if(taken[i]==0 && arr[i].x[0] != prev)
        {
            grp = get_grp(i);
            tmp = check(fours, threes, twos, ones, grp);
            if(tmp + accum + with_me > target)
            {
                printf(" %s", arr[i].x);
                update(fours, threes, twos, ones, grp);
                taken[i]=1;
                trace(fours, threes, twos, ones, arr[i].x[0], with_me + accum);
                return;
            }
            else
                accum += tmp;
        }
    }
}

ll check(int fours, int threes, int twos, int ones, int grp)
{
    switch(grp)
    {
    case 1:
        return fn(fours, threes, twos, ones - 1, 0);
    case 2:
        return fn(fours, threes, twos - 1, ones + 1, 1);
    case 3:
        return fn(fours, threes - 1, twos + 1, ones, 2);
    case 4:
        return  fn(fours - 1, threes + 1, twos, ones, 3);
    }

}

void update(int& fours, int& threes, int& twos, int& ones, int& grp)
{
    switch(grp)
    {
    case 1:
        ones--;
        return;
    case 2:
        twos--;
        ones++;
        return;
    case 3:
        threes--;
        twos++;
        return;
    case 4:
        fours--;
        threes++;
        return;
    }
}

int get_grp(int i)
{
    int j;
    for(j = 0; j < n; j++)
        if(arr[j].x[0] == arr[i].x[0])
            break;

    int k = j;
    int ret = 0;
    while(k < n)
    {
        if(taken[k]==0 && arr[k].x[0] == arr[i].x[0])
            ret++;

        if(arr[k].x[0] != arr[i].x[0])
            break;
        k++;
    }

    return ret;
}

ll fn(int fours, int threes, int twos, int ones, int prev)
{
    if(fours < 0 || threes < 0 || twos < 0 || ones < 0)
        return 0;

    ll& ret = dp[fours][threes][twos][ones][prev];
    bool& flag1 = visited[fours][threes][twos][ones][prev];
    if(flag1)
        return ret;

    flag1 = true;
    if(fours == 0 && threes == 0 && twos == 0 && ones == 0)
        return ret = 1;

    ret = 0;
    int new_fours = fours, new_threes = threes, new_twos = twos, new_ones = ones;

    switch(prev)
    {
    case 0:
        break;
    case 1:
        new_ones--;
        break;
    case 2:
        new_twos--;
        break;
    case 3:
        new_threes--;
        break;
    case 4:
        new_fours--;
        break;
    }

    ret += 4 * new_fours * fn(fours - 1, threes + 1, twos, ones, 3);
    ret += 3 * new_threes * fn(fours, threes - 1, twos + 1, ones, 2);
    ret += 2 * new_twos * fn(fours, threes, twos - 1, ones + 1, 1);
    ret += new_ones * fn(fours, threes, twos, ones - 1, 0);

    return ret;
}

void start(int& fours, int& threes, int& twos, int& ones)
{
    int tmp[500];
    memset(tmp, 0, sizeof(tmp));

    fours = threes = twos = ones = 0;


    for(int i = 0; i < n; i++)
        tmp[arr[i].x[0]]++;

    for(int i = 0; i < 500; i++)
    {
        if(tmp[i] == 1)
            ones++;
        else if(tmp[i] == 2)
            twos++;
        else if(tmp[i] == 3)
            threes++;
        else if(tmp[i] == 4)
            fours++;
    }
    return ;
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

        else if(compare(swap[p1], arr[p2]))
            arr[main_p] = swap[p1], p1++;

        else
            arr[main_p] = arr[p2], p2++;

        main_p++;
    }
    return;
}

bool compare(card x, card y)
{
    if(strcmp(x.x, y.x) < 0)
        return true;
    return false;
}

