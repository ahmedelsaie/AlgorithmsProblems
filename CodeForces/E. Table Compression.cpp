#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009
#define ll long long

void make_group(pair<int, int> x, int g);
void pre_process();
void build_graph();
void fn();

vector<pair<int, int> > arr[MAX];
set<pair<int, int> > rows_map[MAX], cols_map[MAX];

pair<int, int> indx_to_cord[MAX];
int row, col;
bool v[MAX];

int grp_prnt[MAX];
vector<int> grp_child[MAX];

int deg[MAX];
pair<int, int> sorted[MAX];
vector<int> edges[MAX];
int g = 0;

int que[2][MAX], val[MAX];

int main()
{
    scanf("%d %d", &row, &col);

    for(int i = 0, cnt = 0; i < row; i++)
        for(int j = 0; j < col; j++, cnt++)
        {
            int x;
            scanf("%d", &x);

            pair<int, int> tmp;
            tmp.first = x, tmp.second = cnt;

            arr[i].push_back(tmp);

            indx_to_cord[cnt].first = i, indx_to_cord[cnt].second = j;

            rows_map[i].insert(tmp);
            cols_map[j].insert(tmp);
        }

    pre_process();
    fn();


    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int tmp = arr[i][j].second;
            printf("%d ", val[tmp]);
        }
        printf("\n");
    }

    return 0;
}

void fn()
{
    int indx[2] = {0, 0};

    for(int i = 0; i < g; i++)
    {
        if(deg[i] == 0)
            que[0][indx[0]++] = i;
    }


    int flag = 0, num = 1;

    while(indx[flag])
    {
        indx[!flag] = 0;

        for(int i = 0; i < indx[flag]; i++)
        {
            int tmp = que[flag][i];
            for(int k = 0; k < grp_child[tmp].size(); k++)
                val[grp_child[tmp][k]] = num;

            for(int j = 0; j < edges[tmp].size(); j++)
            {
                deg[edges[tmp][j]]--;
                if(deg[edges[tmp][j]] == 0)
                    que[!flag][indx[!flag]++] = edges[tmp][j];
            }
        }

        num++;
        flag = (!flag);
    }
}

void pre_process()
{
    ///making of the group
    memset(v, 0, sizeof(v));

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(!v[arr[i][j].second])
                make_group(arr[i][j], g), g++;
        }

    build_graph();

}

void make_group(pair<int, int> x, int g)
{
    if(v[x.second])
        return;

    v[x.second] = 1;
    grp_prnt[x.second] = g;
    grp_child[g].push_back(x.second);

    int curr_row = indx_to_cord[x.second].first;
    int curr_col = indx_to_cord[x.second].second;

    ///go_right
    set<pair<int, int> >::iterator it1 = rows_map[curr_row].lower_bound(x);
    it1++;
    if(it1 != rows_map[curr_row].end())
    {
        if((*it1).first == x.first)
            make_group(*it1, g);
    }

    ///go left
    it1--;
    if(it1 != rows_map[curr_row].begin())
    {
        it1--;
        if((*it1).first == x.first)
            make_group(*it1, g);
    }



    ///go_down
    set<pair<int, int> >::iterator it2 = cols_map[curr_col].lower_bound(x);
    it2++;
    if(it2 != cols_map[curr_col].end())
    {
        if((*it2).first == x.first)
            make_group(*it2, g);
    }

    ///go up
    it2--;
    if(it2 != cols_map[curr_col].begin())
    {
        it2--;
        if((*it2).first == x.first)
            make_group(*it2, g);
    }
}

void build_graph()
{
    memset(deg, 0, sizeof(deg));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            sorted[j] = arr[i][j];

        sort(sorted, sorted + col);

        int prev = sorted[0].first, indx = 0;

        for(int j = 1; j < col; j++)
        {
            if(sorted[j].first > prev)
            {
                int x_g = grp_prnt[sorted[j].second];
                int y_g = grp_prnt[sorted[indx].second];
                deg[x_g]++;
                edges[y_g].push_back(x_g);
                prev = sorted[j].first;
                indx = j;
            }
        }
    }

    for(int j = 0; j < col; j++)
    {
        for(int i = 0; i < row; i++)
            sorted[i] = arr[i][j];

        sort(sorted, sorted + row);

        int prev = sorted[0].first, indx = 0;

        for(int i = 1; i < row; i++)
        {
            if(sorted[i].first > prev)
            {
                int x_g = grp_prnt[sorted[i].second];
                int y_g = grp_prnt[sorted[indx].second];

                deg[x_g]++;
                edges[y_g].push_back(x_g);
                prev = sorted[i].first;
                indx = i;
            }
        }
    }
}



