#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define ll long long
#define MAX 200009

int get_num(int x);
int array[MAX], n, m, n_ship, l_ship;
set<int> x, y;

int main()
{
    scanf("%d %d %d", &n, &n_ship, &l_ship);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &array[i]), array[i]--;

    int places = get_num(n);
    x.insert(n);
    y.insert(1);

    for(int i = 0; i < m; i++)
    {
        int small = *(y.upper_bound(-1 * array[i]));
        small = -1 * small;
        int big = *(x.upper_bound(array[i]));

        int with_me = big - small - 1;

        places -= get_num(with_me);
        places += get_num(array[i] - small - 1) + get_num(big - array[i] - 1);

        x.insert(array[i]);
        y.insert(-1*array[i]);

        if(places < n_ship)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}

int get_num(int x)
{
    if(x < l_ship)
        return 0;

    x -= l_ship;
    int ret = 1;
    ret += x / (l_ship + 1);

    return ret;
}
