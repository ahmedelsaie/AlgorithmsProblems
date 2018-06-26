#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

int fn();

const int inf = 99999999;
char arr[MAX];

int main()
{
    int tc, cases = 1;

    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%s", arr);
        printf("Case %d: %d\n", cases++, fn());
    }

    return 0;
}

int fn()
{
    int freq[30];
    memset(freq, 0, sizeof(freq));

    int l = strlen(arr);

    for(int i = 0; i < l; i++)
        freq[arr[i] - 'a']++;

    int ret = inf;

    for(int i = 0; i < 26; i++)
        ret = min(ret, freq[i]);// printf("%c %d\n", 'a' + i, freq[i]);

    return ret;
}
