#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int convert(char x);
void gen(int i);
void bsort();

int n;
int m = 0;
char arr[100];
char accum[100];
bool check[100];

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%s", arr);
        n = strlen(arr);

        bsort();

        for(int j = 0; j < n; j++)
            check[j] = true;

        m = 0;
        gen(0);
        printf("\n");
    }

    return 0;

}

void gen(int i)
{
    char current;
    char prev = '1';

    if(i == n)
    {
        accum[i] = '\0';
        if(m > 0)
            printf("\n");
        printf("%s", accum);
        m++;
        return;
    }

    for(int j = 0; j < n; j++)
    {
        if(check[j] == true)
        {
            current = arr[j];
            if(current != prev)
            {
                accum[i] = arr[j];
                check[j] = false;
                gen(i + 1);
                check[j] = true;
                prev = current;
            }
        }
    }

    return ;
}

void bsort()
{
    char swap;
    bool flag;
    for(int i = 0; i < n - 1; i++)
    {
        flag = true;
        for(int j = 0; j < n - 1; j++)
            if(convert(arr[j]) > convert(arr[j + 1]))
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

int convert(char x)
{
    char ref[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    int n = 0;
    while(ref[n] != '\0')
    {
        if(ref[n] == x)
            return n;
        else
            n++;
    }
    return -1;
}

