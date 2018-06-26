#include <stdio.h>
#include <cstring>
struct game
{
    int petra, jan;
};

void merge(int start, int end);
void merge_sort(int start, int last);
bool compare(game x, game y);
game fn(int jan, int petra, int i);
game max(game x, game y);
bool valid_case(int jan, int petra);
bool base_case(int jan, int petra);
bool jan_can(int jan, int petra);
int get(int first, int last);
void build_accum();

bool visited[502][502];
game dp[502][502];
game array[1005];
game help[1005];
int accum[1005];
int n;
const int inf = 0x3f3f3f3f;
bool player;

int main()
{
    char input[20];
    game ans;
    int cases;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);
        scanf("%s", input);

        if(input[0] == 'J')
            player = true;
        else
            player = false;

        for(int i = 0; i < n; i++)
            scanf("%d %d", &array[i].petra, &array[i].jan);

        memset(visited, false, sizeof(visited));
        merge_sort(0, n - 1);
        build_accum();

        ans = fn(0, 0, 0);
        printf("%d %d\n", ans.petra, ans.jan);
    }
    return 0;
}

game fn(int jan, int petra, int i)
{
    if(!valid_case(jan, petra))
    {
        game ret;
        ret.jan = -1 * inf;
        ret.petra = -1 * inf;
        return ret;
    }

    bool &flag = visited[jan][petra];
    if(flag)
        return dp[jan][petra];
    flag = true;
    game temp, ret;

    if(base_case(jan, petra))
    {
        ret.petra = 0;
        ret.jan = 0;
        ret.jan += get(i + 1, n);
        return dp[jan][petra] = ret;
    }

    ret.jan = -1 * inf;
    ret.petra = -1 * inf;

    if(jan_can(jan, petra))
    {
        temp = fn(jan + 1, petra, i + 1);
        temp.jan += array[i].jan;
        ret = max(ret, temp);
    }

    temp = fn(jan, petra + 1, i + 1);
    temp.petra += array[i].petra;
    ret = max(ret, temp);

    return dp[jan][petra] = ret;
}

bool valid_case(int jan, int petra)
{
    if(player)///jan
    {
        if(petra > n / 2)
            return false;
        return true;
    }
    else ///petra
    {
        if(n % 2 == 0)
        {
            if(petra > n / 2)
                return false;
            return true;
        }
        else
        {
            if(petra > n / 2 + 1)
                return false;
            return true;
        }
    }
}

bool base_case(int jan, int petra)
{
    if(player)///jan
    {
        if(petra == n / 2)
            return true;
        return false;
    }
    else ///petra
    {
        if(n % 2 == 0)
        {
            if(petra == n / 2)
                return true;
            return false;
        }
        else
        {
            if(petra == n / 2 + 1)
                return true;
            return false;
        }
    }

}

bool jan_can(int jan, int petra)
{
    if(player)///jan
    {
        if(jan <= petra)
            return true;
        return false;
    }
    else
    {
        if(jan < petra)
            return true;
        return false;
    }
}

game max(game x, game y)
{
    if(x.jan > y.jan)
        return x;

    if(y.jan > x.jan)
        return y;

    if(x.petra > y.petra)
        return x;

    return y;
}

bool compare(game x, game y)
{
    if(x.petra > y.petra)
        return true;

    if(y.petra > x.petra)
        return false;

    if(x.jan < y.jan)
        return true;

    return false;
}

void merge_sort(int start, int last)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle);
    merge_sort(middle + 1, last);
    merge(start, last);
    return;
}

void merge(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = array[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            array[main_p] = array[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            array[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(compare(help[p1], array[p2]))
        {
            array[main_p] = help[p1];
            p1++;
        }
        else
        {
            array[main_p] = array[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

void build_accum()
{
    accum[0] = 0;
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        total += array[i].jan;
        accum[i + 1] = total;
    }
    return;
}

int get(int first, int last)
{
    return accum[last] - accum[first - 1];
}
