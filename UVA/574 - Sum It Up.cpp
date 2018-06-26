#include <bits/stdc++.h>
using namespace std;
#define MAX 20
#define ll long long

struct sum
{
    int arr[MAX];
    int l;
};

void fn(int i, int formed, int taken);
bool is_present(int taken);
bool check(int t);
void print(int r);
void bsort(int max);

sum form[800];
int n, target;
int arr[MAX];
int accum[MAX];
int total;

int main()
{
    bool flag = true;

    while(true)
    {
        scanf("%d %d", &target, &n);
        if(target == 0 && n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        total = 0;
        printf("Sums of %d:\n", target);
        bsort(n);
        fn(0, 0, 0);
        if(total == 0)
            printf("NONE\n");
    }

    return 0;
}

void fn(int i, int formed, int taken)
{
    if(formed > target)
        return;

    if(formed == target)
    {
        if(!is_present(taken))
        {
            for(int j = 0; j < taken; j++)
                form[total].arr[j] = accum[j];
            form[total].l = taken;
            total++;
            print(taken);
        }
        return;
    }

    if(i == n)
        return;


    accum[taken] = arr[i];
    fn(i + 1, formed + arr[i], taken + 1);

    fn(i + 1, formed, taken);
    return ;
}

bool is_present(int taken)
{
    for(int i = 0; i < total; i++)
    {
        if(form[i].l == taken)
            if(check(i))
                return true;
    }
    return false;
}

bool check(int t)
{
    for(int i = 0; i < form[t].l; i++)
        if(form[t].arr[i] != accum[i])
            return false;
    return true;
}

void print(int r)
{
    for(int i = 0; i < r; i++)
    {
        if(i > 0)
            printf("+");
        printf("%d", accum[i]);
    }
    printf("\n");
    return;
}

void bsort(int max)
{
    int swap;
    bool flag;
    for(int i = 0; i < max - 1; i++)
    {
        flag = true;
        for(int j = 0; j < max - 1; j++)
            if(arr[j] < arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}
