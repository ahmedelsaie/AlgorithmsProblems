#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

void fn(int x, int come, int mode, int t);
int dfs(int x, int flag);
int solve();
int go(int b, int b_dash);

vector<int> buttons[MAX];
pair<int, int> doors[MAX];
vector<pair<int, int> > curr;
int state[MAX], v_b[MAX], v_d[MAX], visited_b[MAX][2], visited_d[MAX], initial_state[MAX];
int flag = 0, n_buttons, n_doors;

int main()
{
    scanf("%d %d", &n_doors, &n_buttons);

    int cnt = 0;
    for(int i = 1; i <= n_doors; i++)
        scanf("%d", &initial_state[i]), doors[i].first = doors[i].second = -1, cnt += initial_state[i];

    for(int i = 1; i <= n_buttons; i++)
    {
        int x;
        scanf("%d", &x);

        for(int j = 0; j < x; j++)
        {
            int y = 0;
            scanf("%d", &y);
            buttons[i].push_back(y);

            if(doors[y].first == -1)doors[y].first = i;
            else doors[y].second = i;
        }
    }

    printf("%s\n", solve() == 1 ? "YES" : "NO");

    return 0;
}

int solve()
{
    memset(visited_b, -1, sizeof(visited_b));
    memset(visited_d, -1, sizeof(visited_d));
    memset(v_b, 0, sizeof(v_b));
    memset(v_d, 0, sizeof(v_d));

    for(int i = 1; i <= n_buttons; i++)
    {
        if(v_b[i] == 0)
        {
            curr.clear();
            dfs(i, 0);

            for(int j = 0; j < curr.size(); j++)
            {
                pair<int, int> tmp = curr[j];
                if(tmp.first == 1 && initial_state[tmp.second] == 0)
                {
                    if(!(go(doors[tmp.second].first, doors[tmp.second].second) || go(doors[tmp.second].second, doors[tmp.second].first)))
                        return 0;

                    break;
                }

            }
        }
    }

    return 1;
}

int go(int b, int b_dash)
{
    for(int i = 0; i < curr.size(); i++)
    {
        pair<int, int> tmp = curr[i];
        if(tmp.first == 1)
            state[tmp.second] = initial_state[tmp.second];
    }

    flag++;

    visited_b[b_dash][1] = flag;

    fn(b, 0, 0, 1);
    fn(b_dash, 0, 0, 0);

    for(int i = 0; i < curr.size(); i++)
    {
        pair<int, int> tmp2 = curr[i];

        if(tmp2.first == 1 && !state[tmp2.second])
        {
            if(!state[tmp2.second])
                return 0;
        }
    }

    return 1;
}

void fn(int x, int come, int mode, int t)
{
    if(mode == 0 && visited_b[x][t] == flag)
        return ;

    if(mode == 1 && visited_d[x] == flag)
        return ;

    if(mode == 0) ///button
    {
        visited_b[x][t] = flag;

        if(t)
        {
            for(int i = 0; i < buttons[x].size(); i++)
                state[buttons[x][i]] = !(state[buttons[x][i]]);
        }

        for(int i = 0; i < buttons[x].size(); i++)
            fn(buttons[x][i], x, !mode, 0);

    }
    else
    {
        visited_d[x] = flag;

        if(state[x] == 0)
        {
            if(come == doors[x].first && visited_b[doors[x].second][1] != flag)
                fn(doors[x].second, x, !mode, 1);
            else if(come == doors[x].second && visited_b[doors[x].first][1] != flag)
                fn(doors[x].first, x, !mode, 1);
        }
        else
        {
            fn(doors[x].first, x, !mode, 0);
            fn(doors[x].second, x, !mode, 0);
        }

    }

}

int dfs(int x, int flag)
{
    if(flag == 0) ///button
    {
        if(v_b[x])
            return 0;
        v_b[x] = 1;

        pair<int, int> tmp;
        tmp.first = 0, tmp.second = x;
        curr.push_back(tmp);

        for(int i = 0; i < buttons[x].size(); i++)
            dfs(buttons[x][i], !flag);
    }
    else
    {
        if(v_d[x])
            return 0;
        v_d[x] = 1;

        pair<int, int> tmp;
        tmp.first = 1, tmp.second = x;
        curr.push_back(tmp);

        dfs(doors[x].first, !flag);

        dfs(doors[x].second, !flag);
    }
}


