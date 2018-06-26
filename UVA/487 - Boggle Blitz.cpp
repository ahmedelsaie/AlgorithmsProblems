#include <stdio.h>
#include <cstring>
#define max 30

struct word
{
    char array[max];
    int l;
};

void fn(int row, int col, int l, char last, bool flag);
int comp(word &x, word &y);
void print();
void merge(int start, int end);
void merge_sort(int start, int last);

word ans[25000];
word help[25000];
char accum[max];
int n;
int s;
char grid[25][25];
bool check[25][25];

int main()
{
    memset(check, true, sizeof(check));
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        n = 0;
        scanf("%d", &s);

        for(int j = 0; j < s; j++)
            scanf("%s", grid[j]);

        for(int j = 0; j < s; j++)
            for(int k = 0; k < s; k++)
                fn(j, k, 0, (char) - 1, false);

        merge_sort(0, n - 1);
        print();

        if(cases)
            printf("\n");
    }
    return 0;
}

void fn(int row, int col, int l, char last, bool flag)
{
    if(flag)
    {
        accum[l] = '\0';
        if(true)
        {
            strcpy(ans[n].array, accum);
            ans[n].l = l;
            n++;
        }

        return;
    }

    if(row < 0 || row >= s || col < 0 || col >= s)
        return ;

    if(!check[row][col] || grid[row][col] <= last)
        return ;

    check[row][col] = false;
    accum[l] = grid[row][col];
    last = grid[row][col];

    fn(row, col + 1, l + 1, last, false);
    fn(row, col - 1, l + 1, last, false);
    fn(row + 1, col, l + 1, last, false);
    fn(row - 1, col, l + 1, last, false);

    fn(row + 1, col + 1, l + 1, last, false);
    fn(row + 1, col - 1, l + 1, last, false);
    fn(row - 1, col - 1, l + 1, last, false);
    fn(row - 1, col + 1, l + 1, last, false);

    if(l + 1 >= 3)
        fn(row, col, l + 1, last, true);
    check[row][col] = true;
    return ;
}

void merge_sort(int start, int last)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle);
    merge_sort(middle + 1, last);
    merge(start, last);
    return;
}

void merge(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = ans[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            ans[main_p] = ans[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            ans[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(comp(help[p1], ans[p2]) < 0)
        {
            ans[main_p] = help[p1];
            p1++;
        }
        else
        {
            ans[main_p] = ans[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

int comp(word &x, word &y)
{
    if(x.l < y.l)
        return -1;

    if(x.l > y.l)
        return 1;

    return strcmp(x.array, y.array);
}

void print()
{
    if(n == 0)
        return ;

    char curr[max];
    strcpy(curr, ans[0].array);
    printf("%s\n", curr);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(curr, ans[i].array) != 0)
            printf("%s\n", ans[i].array);
        strcpy(curr, ans[i].array);
    }
}
