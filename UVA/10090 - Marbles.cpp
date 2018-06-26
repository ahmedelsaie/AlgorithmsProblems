#include <stdio.h>
#include <cstring>
typedef long long ll;

struct block
{
    ll p, q, g;
};

ll gcd(ll a, ll b);
block ext_gcd(ll a, ll b);

ll total, x_cap, y_cap, x_cost, y_cost;
block fn();
bool shift;

int main()
{
    block ans;
    while(true)
    {
        scanf("%d", &total);
        if(total == 0)
            break;

        scanf("%d %d", &x_cost, &x_cap);
        scanf("%d %d", &y_cost, &y_cap);
        ans = fn();

        if(ans.g == -1 && ans.p == -1 && ans.q == -1)
            printf("failed");
        else
        {
            if(!shift)
                printf("%lld %lld", ans.p, ans.q);
            else
                printf("%lld %lld", ans.q, ans.p);
        }

        printf("\n");
    }

    return 0;
}

block fn()
{
    shift = false;
    block ans;
    ll r = gcd(x_cap, y_cap);
    if(total % r)
    {
        ans.g = -1 , ans.p = -1 , ans.q = -1;
        return ans;
    }

    double avg1 = (double)x_cap / (double)x_cost;
    double avg2 = (double)y_cap / (double)y_cost;

    if(avg1 < avg2)
    {
        ///swaping
        ll swap_cap = x_cap;
        ll swap_cost = x_cost;
        x_cap = y_cap , x_cost = y_cost;
        y_cap = swap_cap , y_cost = swap_cost;
        shift = true;
    }

    ans = ext_gcd(x_cap, y_cap);

    ll con = 1;
    if(r != total)
        con = total / r;

    ll inc1 = y_cap / r;
    ll inc2 = x_cap / r;

    ans.p *= con;
    ans.q *= con;
    ll k;

    if(ans.p < 0)   /// adjust a >= 0
    {
        k = -(ans.p / inc1) + (ans.p % inc1 != 0);
        ans.p += k * inc1, ans.q -= k * inc2;
    }

    if(ans.q < 0)   /// adjust b >= 0
    {
        k = -(ans.q / inc2) + (ans.q % inc2 != 0);
        ans.p -= k * inc1, ans.q += k * inc2;
    }

    if(ans.p < 0 || ans.q < 0)
    {
        ans.g = -1, ans.p = -1, ans.q = -1;
        return ans;
    }

    ll n = ans.q / inc2;
    ans.q = ans.q - inc2 * n;

    ans.p = ans.p + inc1 * n;

    return ans;
}

block ext_gcd(ll a, ll b)
{
    if (b == 0)
    {
        block ret;
        ret.p = 1;
        ret.q = 0;
        ret.g = a;
        return ret;
    }

    /// 1 * a + 0 * b = gcd(a, b)
    block nextSolution = ext_gcd(b, a % b);
    ll p = nextSolution.p;
    ll q = nextSolution.q;
    ll g = nextSolution.g;
    block ret;
    ret.p = q;
    ret.q = p - a / b * q;
    ret.g = g;

    return ret;
}

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
