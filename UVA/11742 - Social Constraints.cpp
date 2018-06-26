#include <stdio.h>
#include <cstring>

struct constr
{
    int a, b, c;
};

bool check_fn();
int get_dist(int x, int y);
void gen(int i);
int abs(int x);

constr fight[25];
int array[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int accum[9];
bool check[9];
int ans, n, m;

int main()
{
    memset(check, true, sizeof(check));
    while(true)
    {
        ans = 0;
        scanf("%d %d", &n, &m);
        if(m == 0 && n == 0)
            break;

        for(int i = 0; i < m; i++)
            scanf("%d %d %d", &fight[i].a, &fight[i].b, &fight[i].c);
        gen(0);
        printf("%d\n", ans);
    }
    return 0;
}

bool check_fn()
{
    int r;
    for(int i = 0; i < m; i++)
    {
        r = get_dist(fight[i].a, fight[i].b);
        if(fight[i].c > 0 && r > fight[i].c)
            return false;
        if(fight[i].c < 0 && r < abs(fight[i].c))
            return false;
    }
    return true;
}

int get_dist(int x, int y)
{
    int place_x = -1, place_y = -1;
    for(int i = 0; i < n; i++)
    {
        if(x == accum[i])
            place_x = i;
        if(y == accum[i])
            place_y = i;
        if(place_x != -1 && place_y != -1)
            break;
    }
    return abs(place_x - place_y);
}

void gen(int i)
{
    if(i == n)
    {
        if(check_fn())
            ans++;
        return;
    }

    for(int j = 0; j < n; j++)
        if(check[j] == true)
        {
            accum[i] = array[j];
            check[j] = false;
            gen(i + 1);
            check[j] = true;
        }

    return;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
