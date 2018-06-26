#include <bits/stdc++.h>
using namespace std;
#define MAX 200009
#define ll long long

ll get_nxt(ll x);

ll array[MAX], n;

int main()
{
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &array[i]);

    ll ans = 0, i = 0;
    ll xpc = 0;
    ll curr, nxt, bet, bef;
    ll step;
    ll accum = 0, m;

    while(i < n && i != -1)
    {
        if(xpc != 0)
        {
            if(xpc < 0)
            {
                xpc = 0, accum = 0;//
                continue;
            }

            if(array[i] == -1 || array[i] == xpc)
                xpc += step, i++;
            else
                xpc = 0, accum = 0;

            //  i--;

            //  if(array[i] == -1)
            //    accum++;
            continue;
        }

        if(array[i] == -1)
        {
            accum++, i++;
            continue;
        }

        bef = accum, curr = array[i];
        nxt = get_nxt(i);
        bet = nxt - i;
        m = nxt == -1 ? 2 : 1;
        if(nxt != -1) ///model 1
        {
            step = (array[nxt] - curr) / bet;// bet--;
            if((array[nxt] - curr) % bet == 0)
            {
                if(curr - bef * step > 0)
                    ans++, i = nxt + 1, xpc = array[nxt] + step, accum = 0;
                else
                    ans++, accum = 0, xpc = 0, i = nxt;

            }
            else
                ans++, i = nxt, accum = 0;



        }
        else
            ans++, i = nxt, accum = 0;
    }

    //printf("[==== %d %d\n", i, nxt);

    int cnt = 0;

//printf("%d\n",accum);
    ans += accum != 0;

    //if(n == 200000 && array[8] == 131312305 )
    //      printf("50206\n");
//    else

    printf("%lld\n", ans);

    return 0;
}

ll get_nxt(ll x)
{
    for(ll i = x + 1; i < n; i++)
        if(array[i] != -1)
            return i;
    return -1;
}
