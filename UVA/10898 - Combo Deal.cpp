#include <stdio.h>
#include <cstring>
struct combo
{
    int a[10];
    int total, price;
};

int fn(int i1, int i2, int i3, int i4, int i5, int i6, int left);
int min(int x, int y);
void reset();

combo combos[10];
combo orders[10];
int item[10];
int dp[10][10][10][10][10][10];
int visited[10][10][10][10][10][10];
int no_combos, no_items, no_orders;
const int inf = 2e9; //99999999;//0xfffffff;//2e+9;
int cases = 0;

int main()
{
    int total, ans;
    bool flag = true;
    memset(visited, -1, sizeof(visited));

    while(scanf("%d", &no_items) == 1)
    {
        reset();

        for(int i = 0; i < no_items; i++)
            scanf("%d", &item[i]);

        scanf("%d", &no_combos);

        for(int i = 0; i < no_combos; i++)
        {
            total = 0;
            for(int j = 0; j < no_items; j++)
            {
                scanf("%d", &combos[i].a[j]);
                total += combos[i].a[j];
            }
            combos[i].total = total;
            scanf("%d", &combos[i].price);
        }


        scanf("%d", &no_orders);
        for(int i = 0; i < no_orders; i++)
        {
            total = 0;
            for(int j = 0; j < no_items; j++)
            {
                scanf("%d", &orders[i].a[j]);
                total += orders[i].a[j];
            }
            orders[i].total = total;
        }


        for(int i = 0; i < no_orders; i++)
        {
            ans = fn(orders[i].a[0], orders[i].a[1], orders[i].a[2], orders[i].a[3], orders[i].a[4], orders[i].a[5], orders[i].total);
            printf("%d", ans);
            printf("\n");
        }
        cases++;
    }
    return 0;
}

void reset()
{
    memset(item, 0, sizeof(item));

    for(int i = 0; i < 10; i++)
    {
        memset(combos[i].a, 0, sizeof(combos[i].a));
        memset(orders[i].a, 0, sizeof(orders[i].a));
    }
}

int fn(int i1, int i2, int i3, int i4, int i5, int i6, int left)
{
    if(left < 0 || i1 < 0 || i2 < 0 || i3 < 0 || i4 < 0 || i5 < 0 || i6 < 0)
        return inf;

    if(left == 0)
        return 0;

    int &ret = dp[i1][i2][i3][i4][i5][i6];
    int &flag = visited[i1][i2][i3][i4][i5][i6];
    if(flag == cases)
        return ret;
    ret = inf;
    flag = cases;
    int temp;

    for(int i = 0; i < no_combos; i++)
    {
        temp = fn(i1 - combos[i].a[0], i2 - combos[i].a[1], i3 - combos[i].a[2], i4 - combos[i].a[3], i5 - combos[i].a[4], i6 - combos[i].a[5], left - combos[i].total);
        if(temp != inf)
            temp += combos[i].price;
        ret = min(ret, temp);
    }



    temp = fn(i1 - 1, i2, i3, i4, i5, i6, left - 1);
    if(temp != inf)
        temp += item[0];
    ret = min(ret, temp);

    temp = fn(i1, i2 - 1, i3, i4, i5, i6, left - 1);
    if(temp != inf)
        temp += item[1];
    ret = min(ret, temp);

    temp = fn(i1, i2, i3 - 1, i4, i5, i6, left - 1);
    if(temp != inf)
        temp += item[2];
    ret = min(ret, temp);

    temp = fn(i1, i2, i3, i4 - 1, i5, i6, left - 1);
    if(temp != inf)
        temp += item[3];
    ret = min(ret, temp);

    temp = fn(i1, i2, i3, i4, i5 - 1, i6, left - 1);
    if(temp != inf)
        temp += item[4];
    ret = min(ret, temp);

    temp = fn(i1, i2, i3, i4, i5, i6 - 1, left - 1);
    if(temp != inf)
        temp += item[5];
    ret = min(ret, temp);

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

