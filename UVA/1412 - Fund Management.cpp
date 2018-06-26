#include <bits/stdc++.h>
using namespace std;
#define MAX 109
#define ll long long
#define maxState 12875
double fn();
int combineToKey(int arr[]);
void getStocksNumber(int x, int arr[]);
void buid_indx(int j, int with_me, int stocks);
void reset();
void buildResult();

map<int, int> indx;
const double INF = 1e30;
int days, n_indx;
int stock_total_limit;
int n_stock;
int stock_limit[16];
bool v[MAX][maxState];
double dp[MAX][maxState];
int indexes[maxState];
double stockPrice[16][MAX];
double money_first;
int n_days;
char stockName[50][50];
int lotSize[16];
int trace_action[MAX][maxState];
int result[MAX];

int main()
{
    int cases = 0;
    while(scanf("%lf%d%d%d", &money_first, &n_days, &n_stock, &stock_total_limit) == 4)
    {
        if(cases++)printf("\n");

        for(int i = 1; i <= n_stock; i++)
        {
            scanf("%s%d%d", stockName[i], &lotSize[i], &stock_limit[i]);

            for(int days = 1; days <= n_days; days++)
            {
                scanf("%lf", &stockPrice[i][days]);

                stockPrice[i][days] *= lotSize[i];
                //printf("sas %lf\n",stockPrice[i][days]);
            }
        }

        printf("%.2lf\n", fn());

        buildResult();

//printf("%lf\n",dp[n_days][indx[10]]);
        for(int i = 1; i <= n_days; i++)
        {
            if(result[i] == 0)
                printf("HOLD");
            else if(result[i] > 0)
                printf("BUY %s", stockName[abs(result[i])]);
            else
                printf("SELL %s", stockName[abs(result[i])]);

            printf("\n");
        }

    }



    return 0;
}

void buildResult()
{
    int currentIndx = 0;
    trace_action[n_days][0];


    for(int days = n_days; days >= 1; days--)
    {
        //      if(days == n_days + 1)
        //        printf("sassijaso %d\n", trace_action[days][0]);
        // printf("%d kmk\n",indx[currentIndx]);
        int key = indx[currentIndx];
        result[days] = trace_action[days][key];

        int noOfPastStocks[10];
        getStocksNumber(currentIndx, noOfPastStocks);
        //     printf("%d %d %d\n",noOfPastStocks[1],noOfPastStocks[2],trace_action[days][key]);

        if(result[days] != 0)
            noOfPastStocks[abs(result[days])] += (result[days] > 0 ? -1 : 1);

        currentIndx = combineToKey(noOfPastStocks);
    }
}

double fn()
{
    reset();

    v[0][0] = true;
    dp[0][0] = money_first;

    for(int days = 1; days <= n_days; days++)
    {
        for(int stockIndx = 0; stockIndx < n_indx; stockIndx++)
        {
            int x = indexes[stockIndx];
            if(dp[days - 1][stockIndx] < -1)
                continue;

            int noOfPastStocks[20];
            getStocksNumber(x, noOfPastStocks);
            int takenStocks = 0;
            for(int j = 1; j <= n_stock; j++)
                takenStocks += noOfPastStocks[j];

            ///keep as it is
            if(dp[days][stockIndx] <= dp[days - 1][stockIndx])
            {
                v[days][stockIndx] = true;
                dp[days][stockIndx] = dp[days - 1][stockIndx];

                trace_action[days][stockIndx] = 0;
            }

            ///sell anyone
            for(int k = 1; k <= n_stock; k++)
            {
                if(noOfPastStocks[k] > 0)
                {
                    double currentMoney = dp[days - 1][stockIndx] + stockPrice[k][days];
                    noOfPastStocks[k]--;
                    int key = combineToKey(noOfPastStocks);
                    noOfPastStocks[k]++;

                    key = indx[key];

                    if(dp[days][key] <= currentMoney)
                    {
                        v[days][key] = true;
                        dp[days][key] = currentMoney;
                        trace_action[days][key] = -k;
                    }
                }
            }


            ///buy more stocks
            for(int k = 1; k <= n_stock; k++)
            {
                double eps = 1e-3;

                if(noOfPastStocks[k] < stock_limit[k] && takenStocks + 1 <= stock_total_limit && dp[days - 1][stockIndx] >= stockPrice[k][days])
                {
                    double currentMoney = dp[days - 1][stockIndx] - stockPrice[k][days];

                    noOfPastStocks[k]++;
                    int key = combineToKey(noOfPastStocks);
                    noOfPastStocks[k]--;

                    key = indx[key];
                    if(dp[days][key] <= currentMoney)
                    {
                        v[days][key] = true;
                        dp[days][key] = currentMoney;
                        trace_action[days][key] = k;
                    }
                }
            }

        }
    }

    return dp[n_days][0];
}

int combineToKey(int arr[])
{
    int ret = 0;
    for(int i = 1; i <= n_stock; i++)
        ret = ret * 10 + arr[i];

    return ret;
}

void getStocksNumber(int x, int arr[])
{
    memset(arr, 0, sizeof(arr));

    int j = n_stock;
    for(int i = 1; i <= n_stock; i++)
    {
        if(x)
            arr[j--] = x % 10, x = x / 10;
        else
            arr[j--] = 0;
    }
}

void reset()
{
    //  memset(v, 0, sizeof(v));
    // memset(dp, 0.0, sizeof(dp));

    n_indx = 0;
    indx.clear();

    buid_indx(1, 0, 0);
//printf("%d\n",n_indx);
    for(int day = 0; day <= n_days + 3; day++)
        for(int s = 0; s <= n_indx + 3; s++)
            dp[day][s] = -INF, v[day][s] = 0;
}

void buid_indx(int j, int with_me, int stocks)
{
    if(j > n_stock)
        indexes[n_indx] = stocks, indx[stocks] = n_indx++;//printf("%d\n",stocks);
    else
    {
        for(int i = 0; i <= stock_limit[j] && with_me + i <= stock_total_limit; i++)
            buid_indx(j + 1, with_me + i, stocks * 10 + i);
    }
}
