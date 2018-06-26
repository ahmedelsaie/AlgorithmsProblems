#include <iostream>
#include <stdio.h>

using namespace std;
struct block
{
    int first, sec, id;
};
block exams[5005];
block help[5005];
template <typename type>
void merge_sort(int start, int last, type array, type swap);
int n;
int fn();
bool comp(block x, block y);

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &exams[i].first, &exams[i].sec), exams[i].id = i;
    merge_sort(0, n - 1, exams, help);
    printf("%d\n", fn());
    return 0;
}

int fn()
{
    int day = min(exams[0].first, exams[0].sec);
    for(int i = 0; i < n; i++)
    {
        if(min(exams[i].first, exams[i].sec) >= day)
            day = min(exams[i].first, exams[i].sec);
        else
            day = max(exams[i].first, exams[i].sec);
    }

    return day;
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

        else if(comp(swap[p1], array[p2]))
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

bool comp(block x, block y)
{
    if(x.first == y.first)
        return x.sec < y.sec;
    return x.first < y.first;
}


