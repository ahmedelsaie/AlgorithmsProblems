#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

struct box
{
    int dim[10];
    int serial;
};

bool check(int current, int last);
int fn(int current, int last);
void sort_allboxes();
void bsort(int i);
void reset();
void sort_main();
void print();

box boxes[35];
int dp[35][35];
const int inf = 10000000;
int result;
int n, k;

int main()
{
    while(scanf("%d %d", &k, &n) == 2)
    {
        for(int counter = 0; counter < k; counter++)
        {
            for(int counter2 = 0; counter2 < n; counter2++)
                scanf("%d", &boxes[counter].dim[counter2]);
            boxes[counter].serial = counter;
        }

        for(int counter = 0; counter < n; counter++)
            boxes[k + 1].dim[counter] = -1 * inf;

        reset();
        sort_allboxes();
        sort_main();

        result = fn(0, k + 1);
        printf("%d\n", result);
        print();
    }

    return 0;
}

void print()
{
    int current, last;
    int taken = 0;
    last = k + 1;
    for(int counter = 0; counter < k; counter++)
    {
        if(check(counter, last))
        {
            if(dp[counter + 1][counter] + 1 >= dp[counter + 1][last])
            {
                last = counter;
                printf("%d", boxes[counter].serial + 1);
                taken++;
                if(taken < result)
                    printf(" ");
            }
        }

    }
    printf("\n");
}

void sort_main()
{
    box swap;
    for(int counter = 0; counter < k - 1; counter++)
        for(int counter2 = 0; counter2 < k - 1; counter2++)
            if(boxes[counter2].dim[0] >= boxes[counter2 + 1].dim[0])
            {
                swap = boxes[counter2];
                boxes[counter2] = boxes[counter2 + 1];
                boxes[counter2 + 1] = swap;
            }
}

bool check(int current, int last)
{
    for(int counter = 0; counter < n; counter++)
        if(boxes[current].dim[counter] <= boxes[last].dim[counter])
            return false;
    return true;
}

int fn(int current, int last)
{
    int &ret = dp[current][last];

    if(ret != -1)
        return ret;

    if(current == k)
        return 0;

    int r1 = 0;
    int r2 = 0;

    if(check(current, last))
        r1 = fn(current + 1, current) + 1;

    r2 = fn(current + 1, last);

    if(r1 > r2)
        return ret = r1;

    else
        return ret = r2;

}

void reset()
{
    for(int counter = 0; counter < k + 4; counter++)
        for(int counter2 = 0; counter2 < k + 4; counter2++)
            dp[counter][counter2] = -1;
}

void sort_allboxes()
{
    for(int counter = 0; counter < k; counter++)
        bsort(counter);
}

void bsort(int i)
{
    int swap;

    for(int counter = 0; counter < n - 1; counter++)
        for(int counter2 = 0; counter2 < n - 1; counter2++)
            if(boxes[i].dim[counter2] >= boxes[i].dim[counter2 + 1])
            {
                swap = boxes[i].dim[counter2];
                boxes[i].dim[counter2] = boxes[i].dim[counter2 + 1];
                boxes[i].dim[counter2 + 1] = swap;
            }

}

