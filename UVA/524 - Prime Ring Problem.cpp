#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void reset_prime();
int isprime(float x);
int is_present(int i, int target);
void fn(int i);

int prime_memo[46];
int arr[20];
int n = 0;
int input[10000];

int main()
{
    int counter;

    reset_prime();
    int r = 1;
    int noof = 0;

    while((scanf("%d", &n)) != EOF)
    {
        input[noof] = n;
        noof++;
    }

    for(counter = 0; counter < noof; counter++)
    {
        arr[0] = 1;
        n = input[counter];
        printf("Case %d:\n", counter + 1);
        fn(1);
        if(counter < noof - 1)
            printf("\n");
    }

    return 0;
}

void reset_prime()
{
    int counter;
    for(counter = 0; counter < 46; counter++)
        prime_memo[counter] = -1;
}

int isprime(float x)
{
    if(prime_memo[(int)x] != -1)
        return prime_memo[(int)x];
    int y;
    int counter;
    y = x;
    x = sqrt(x);

    for(counter = 2; counter <= x; counter++)
    {

        if(y % counter == 0)
        {
            prime_memo[(int)y] = 0;
            return 0;
        }

    }

    prime_memo[(int)y] = 1;
    return 1;
}

int is_present(int i, int target)
{
    int counter;
    for(counter = 1; counter < i; counter++)
    {
        if(arr[counter] == target)
            return 1;

    }
    return 0;

}

void fn(int i)
{
    int counter;
    if(i == n)
    {
        if(isprime(arr[n - 1] + 1) == 1)
        {
            for(counter = 0; counter < n; counter++)
            {
                printf("%d", arr[counter]);
                if(counter < n - 1)
                    printf(" ");

            }

            printf("\n");
            return;
        }
    }

    for(counter = 2; counter <= n; counter++)
    {
        if(is_present(i, counter) == 0 && isprime(counter + arr[i - 1]) == 1)
        {
            arr[i] = counter;
            fn(i + 1);
        }
    }

}

