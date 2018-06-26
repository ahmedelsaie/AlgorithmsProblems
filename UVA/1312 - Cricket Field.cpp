#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX1 109
#define MAX2 10009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int bin_search(int arr[], int m, int val, int flag);
int get(int x0, int y0, int x1, int y1);
void build_accum(int x, int y);
int check(int r1, int c1, int r2, int c2);
int get_max(int r, int c, int flag);
int RLC(int arr[], int m);
void fn();

pair<int, int> array[MAX1];
int row, col, tmp_row, tmp_col, n, p1, p2, cases;
int tmp1[MAX1], tmp2[MAX1], r_under[MAX2], r_upper[MAX2], c_under[MAX2], c_upper[MAX2], help[MAX1];
bool visited[MAX1][MAX1];
int accum[MAX1][MAX1], ans = 0;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d", &n, &col, &row);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &array[i].second, &array[i].first);
            array[i].second++;
            array[i].first = row - array[i].first + 1;
            tmp1[i] = array[i].first, tmp2[i] = array[i].second;
        }

        ans = 0;

        if(n == 0)
            printf("0 0 %d\n", min(row, col));
        else
        {
            fn();
            printf("%d %d %d\n", p2 - 1, row - p1, ans);
        }
        if(cases)
            printf("\n");
    }

    return 0;
}

void fn()
{
    row++, col++;

    merge_sort(0, n - 1, tmp1, help);
    merge_sort(0, n - 1, tmp2, help);

    tmp_row = RLC(tmp1, n);
    tmp_col = RLC(tmp2, n);

    for(int i = 1; i <= row; i++)
    {
        r_under[i] = bin_search(tmp1, tmp_row, i, 0);
        r_upper[i] = bin_search(tmp1, tmp_row, i, 1);
    }

    for(int i = 1; i <= col; i++)
    {
        c_under[i] = bin_search(tmp2, tmp_col, i, 0);
        c_upper[i] = bin_search(tmp2, tmp_col, i, 1);
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++)
    {
        int x = r_under[array[i].first] + 1;
        int y = c_under[array[i].second] + 1;
        visited[x][y] = 1;
    }

    build_accum(tmp_row, tmp_col);

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= row; j++)
        {
            int tmp = get_max(j, array[i].second, 1);
            if(tmp > ans)
                ans = tmp, p1 = j, p2 = array[i].second;

            int big = min(j - 1, col - array[i].second);
            if(big <= ans)
                break;
        }

        for(int j = 1; j <= col; j++)
        {
            int tmp = get_max(array[i].first, j, 1);
            if(tmp > ans)
                ans = tmp, p1 = array[i].first, p2 = j;

            int big = min(array[i].first - 1, col - j);
            if(big <= ans)
                break;
        }

        for(int j = 1; j <= row; j++)
        {
            int tmp = get_max(j, array[i].second, 0);
            if(tmp > ans)
                ans = tmp, p1 = j + ans, p2 = array[i].second - ans;

            int big = min(row - j, array[i].second - 1);
            if(big <= ans)
                break;
        }

        for(int j = 1; j <= col; j++)
        {
            int tmp = get_max(array[i].first, j, 0);
            if(tmp > ans)
                ans = tmp, p1 = array[i].first + ans, p2 = j - ans;

            int big = min(array[i].first - 1, col - j);
            if(big <= ans)
                break;
        }

        if(ans == min(row, col))
            return;

    }

    return ;
}

int get_max(int r, int c, int flag)
{
    int small = 1, big, mid, ret = 0;

    if(flag == 0)
    {
        big = min(row - r, c - 1);

        while(big >= small)
        {
            mid = (big + small) / 2;
            int s = check(r, c, r + mid, c - mid);

            if(s && mid >= ret)
                ret = mid;

            if(s)
                small = mid + 1;
            else
                big = mid - 1;
        }
    }
    else
    {
        big = min(r - 1, col - c);

        while(big >= small)
        {
            mid = (big + small) / 2;

            int s = check(r, c, r - mid, c + mid);

            if(s && mid >= ret)
                ret = mid;

            if(s)
                small = mid + 1;
            else
                big = mid - 1;
        }
    }

    return ret;
}

int check(int r1, int c1, int r2, int c2)
{
    int r_s = min(r1, r2) + 1;
    int r_b = max(r1, r2) - 1;
    int c_s = min(c1, c2) + 1;
    int c_b = max(c1, c2) - 1;

    r_s = r_upper[r_s];
    r_b = r_under[r_b];

    c_s = c_upper[c_s];
    c_b = c_under[c_b];


    if(r_s == -1 || r_b == -1 || c_s == -1 || c_b == -1)
        return 1;

    c_s++, c_b++, r_s++, r_b++;

    if(r_s > r_b || c_s > c_b)
        return 1;

    int tmp = get(r_s, c_s, r_b, c_b);
    if(tmp)
        return 0;
    return 1;
}

void build_accum(int x, int y)
{
    for(int i = 0; i <= x; i++)
        accum[i][0] = 0;

    for(int i = 0; i <= y; i++)
        accum[0][i] = 0;

    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            accum[i][j] = accum[i - 1][j] + accum[i][j - 1] - accum[i - 1][j - 1] + visited[i][j];
    return ;
}

int get(int x0, int y0, int x1, int y1)
{
    return accum[x1][y1] - accum[x0 - 1][y1] - accum[x1][y0 - 1] + accum[x0 - 1][y0 - 1];
}

int bin_search(int arr[], int m, int val, int flag)
{
    ///0 under
    int small = 0, big = m - 1, mid, ret;
    ret = (flag == 0 ? -1 : 9999999);

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(arr[mid] <= val && flag == 0 && mid > ret)
            ret = mid;

        if(arr[mid] >= val && flag == 1 && mid < ret)
            ret = mid;

        if(arr[mid] <= val)
            small = mid + 1;
        else
            big = mid - 1;
    }

    if(ret == -1 || ret == 9999999)
        return -1;

    return ret;
}

int RLC(int arr[], int m)
{
    int i = 0, prev = arr[i], j = 0;

    while(i < m)
    {
        if(arr[i] != prev)
            arr[j++] = prev, prev = arr[i];
        i++;
    }

    arr[j++] = prev;

    return j;
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
