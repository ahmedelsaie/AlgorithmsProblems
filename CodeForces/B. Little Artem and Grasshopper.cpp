#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

ll len[MAX];
char strip[MAX];
int l;
bool v[MAX];

int main()
{
    scanf("%d", &l);
    scanf("%s", strip);

    for(int i = 0; i < l; i++)
        scanf("%lld", &len[i]);

    memset(v, 0, sizeof(v));

    ll curr = 0;
    int f = 0;
    while(true)
    {
        if(v[curr] == 1)
        {
            f = 1;
            break;
        }

        v[curr] = 1;

        if(strip[curr] == '>')
            curr += len[curr];
        else
            curr -= len[curr];

        if(curr >= l || curr < 0)
        {
            f = 0;
            break;
        }
    }

    printf("%s\n", f == 0 ? "FINITE" : "INFINITE");

    return 0;
}
