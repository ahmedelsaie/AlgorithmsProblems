#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

struct box
{
    int dim[10];
    int serial;
};

int lis(int limit);
bool check(int current, int last);
void sort_boxes();
void sort_dimen();
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
        for(int i = 1; i <= k; i++)
        {
            for(int j = 0; j < n; j++)
                scanf("%d", &boxes[i].dim[j]);
            boxes[i].serial = i - 1;
        }

        sort_dimen();
        sort_boxes();
        result = lis(k);
        printf("%d\n", result);
        print();
    }

    return 0;
}

void print()
{
    int current, last;
    int taken = 0;
    last = 0;
    current = 1;
    while(true)
    {
        if(check(current, last))
        {
            if(dp[current][current + 1] + 1 >= dp[last][current + 1])
            {
                last = current;
                printf("%d", boxes[current].serial + 1);
                taken++;
                if(taken < result)
                    printf(" ");
            }
            if(taken >= result)
                break;
        }
        current++;
    }
    printf("\n");
}

bool check(int current, int last)
{
    for(int i = 0; i < n; i++)
        if(boxes[current].dim[i] <= boxes[last].dim[i])
            return false;
    return true;
}

int lis(int limit)
{
    for(int i = 0; i <= limit; i++)
        dp[i][limit + 1] = 0;


    for(int i = 0; i < n; i++)
        boxes[0].dim[i] = -1 * inf;

    int choice1, choice2;

    for(int j = limit; j >= 1; j--)
        for(int i = 0; i < j; i++)
        {
            choice2 = choice1 = -1 * inf;
            choice1 = dp[i][j + 1];

            if(check(j, i))
                choice2 = 1 + dp[j][j + 1];

            if(choice1 > choice2)
                dp[i][j] = choice1;
            else
                dp[i][j] = choice2;
        }
    return dp[0][1];
}

void sort_dimen()
{
    int swap;
    bool flag;

    for(int i = 1; i <= k; i++)
    {
        for(int dim = 0; dim < n - 1; dim++)
        {
            flag = true;
            for(int din = 0; din < n - 1; din++)
                if(boxes[i].dim[din] >= boxes[i].dim[din + 1])
                {
                    swap = boxes[i].dim[din];
                    boxes[i].dim[din] = boxes[i].dim[din + 1];
                    boxes[i].dim[din + 1] = swap;
                    flag = false;
                }
            if(flag)
                break;
        }
    }
}

void sort_boxes()
{
    box swap;
    bool flag;

    for(int i = 1; i < k; i++)
    {
        flag = true;
        for(int j = 1; j < k; j++)
            if(boxes[j].dim[0] >= boxes[j + 1].dim[0])
            {
                swap = boxes[j];
                boxes[j] = boxes[j + 1];
                boxes[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return;
}


