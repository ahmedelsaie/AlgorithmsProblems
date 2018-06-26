#include <bits/stdc++.h>
using namespace std;
#define MAX 10000007
#define ll long long

bool fn();

char arr1[MAX];
char arr2[MAX];

int main()
{
    while(scanf("%s %s", arr1, arr2) != EOF)
    {
        if(fn())
            printf("Yes");
        else
            printf("No");
        printf("\n");
    }
    return 0;
}

bool fn()
{
    int l1 = strlen(arr1);
    int l2 = strlen(arr2);
    int i = 0, j = 0;

    while(i < l1 && j < l2)
    {
        if(arr1[i] == arr2[j])
            i++, j++;
        else
            j++;
    }

    if(i == l1)
        return true;

    return false;
}
