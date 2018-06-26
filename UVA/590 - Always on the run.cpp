#include <stdio.h>
#include <climits>

int min(int x, int y);
void reset();
int fn(int city, int flight);

int dp[15][1005];
int cycles[100];
int book[100][40];
int max_flight;
int max_cities;
const int inf = 1 << 30;

int main()
{
    bool flag = true;
    int cases = 1;

    while(scanf("%d%d", &max_cities, &max_flight) != EOF)
    {
        if(max_cities == 0 && max_flight == 0)
            break;

        for(int i = 0; i < max_cities * (max_cities - 1); i++)
        {
            scanf("%d", &cycles[i]);
            for(int j = 0; j < cycles[i]; j++)
                scanf("%d", &book[i][j]);
        }

        reset();
        int r = fn(0, 0);

        printf("Scenario #%d\n", cases);

        if(r != inf)
            printf("The best flight costs %d.\n\n", r);
        else
            printf("No flight possible.\n\n");

        cases++;
    }

    return 0;
}

int fn(int city, int flight)
{
    if(flight == max_flight)
    {
        if(city == max_cities - 1)
            return 0;
        else
            return inf;
    }

    int &ret = dp[city][flight];
    if(ret != -1)
        return ret;
    ret = inf;
    int t;
    int temp = inf;
    int start = (city) * (max_cities - 1);
    int nxt = 0;
    for(int i = start; i < start + (max_cities - 1); i++)
    {
        if(nxt == city)
            nxt++;
        t = flight % cycles[i];
        if(book[i][t] != 0)
        {
            temp = fn(nxt, flight + 1);
            if(temp != inf)
                temp += book[i][t];
            ret = min(ret, temp);
        }
        nxt++;
    }
    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i = 0; i < max_cities + 1; i++)
        for(int j = 0; j < max_flight + 1; j++)
            dp[i][j] = -1;
}
