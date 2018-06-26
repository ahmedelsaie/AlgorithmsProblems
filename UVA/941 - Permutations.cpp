#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void  fn(long long before, int p);
long long permutation_of_repeated_chars(int p);
int nxt(int x);

char arr[35];
char ans[35];
int letters[26];
int length;
long long target;

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%s", arr);
        scanf("%lld", &target);
        length = strlen(arr);

        for(int i = 0; i < 26; i++)
            letters[i] = 0;

        for(int i = 0; i < length; i++)
            letters[arr[i] - 'a']++;

        target++;
        fn(1, 0);
        printf("%s\n", ans);
    }

    return 0;
}

int nxt(int x)
{
    for(int i = x; i < 26; i++)
        if(letters[i])
            return i;

    return -1;
}

long long permutation_of_repeated_chars(int p)
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

    return n;
}

void  fn(long long before, int p)
{
    if(p == length)
    {
        ans[p] = '\0';
        return;
    }

    int x = 0;
    long long upper = before - 1;
    long long lower = before - 1;
    int flag = 0;

    while(upper < target)
    {
        if(flag == 0)
            x = nxt(x);
        else
            x = nxt(x + 1);
        lower = upper + 1;

        letters[x]--;
        upper = upper + permutation_of_repeated_chars(p + 1);
        letters[x]++;


        flag++;
    }

    x = nxt(x);

    letters[x]--;
    ans[p] = x + 'a';

    fn(lower, p + 1);

    return;
}

