#include <stdio.h>
#include <cstring>
struct cash
{
    double ben;
    int budget_left;
};

cash fn(int days, int left, int dish, int before);
cash max(cash x, cash y);
bool equal(cash x, cash y);
void trace(int days, int left, int dish, int before);

cash dp[22][102][52][3];
bool visited[22][102][52][3];
int cost[52];
int benifit[52];

int num_days, num_dishes, money;
const int inf = 99999999;

int main()
{
    cash ans;
    while(true)
    {
        scanf("%d %d %d", &num_days, &num_dishes, &money);
        if(num_days == 0 && num_dishes == 0 && money == 0)
            break;

        for(int i = 0; i < num_dishes; i++)
            scanf("%d %d", &cost[i], &benifit[i]);

        memset(visited, false, sizeof(visited));
        ans = fn(0, money, 51, 0);
        if(ans.ben > 0)
        {
            printf("%.1lf\n", ans.ben);
            trace(0, money, 51, 0);
        }
        else
            printf("0.0");

        printf("\n");

    }
    return 0;
}

cash fn(int days, int left, int dish, int before)
{
    if(left < 0)
    {
        cash ret;
        ret.ben = -1 * inf;
        return ret;
    }

    cash &ret = dp[days][left][dish][before];
    bool &flag = visited[days][left][dish][before];
    if(flag)
        return ret;
    flag = true;

    ret.ben = -1 * inf;

    if(days == num_days)
    {
        ret.ben = 0;
        ret.budget_left = left;
        return ret;
    }

    if(dish == num_dishes)
    {
        ret.ben = -1 * inf;
        return ret;
    }


    cash temp;

    for(int i = 0; i < num_dishes; i++)
    {
        if(i == dish)
        {
            if(!before)
            {
                temp = fn(days + 1, left - cost[i], i, before);
                ret = max(ret, temp);
            }
            else
            {
                temp = fn(days + 1, left - cost[i], i, false);
                temp.ben += .5 * benifit[i];
                ret = max(ret, temp);
            }
        }
        else
        {
            temp = fn(days + 1, left - cost[i], i, true);
            temp.ben += benifit[i];
            ret = max(ret, temp);
        }
    }

    return ret;
}

cash max(cash x, cash y)
{
    if(x.ben > y.ben)
        return x;

    if(y.ben > x.ben)
        return y;

    if(x.budget_left > y.budget_left)
        return x;

    return y;
}

void trace(int days, int left, int dish, int before)
{
    if(days == num_days)
        return;

    cash ret;
    ret.ben = -1 * inf;
    cash temp;

    int used_dish, used_left;
    bool used_before;

    for(int i = 0; i < num_dishes; i++)
    {
        if(left - cost[i] >= 0)
        {
            if(i == dish)
            {
                if(!before)
                {
                    temp = dp[days + 1][left - cost[i]][i][before];
                    ret = max(ret, temp);

                    if(equal(ret, temp))
                    {
                        used_dish = i;
                        used_left = left - cost[i];
                        used_before = before;
                    }
                }
                else
                {
                    temp = dp[days + 1][left - cost[i]][i][false];
                    temp.ben += .5 * benifit[i];
                    ret = max(ret, temp);
                    if(equal(ret, temp))
                    {
                        used_dish = i;
                        used_left = left - cost[i];
                        used_before = false;
                    }
                }
            }

            else
            {
                temp = dp[days + 1][left - cost[i]][i][true];
                temp.ben += benifit[i];
                ret = max(ret, temp);
                if(equal(ret, temp))
                {
                    used_dish = i;
                    used_left = left - cost[i];
                    used_before = true;
                }
            }
        }

    }
    if(days == 0)
        printf("%d", used_dish + 1);
    else
        printf(" %d", used_dish + 1);
    trace(days + 1, used_left, used_dish, used_before);
    return;
}

bool equal(cash x, cash y)
{
    return (x.ben == y.ben) && (x.budget_left == y.budget_left);
}
