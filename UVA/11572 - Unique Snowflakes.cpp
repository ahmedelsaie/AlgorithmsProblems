#include <stdio.h>
#include <cstring>
struct block
{
    int val, i, hash;
};
///FUNCTIONS
template <typename type>
void merge_sort(int start, int last, type arr, type swap);
int max(int x, int y);
void build_hash();
int fn();

///arrS
block arr1[1000009];
block arr2[1000009];
block help[1000009];
int prev[1000009];
int visited[1000009];

///VARIABLES
int n, cases;

int main()
{
    block tmp;
    memset(visited, -1, sizeof(visited));
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp.val);
            tmp.i = i;
            arr1[i] = tmp;
            arr2[i] = tmp;
        }

        printf("%d\n", fn());
    }

    return 0;
}

int fn()
{
    build_hash();

    int start = 0, end = 0;
    int ret = 0;
    int a;
    for(int i = 0; i < n; i++)
    {
        end = i;
        a = arr1[i].hash;

        if(visited[a] == cases)
        {
            if(prev[a] >= start)
                start = prev[a] + 1;
        }
        else
            visited[a] = cases;


        ret = max(ret, end - start + 1);
        prev[a] = i;
    }

    return ret;
}

void build_hash()
{
    merge_sort(0, n - 1, arr2, help);
    int taken = -1;
    int prev = -1;
    int curr, index;

    for(int i = 0; i < n; i++)
    {
        curr = arr2[i].val;

        if(curr != prev)
            taken++;

        index = arr2[i].i;
        arr1[index].hash = taken;
        prev = curr;
    }

    return;
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

        else if(swap[p1].val < arr[p2].val)
            arr[main_p] = swap[p1], p1++;

        else
            arr[main_p] = arr[p2], p2++;

        main_p++;
    }
    return;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
