#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
bool comp(pair<int, int> x, pair<int, int> y);
void fill(int start, int end, int i);
int to_binary(int x, int i);
bool fn();
int bin_to_int(int j);

pair<int, int> tmp[MAX], help[MAX], tmp2[MAX];
int con[MAX][3], n, m, max_num = 0;
bool array[MAX][32], con_bin[MAX][32];

int main()
{
    memset(array, 0, sizeof(array));
    memset(con_bin, 0, sizeof(con_bin));


    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &con[i][0], &con[i][1], &con[i][2]);
        max_num = max(max_num, to_binary(con[i][2], i));
    }

    //printf("%d\n", max_num);

    bool ans = fn();

    if(ans)
    {
        printf("YES\n");
        for(int i = 1; i <= n; i++)
        {
            if(i > 1)
                printf(" ");
            printf("%d", bin_to_int(i));
        }
    }
    else
        printf("NO");

    printf("\n");

    return 0;
}

bool fn()
{
    int indx, accum[MAX], indx2;

    for(int i = 0; i < max_num; i++)
    {
        indx = indx2 = 0;
        for(int j = 1; j <= m; j++)
        {
            if(con_bin[j][i] == 1)
                tmp[indx].first = con[j][0], tmp[indx].second = con[j][1], indx++;
            else
                tmp2[indx2].first = con[j][0], tmp2[indx2].second = con[j][1], indx2++;
        }

        merge_sort(0, indx - 1, tmp, help);

        int start = 0, end = 0;

        for(int j = 0; j < indx; j++)
        {
            if(tmp[j].first < end)
                start = end;
            else
                start = tmp[j].first;
            end = max(end, tmp[j].second);
            fill(start, end, i);
        }

        accum[0] = 0;
        for(int j = 1; j <= n; j++)
            accum[j] = accum[j - 1] + array[j][i];

        for(int j = 0; j < indx2; j++)
        {
            int s = tmp2[j].first, e = tmp2[j].second;

            if(accum[e] - accum[s - 1] == e - s + 1)
                return false;
        }
    }

    return true;
}

int bin_to_int(int j)
{
    int ret = 0, t = 1;
    for(int i = 0; i < max_num; i++)
        ret = ret + t * array[j][i], t *= 2;
    return ret;
}

void fill(int start, int end, int i)
{
    for(int j = start; j <= end; j++)
        array[j][i] = 1;

    return;
}

int to_binary(int x, int i)
{
    int j = 0;

    while(x)
    {
        con_bin[i][j] = x % 2;
        j++, x = x / 2;
    }

    return j;
}

//merge_sort
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

        else if(comp(swap[p1], array[p2]))
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

bool comp(pair<int, int> x, pair<int, int> y)
{
    if(x.first == y.first)
        return x.second == y.second;
    return x.first < y.first;
}

