#include <stdio.h>
#include <cstring>
#define MAX 505
struct edge
{
    int n1, n2, val;
    int node;
};

struct node
{
    bool visited;
    int heap_place;
};


int dist(int a, int b);
int min(int x, int y);
int abs(int x);
void build_matrix();
void swap(int i, int j);
void build_heap(int size);
void heapify(int i, int size);
void print_heap(int size);
int update(int node);
int prim();

edge cut[(MAX*MAX) / 2];
edge help[(MAX*MAX) / 2];
node state [MAX];
char input [MAX][5];
int graph[MAX][MAX];
int n; ///nodes
int n_cut;


int main()
{
    int ans, cases;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", input[i]);
        build_matrix();
        ans = prim();

        printf("%d", ans);
        printf("\n");
    }

    return 0;
}

void build_matrix()
{
    input[n][0] = '0';
    input[n][1] = '0';
    input[n][2] = '0';
    input[n][3] = '0';

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            graph[i][j] = dist(i, j);
            graph[j][i] = dist(i, j);
        }

    for(int i = 0; i < n; i++)
        state[i].visited = false;

    return ;
}

int prim()
{
    int with_me = 0;
    int nxt = 0, node = 0;
    n_cut = 0;
    cut[0].val = 0;
    int ret = 0;
    int comp = 999999;

    for(int i = 0; i < n; i++)
    {
        if(dist(i, n) < comp)
        {
            comp = dist(i, n);
            node = i;
        }
    }
    ret += comp;
    while(with_me < n)
    {
        ret += cut[nxt].val;
        nxt = update(node);

        if(state[cut[nxt].n1].visited == false)
            node = cut[nxt].n1;
        else
            node = cut[nxt].n2;

        with_me++;
    }

    return ret;
}

int update(int node)
{
    state[node].visited = true;
    int j = 0;

    for(int i = 0; i < n; i++)
    {
        if(state[i].visited == false && i != node)
        {
            //  printf("sfjnfjsdonjfsa\n");
            help[j].n1 = node;
            help[j].n2 = i;

            help[j].val = graph[i][node];
            j++;
        }
    }

    for(int i = 0; i < n_cut; i++)
        help[j++] = cut[i];

    int i = 0;
    int ret = 9999999;
    int index = 0;
    for(int k = 0; k < j; k++)
    {
        if((help[k].n1 == node && state[help[k].n2].visited == true) || (help[k].n2 == node && state[help[k].n1].visited == true))
            continue;
        cut[i++] = help[k];


        if(help[k].val < ret)
        {
            ret = help[k].val;
            index = i - 1;
        }

    }
    n_cut = i;

    return index;
}

void swap(int i, int j)
{
    edge tmp = cut[i];
    cut[i] = cut[j];
    cut[j] = tmp;

    int i_a = cut[i].node;
    int j_a = cut[j].node;

    state[i_a].heap_place = j;
    state[j_a].heap_place = i;
    return ;
}

void build_heap(int size)
{
    for(int i = size / 2 + 2; i >= 0; i--)
        heapify(i, size);
    return ;
}

void heapify(int i, int size)
{
    if(i >= size / 2 + 2)
        return;
    ///one leaf
    if(2 * i + 1 < size && 2 * i + 2 >= size)
    {
        if(cut[i].val > cut[2 * i + 1].val)
            swap(i, 2 * i + 1);

        heapify(2 * i + 1, size);
    }

    ///two leaves
    if(2 * i + 1 < size && 2 * i + 2 < size)
    {
        if(cut[2 * i + 1].val <= cut[2 * i + 2].val && cut[2 * i + 1].val < cut[i].val)
            swap(2 * i + 1, i);

        else if(cut[2 * i + 2].val <= cut[2 * i + 1].val && cut[2 * i + 2].val < cut[i].val)
            swap(2 * i + 2, i);

        heapify(2 * i + 1, size);
        heapify(2 * i + 2, size);
    }
    return ;
}


void print_heap(int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", cut[i].val);
    printf("\n");
    return;
}

int dist(int a, int b)
{
    int result = 0;
    int aa, bb;
    for(int i = 0; i < 4; i++)
    {
        aa = input[a][i] - '0';
        bb = input[b][i] - '0';
        result += min(abs(aa - bb), 10 - abs(aa - bb));
    }
    return result;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    return y;
}
