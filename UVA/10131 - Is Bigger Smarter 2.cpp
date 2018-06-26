#include <stdio.h>
struct elephant
{
    int weight;
    int iq;
    int serial;
};
const int inf = 100000000;

void merge_sort(int start, int last);
void merge(int start, int end);
int lis(int limit);
void print();

elephant elephants[1050];
elephant help[1050];
int dp[1050][1050];
int no_elephants;
int sub;

int main()
{
    int w, i;
    no_elephants = 1;
    while(scanf("%d", &w) != EOF)
    {
        scanf("%d", &i);
        elephants[no_elephants].weight = w;
        elephants[no_elephants].iq = i;
        elephants[no_elephants].serial = no_elephants - 1;
        no_elephants++;
    }
    merge_sort(1, no_elephants);
    sub = lis(no_elephants);
    printf("%d\n", sub);
    print();
    return 0;
}

void print()
{
    int x, y;
    int current = 1;
    int prev = 0;
    int taken = 0;

    while(true)
    {
        x = dp[prev][current + 1];
        if(elephants[current].weight > elephants[prev].weight && elephants[current].iq < elephants[prev].iq)
            y = dp[current][current + 1] + 1;
        else
            y = -1 * inf;

        if(y >= x)
        {
            prev = current;
            printf("%d\n", elephants[current].serial + 1);
            taken++;
        }
        current++;

        if(taken == sub)
            return;
    }
    return;
}

int lis(int limit)
{
    for(int i = 0; i <= limit; i++)
        dp[i][limit + 1] = 0;

    elephants[0].weight = 0;
    elephants[0].iq = inf;

    int choice1, choice2;


    for(int j = limit; j >= 1; j--)
        for(int i = 0; i < j; i++)
        {
            choice2 = choice1 = -1 * inf;
            choice1 = dp[i][j + 1];

            if(elephants[j].weight > elephants[i].weight && elephants[j].iq < elephants[i].iq)
                choice2 = 1 + dp[j][j + 1];

            if(choice1 > choice2)
                dp[i][j] = choice1;
            else
                dp[i][j] = choice2;
        }
    return dp[0][1];
}

void merge_sort(int start, int last)
{
    if(start == last)
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
        help[i] = elephants[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            elephants[main_p] = elephants[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            elephants[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1].weight < elephants[p2].weight)
        {
            elephants[main_p] = help[p1];
            p1++;
        }
        else
        {
            elephants[main_p] = elephants[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}
