#include <stdio.h>

int array[100009];

int n;
int collect(int start);
void fn();
int get_diff(int start, int end);

int main()
{
    int cases = 1;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        printf("Case %d:\n", cases);
        fn();
        cases++;
        printf("\n");
    }
    return 0;
}

void fn()
{
    int i = 0;
    int start, end;
    int help;
    while(i < n)
    {
        start = i;
        end = collect(start);
        if(end == -1)
        {
            printf("0%d\n", array[start]);
            i++;
        }
        else
        {
            help = get_diff(start, end);
            printf("0%d-%d\n", array[start], help);
            i = end + 1;
        }
    }
}

int get_diff(int start, int end)
{
    int n = 0;
    int x, y;
    x = array[start];
    y = array[end];
    int ans = 0;
    while(x && y)
    {
        if(x % 10 != y % 10)
            ans = n;

        n++;
        x = x / 10;
        y = y / 10;
    }
    ans++;
    int r = 1;
    for(int i = 0; i < ans; i++)
        r = r * 10;
    return array[end] % r;
}

int collect(int start)
{
    long long current = array[start];
    int i = start + 1;
    while(i < n)
    {
        if(array[i] - 1 == current)
        {
            current = array[i];
            i++;
        }
        else
            break;
    }
    if(i == start + 1)
        return -1;
    else
        return i - 1;
}
