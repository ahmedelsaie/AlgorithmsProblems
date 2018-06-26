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

int array[MAX], seg_tree[4 * MAX], n, x, y, cases = 1;
char input[20];

int main()
{
    bool flag = 0;
    while(true)
    {
        flag = 0;
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        construct_segtree(array, seg_tree, 0, n, 0);
        //printf("Case %d:\n", cases++);

        while(true)
        {
            scanf("%s", input);
            if(input[0] == 'M')
            {
                scanf("%d %d", &x, &y);
                if(flag == 0)
                {
                    if(cases > 1)
                        printf("\n");
                    printf("Case %d:\n", cases++), flag = 1;
                }
                printf("%d\n", get_query(seg_tree, x - 1, y, 0, n, 0));

            }
            else if(input[0] == 'S')
                scanf("%d %d", &x, &y), update(seg_tree, x - 1, y, 0, n, 0);
            else
                break;
        }
        if(flag == 0)
            cases++;
       // printf("\n");
    }

    return 0;
}

int update(int seg_tree[], int indx, int val, int low, int high, int pos)
{
    if(indx == low && high == low + 1)
    {
        seg_tree[pos] = val;
        return val;
    }

    ///check in which part
    int mid = (low + high) / 2;

    if(indx >= low && indx < mid)
        seg_tree[pos] = seg_tree[2 * pos + 2] + update(seg_tree, indx, val, low, mid, 2 * pos + 1);
    else
        seg_tree[pos] = seg_tree[2 * pos + 1] + update(seg_tree, indx, val, mid, high, 2 * pos + 2);;

    return seg_tree[pos];
}

void construct_segtree(int array[], int seg_tree[], int start, int end, int pos)
{
    if(end == start + 1)
        seg_tree[pos] = array[start];
    else
    {
        int mid = (start + end) / 2;
        construct_segtree(array, seg_tree, start, mid, 2 * pos + 1);
        construct_segtree(array, seg_tree, mid, end, 2 * pos + 2);
        seg_tree[pos] = seg_tree[2 * pos + 1] + seg_tree[2 * pos + 2];
    }
}

int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos)
{
    ///no overlap
    if (qh <= low || ql >= high)
        return 0;

    ///total overlap
    if(low >= ql && high <= qh)
        return seg_tree[pos];

    int mid = (low + high) / 2;

    ///partial overlap
    return get_query(seg_tree, ql, qh, low, mid, 2 * pos + 1) + get_query(seg_tree, ql, qh, mid, high, 2 * pos + 2);
}
