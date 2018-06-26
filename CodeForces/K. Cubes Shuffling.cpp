#include <bits/stdc++.h>
using namespace std;
int array[105];
int sec[52];
int n;
void fn();

int main()
{
    freopen("cubes.in", "r", stdin);
    // freopen("c.out", "w", stdout);

    int tc, p = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        printf("Case %d:\n", p++);
        fn();
        //  if(tc)
         printf("\n");
    }


    return 0;
}

void fn()
{
    int i = n - 1, j = 0;
    bool flag = false;

    sort(array, array + n);

    while(i >= 0)
    {
        sec[j] = array[i], j++;

        if(i - 1 < 0)
            break;

        if(i != n - 1)
            printf(" ");
        printf("%d", array[i - 1]);
        flag = true;

        i -= 2;
    }

    for(int i = j - 1; i >= 0; i--)
    {
        if(i != j - 1)
            printf(" ");
        else if(flag)
            printf(" ");

        printf("%d", sec[i]);

    }

    return;
}
