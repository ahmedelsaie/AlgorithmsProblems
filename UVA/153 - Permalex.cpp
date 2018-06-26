#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

long long fn(int p, long long c);
void intializer();
int permutation_of_repeated_chars(int p);

char arr[35];
int letters[26];
int length;

int main()
{
    while(true)
    {
        scanf("%s", arr);
        if (arr[0] == '#')
            break;
        intializer();
        printf("%10d\n", fn(0, 0));
    }

    return 0;
}

void intializer()
{
    length = strlen(arr);
    for(int i = 0; i < 26; i++)
        letters[i] = 0;

    for(int i = 0; i < length; i++)
        letters[arr[i] - 'a']++;
}

int permutation_of_repeated_chars(int p)
{
    int nr_denominators = 0;
    int denominators[50];

    for (int i = 0; i < 26; i++)
        for (int j = 2; j <= letters[i]; j++)
            denominators[nr_denominators++] = j;

    long long n = 1, d = 1;
    for (int i = 2; i <= length - p; i++)
    {
        n *= i;
        if (nr_denominators > 0)
            d *= denominators[--nr_denominators];
        if (d != 1 && !(n % d))
        {
            n /= d;
            d = 1;
        }
    }
    return static_cast<int>(n);
}

long long  fn(int p, long long c)
{
    if(p == length)
        return c + 1;

    char current = arr[p];
    int counter;

    for(counter = 0; counter < current - 'a'; counter++)
    {
        if(letters[counter])
        {
            letters[counter]--;
            c += permutation_of_repeated_chars(p + 1);
            letters[counter]++;
        }
    }
    letters[counter]--;

    return fn(p + 1, c);
}
