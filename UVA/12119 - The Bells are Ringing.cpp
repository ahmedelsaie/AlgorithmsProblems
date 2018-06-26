#include <bits/stdc++.h>
using namespace std;
#define MAX1 1000000
#define ll long long

struct node
{
    ll x, y, z;
};

void fn(ll x);
ll lcm(ll a, ll b);
ll gcd(ll a, ll b);
bool comp(node a, node b);

ll n;
int indx, cases = 1;
node ans[MAX1];

int main()
{
    while(scanf("%lld", &n) != EOF && n)
    {
        printf("Scenario %d:\n", cases++);
        fn(n);
        if(indx == 0)
            printf("Such bells don't exist\n");
        printf("\n");
    }


    return 0;
}

void fn(ll x)
{
    ll tmp[5];
    indx = 0;
    for(ll i = 1; i <= MAX1; i++)
        if(x % i == 0)
        {

            for(ll j = i + 1; j <= i + 25 && j <= MAX1; j++)
            {
                if(x % j == 0)
                    for(ll k = j + 1; k <= i + 25 && k <= MAX1; k++)
                    {
                        ll l = lcm(i, j);
                        l = lcm(l, k);
                        if(l == n)
                            printf("%lld %lld %lld\n", i, j, k), indx++;
                    }


            }
        }
}

bool comp(node a, node b)
{
    if(a.x == b.x)
    {
        if(a.y == b.y)
            return a.z < b.z;
        return a.y < b.y;
    }

    return a.x < b.x;
}

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}
