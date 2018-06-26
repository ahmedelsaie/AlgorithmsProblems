#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 200009

int update(int seg_tree[], int indx, int val, int low, int high, int pos);
void construct_segtree(int array[], int seg_tree[], int start, int end, int pos);
int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos);
int calc(int x, int y);

int array[MAX], seg_tree[MAX], n, k, x, y;
char input[20];

int main()
{
    while(scanf("%d %d", &n, &k) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        construct_segtree(array, seg_tree, 0, n, 0);

        for(int i = 0; i < k; i++)
        {
            scanf("%s", input);
            scanf("%d %d", &x, &y);

            if(input[0] == 'C')
                update(seg_tree, --x, y, 0, n, 0);
            else
            {
                int tmp = get_query(seg_tree, --x, y, 0, n, 0);
                if(tmp == 0)
                    printf("0");
                else if(tmp == 1)
                    printf("+");
                else
                    printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}

int update(int seg_tree[], int indx, int val, int low, int high, int pos)
{
    if(indx == low && high == low + 1)
    {
        seg_tree[pos] = calc(val, 1);
        return calc(val, 1);
    }

    ///check in which part
    int mid = (low + high) / 2;

    if(indx >= low && indx < mid)
        seg_tree[pos] = calc(seg_tree[2 * pos + 2], update(seg_tree, indx, val, low, mid, 2 * pos + 1));
    else
        seg_tree[pos] = calc(seg_tree[2 * pos + 1], update(seg_tree, indx, val, mid, high, 2 * pos + 2));

    return seg_tree[pos];
}

void construct_segtree(int array[], int seg_tree[], int start, int end, int pos)
{
    if(end == start + 1)
        seg_tree[pos] = calc(array[start], 1);
    else
    {
        int mid = (start + end) / 2;
        construct_segtree(array, seg_tree, start, mid, 2 * pos + 1);
        construct_segtree(array, seg_tree, mid, end, 2 * pos + 2);
        seg_tree[pos] = calc(seg_tree[2 * pos + 1], seg_tree[2 * pos + 2]);
    }
}

int calc(int x, int y)
{
    ///-1
    ///0
    ///1
    if(x >= 1)
        x = 1;

    if(y >= 1)
        y = 1;

    if(y <= -1)
        y = -1;

    if(x <= -1)
        x = -1;

    return x * y;
}

int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos)
{
    ///no overlap
    if (qh <= low || ql >= high)
        return 1;

    ///total overlap
    if(low >= ql && high <= qh)
        return seg_tree[pos];

    int mid = (low + high) / 2;

    ///partial overlap
    return calc(get_query(seg_tree, ql, qh, low, mid, 2 * pos + 1), get_query(seg_tree, ql, qh, mid, high, 2 * pos + 2));
}
