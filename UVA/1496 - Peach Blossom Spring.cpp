#include <bits/stdc++.h>
using namespace std;
#define MAX 55
#define MSKNUM 2500
#define ll long long

struct edge
{
    int x, y, weight;
};

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
void floydWarshall();
void buildMsks(int i, int carry, int msk);
void buildDpTable();
int fn(int currnt_msk);
int check_msk(int msk);
void addEdge(int src, int dest, int weight);
void reset();

const int inf = 1 << 25;
int n_nodes, n_edges, k, n;

vector<edge> graph[MAX];

int dp[MAX][MSKNUM], dp2[MSKNUM];
int msks[MAX][MSKNUM];
int indx[100];

int dist[MAX][MAX];
int edgesVal[MAX][MAX], edgesPlaces[MAX][MAX];
int cnt[MSKNUM];
int ownMsk[MAX];
int best[MSKNUM];

int main()
{
    for(int i = 0; i < 100; i++)
        indx[i] = 0;

    buildMsks(0, 0, 0);

    int cases = 0;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d %d", &n_nodes, &n_edges, &k);

        reset();

        for(int i = 0; i < n_edges; i++)
        {
            int src, dest, weight;
            scanf("%d %d %d", &src, &dest, &weight);
            src--, dest--;

            addEdge(src, dest, weight);
            addEdge(dest, src, weight);
        }


        floydWarshall();
        buildDpTable();

        for(int i = 0; i < (1 << 2 * k); i++)
        {
            int val = inf;
            for(int j = 0; j < n_nodes; j++)
                val = min(val, dp[j][i]);
            best[i] = val;
        }

        if(fn(0) >= inf || (2 * k > n_nodes)) cout << "No solution\n";
        else cout << fn(0) << endl;
    }

    return 0;
}

void buildDpTable()
{
    ///fill the ones first
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < n_nodes; j++)
        {
            int g = setbit(0, i, 1);

            g = g | ownMsk[i] | ownMsk[j];
            dp[j][g] = min(dp[j][g], dist[i][j]);
        }
    }

    int p = k;
    for(int i = n_nodes - k ; i < n_nodes; i++)
    {
        for(int j = 0; j < n_nodes; j++)
        {
            int g = setbit(0, p, 1);

            g = g | ownMsk[i] | ownMsk[j];
            dp[j][g] = min(dp[j][g], dist[i][j]);
        }
        p++;
    }

    for(int bits = 0; bits <= 2 * k; bits++)
    {
        for(int node = 0; node < n_nodes; node++)
        {
            for(int mskindx = 0; mskindx < indx[bits]; mskindx++)
            {
                int submask_upper = (msks[bits][mskindx]);
                int m = (1 << 2 * k) - 1;
                submask_upper = ( m & submask_upper);
                int bigmsk = msks[bits][mskindx] | ownMsk[node];

                for(int j = submask_upper; j > 0; j = (j - 1)&submask_upper)
                {
                    j = (j & m);

                    int &ret = dp[node][bigmsk];
                    int s = submask_upper ^ j;

                    int i1 = s | ownMsk[node];
                    int i2 = j | ownMsk[node];

                    ret = min(ret, dp[node][i2] + dp[node][i1]);
                }
            }
        }

        for(int node = 0; node < n_nodes; node++)
        {
            for(int destNode = 0; destNode < n_nodes; destNode++)
            {
                for(int mskindx = 0; mskindx < indx[bits]; mskindx++)
                {
                    int bigmsk = msks[bits][mskindx] | ownMsk[node];

                    int bigmsk2 = msks[bits][mskindx] | ownMsk[node] | ownMsk[destNode];
                    dp[destNode][bigmsk2] = min(dp[destNode][bigmsk2], dp[node][bigmsk] + dist[node][destNode]);
                }
            }
        }
    }


}

void buildMsks(int i, int carry, int msk)
{
    if(i == 10)
    {
        msks[carry][indx[carry]++] = msk;
    }
    else
    {
        buildMsks(i + 1, carry, msk);
        buildMsks(i + 1, carry + 1, setbit(msk, i, 1));
    }
}

int check_msk(int msk)
{
    int x = 0, y = 0;
    for(int i = 0; i < k; i++)
        x += getbit(msk, i);

    for(int i = k; i < 2 * k; i++)
        y += getbit(msk, i);

    return x == y;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

void floydWarshall ()
{
    /* dist[][] will be the output matrix that will finally have the shortest
      distances between every pair of vertices */
    int i, j, k2;


    for(int i = 0; i < n_nodes; i++)
        dist[i][i] = 0;
    /* Initialize the solution matrix same as input graph matrix. Or
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    /*  for (i = 0; i < n_nodes; i++)
      {
          dist[i][i] = 0;
          for (j = 0; j < graph[i].size(); j++)
          {
              int node = graph[i][j].y;
              dist[i][node] = graph[i][j].weight;
          }
      }
    */
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k2 = 0; k2 < n_nodes; k2++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < n_nodes; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < n_nodes; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                // if(dist[i][k2] <= inf && dist[k2][j] <= inf)
                if (dist[i][k2] + dist[k2][j] < dist[i][j])
                    dist[i][j] = dist[i][k2] + dist[k2][j];
            }
        }
    }


    // Print the shortest distance matrix
    // printSolution();
}

int fn(int currnt_msk)
{
    if(!cnt[currnt_msk])
        return inf;

    if(currnt_msk == (1 << 2 * k) - 1)
    {
        return 0;
    }
    int &ret = dp2[currnt_msk];
    if(ret != -1)
        return ret;
    ret = inf;

    int submask_upper = ~(currnt_msk);
    int m = (1 << 2 * k) - 1;
    submask_upper = ( m & submask_upper);

    for(int j = submask_upper; j > 0; j = (j - 1)&submask_upper)
    {
        j = (j & m);
        ret = min(ret, best[j] + fn((j | currnt_msk)));
    }

    return ret;
}

void addEdge(int src, int dest, int weight)
{
    if(src == dest)
        return;
    edge newEdge;
    newEdge.weight = weight;

    newEdge.x = src, newEdge.y = dest;
    if(edgesVal[src][dest] > weight)
    {
        if(edgesPlaces[src][dest] != -1)
        {
            graph[src][edgesPlaces[src][dest]].weight = weight;
        }
        else
        {
            graph[src].push_back(newEdge);
            edgesPlaces[src][dest] = graph[src].size() - 1;
        }

        edgesVal[src][dest] = weight;
    }

    dist[src][dest] = edgesVal[src][dest];
}

void reset()
{
    for(int i = 0; i < MSKNUM; i++)
        best[i] = inf;

    memset(ownMsk, 0, sizeof(ownMsk));
    for(int i = 0; i < k; i++)
        ownMsk[i] = setbit(0, i, 1);


    int p = k;
    for(int i = n_nodes - k ; i < n_nodes; i++)
    {
        ownMsk[i] = setbit(0, p, 1);

        p++;
    }


    for(int i = 0; i < MSKNUM; i++)
    {
        cnt[i] = check_msk(i);
    }

    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            edgesVal[i][j] = inf;

    memset(edgesPlaces, -1, sizeof(edgesPlaces));

    ///RESET GRAPH DATA STRUCTURE
    for(int i = 0; i < MAX; i++)
        graph[i].clear();

    ///FLOYED TABLE
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            dist[i][j] = inf;
    for(int i = 0; i < MAX; i++)
        dist[i][i] = 0;
    ///FIRST DP TABLE
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MSKNUM; j++)
            dp[i][j] = inf;

    memset(dp2, -1, sizeof(dp2));

}
