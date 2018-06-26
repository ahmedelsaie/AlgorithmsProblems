#include <bits/stdc++.h>
using namespace std;
#define MAX 305
#define ll long long

void pre_process();
ll fn();

ll array[MAX][MAX];
ll left1[MAX][MAX], right1[MAX][MAX], up[MAX][MAX], down[MAX][MAX];
ll n, m, t_up, t_down, t_same, des;
const ll inf = 9999999999;

ll s_ans, e_ans, j_ans, col_ans;

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%lld %lld %lld", &n, &m, &des);
    scanf("%lld %lld %lld", &t_same, &t_up, &t_down);

    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
            scanf("%lld", &array[i][j]);

    pre_process();

    ll ret = fn();
    printf("%lld %lld %lld %lld\n", s_ans, col_ans, e_ans, j_ans);

    return 0;
}

ll fn()
{
    set<pair<ll, ll>  >tree;
    pair<ll, ll> tmp, tmp2, tmp3;
    ll ret = inf;
    ll add, sub, val;

    set<pair<ll, ll>  >::iterator it, it2;

    for(ll s = 1; s <= n; s++)
        for(ll e = s + 2; e <= n; e++)
        {
            tree.clear();
            for(ll j = m; j >= 1; j--)
            {
                ///check
                if(j <= m - 2)
                {
                    sub = right1[s][j - 1] + left1[e][j - 1];
                    add = (up[e - 1][j] - up[s - 1][j]); // + (down[e][j] - down[s - 1][j]);
                    val = des - add + sub;
                    tmp2.first = val, tmp2.second = 0;
                    it = tree.lower_bound(tmp2);
                    tmp = *(it);
                    tmp.first += add - sub;
                    if(tmp.second>m)
                        m/0;

                    if(tmp.second < j + 2 || tmp.second>m)
                    {
                        it2 = it;
                        ll k = 3;
                        if(it2 != tree.end())
                            it2++, k = 0;
                        while(it2 != tree.end() && k < 3)
                        {
                            tmp = *(it2);
                            tmp.first += add - sub;
                            if(tmp.second >= j + 2)
                                break;
                            else
                                tmp.first = inf;
                            k++, it2++;
                        }
                        tmp;

                        tmp3.first = inf;
                        tmp3.second = m;
                        it2 = it, k = 3;
                        if(it2 != tree.begin())
                            it2--, k = 0;
                        while(it2 != tree.begin()&& k < 3)
                        {

                            tmp3 = *(it2);

                            tmp3.first += add - sub;
                            if(tmp3.second >= j + 2)
                                break;
                            else
                                tmp3.first = inf;
                            k++, it2--;
                        }


                        if(abs(tmp.first - des) > abs(tmp3.first - des))
                            tmp = tmp3;


                    }


                    if(abs(des - tmp.first) < ret)
                    {
                        //printf("hi");
                        //   printf("%d\n", tmp.first);
                        ret = abs(des - tmp.first);
                        s_ans = s, e_ans = e;
                        col_ans = j;
                        //   printf("hi %d\n", tmp.second);
                        j_ans = tmp.second;
                    }

                }

                ///update the tree
                //if(j <= m)
                {
                    tmp.first = right1[s][j - 1] + left1[e][j - 1] + (down[e - 1][j] - down[s - 1][j]);
                    tmp.second = j;
                    tree.insert(tmp);
                }
            }
        }

    return ret;


}

void pre_process()
{
    ll tmp;
    ///right
    for(ll i = 1; i <= n; i++)
    {
        right1[i][1] = 0;
        for(ll j = 1; j < m; j++)
        {
            if(array[i][j] < array[i][j + 1])
                tmp = t_up;
            else if(array[i][j] > array[i][j + 1])
                tmp = t_down;
            else
                tmp = t_same;

            right1[i][j] = right1[i][j - 1] + tmp;

            //if(i == 4)
            //  printf("%d ", right1[i][j]);
        }
    }

    ///  printf("donen");
    ///left
    for(ll i = 1; i <= n; i++)
    {
        left1[i][1] = 0;
        for(ll j = 1; j < m; j++)
        {
            if(array[i][j] > array[i][j + 1])
                tmp = t_up;
            else if(array[i][j] < array[i][j + 1])
                tmp = t_down;
            else
                tmp = t_same;

            left1[i][j] = left1[i][j - 1] + tmp;
        }
    }

    ///down
    for(ll j = 1; j <= m; j++)
    {
        down[0][j] = 0;
        for(ll i = 1; i < n; i++)
        {
            if(array[i][j] < array[i + 1][j])
                tmp = t_up;
            else if(array[i][j] > array[i + 1][j])
                tmp = t_down;
            else
                tmp = t_same;

            down[i][j] = down[i - 1][j] + tmp;
        }
    }
    ///up
    for(ll j = 1; j <= m; j++)
    {
        up[0][j] = 0;
        for(ll i = 1; i < n; i++)
        {
            if(array[i][j] > array[i + 1][j])
                tmp = t_up;
            else if(array[i][j] < array[i + 1][j])
                tmp = t_down;
            else
                tmp = t_same;
            //printf("%d %d %d %d\n", i, j, array[i][j], array[i + 1][j]);
            up[i][j] = up[i - 1][j] + tmp;
        }
    }
}

