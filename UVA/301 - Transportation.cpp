#include <stdio.h>
struct order
{
    int start;
    int end;
    int passen;
};

int max(int x, int y);
int fn(int city, int curr_order, int left_passen, bool flag);
void bsort();

int people_arrive[25];
order orders[25];
int no_city, no_order, train_cap;
const int inf = 99999999;

int main()
{
    bool flag = true;
    for(int i = 0; i < 25; i++)
        people_arrive[i] = 0;
    while(true)
    {
        scanf("%d %d %d", &train_cap, &no_city, &no_order);

        if(train_cap == 0 && no_city == 0 && no_order == 0)
            break;

        for(int i = 0; i < no_order; i++)
            scanf("%d %d %d", &orders[i].start, &orders[i].end, &orders[i].passen);
        bsort();
        int ans = fn(0, 0, train_cap, true);

        printf("%d\n", ans);
    }

    return 0;
}

int fn(int city, int curr_order, int left_passen, bool flag)
{
    if(left_passen < 0)
        return -1 * inf;

    if(city == no_city || curr_order == no_order)
        return 0;

    if (flag)
        left_passen += people_arrive[city];

    int temp = -1 * inf;
    int ret = -1 * inf;


    if(orders[curr_order].start == city)
    {
        if(orders[curr_order + 1].start == city)
        {
            temp = fn(city, curr_order + 1, left_passen, false);
            ret = max(temp, ret);

            people_arrive[orders[curr_order].end] += orders[curr_order].passen;
            temp = fn(city, curr_order + 1, left_passen - orders[curr_order].passen, false);
            if(temp != -1 * inf)
                temp += orders[curr_order].passen * (orders[curr_order].end - orders[curr_order].start);
            ret = max(temp, ret);
            people_arrive[orders[curr_order].end] -= orders[curr_order].passen;
        }
        else
        {
            temp = fn(city + 1, curr_order + 1, left_passen, true);
            ret = max(temp, ret);

            people_arrive[orders[curr_order].end] += orders[curr_order].passen;
            temp = fn(city + 1, curr_order + 1, left_passen - orders[curr_order].passen, true);
            if(temp != -1 * inf)
                temp += orders[curr_order].passen * (orders[curr_order].end - orders[curr_order].start);
            ret = max(temp, ret);
            people_arrive[orders[curr_order].end] -= orders[curr_order].passen;
        }
    }
    else
        temp = fn(city + 1, curr_order, left_passen, true);

    ret = max(ret, temp);


    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void bsort()
{
    order swap;
    bool flag;
    for(int i = 0; i < no_order - 1; i++)
    {
        flag = true;
        for(int j = 0; j < no_order - 1; j++)
            if(orders[j].start > orders[j + 1].start)
            {
                swap = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}
