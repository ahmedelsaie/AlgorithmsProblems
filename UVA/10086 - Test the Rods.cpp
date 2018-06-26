#include <stdio.h>
#include <cstring>
struct site
{
    int n;
    int first[25];
    int sec[25];
};

int min(int x, int y);
int fn(int place, int left, int sec);
void trace (int place, int left, int sec);

site array[35];
int dp[35][305];
int n;
const int inf = 99999999;

int main()
{
    int first, sec, x, ans;

    while(true)
    {
        scanf("%d %d", &first, &sec);
        if(first == 0 && sec == 0)
            break;

        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            array[i].n = x;

            for(int j = 1; j <= x; j++)
                scanf("%d", &array[i].first[j]);

            for(int j = 1; j <= x; j++)
                scanf("%d", &array[i].sec[j]);
        }
        memset(dp, -1, sizeof(dp));
        ans = fn(0, first, sec);
        printf("%d\n", ans);
        trace(0, first, sec);
        printf("\n");
    }
    return 0;
}

int fn(int place, int left, int sec)
{
    if(left < 0 || sec < 0)
        return inf;

    int &ret = dp[place][left];
    if(ret != -1)
        return ret;

    if(place == n || (left == 0 && sec == 0))
        return ret = 0;

    ret = inf;

    int limit = array[place].n;
    int temp;

    for(int i = 0; i <= limit; i++)
    {
        temp = fn(place + 1, left - i, sec - (limit - i)) + array[place].first[i] + array[place].sec[limit - i];
        ret = min(ret, temp);
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


void trace (int place, int left, int sec)
{
    if(place == n || (left == 0 && sec == 0))
        return ;

    int ret = inf;

    int limit = array[place].n;
    int temp, sent_i;

    for(int i = 0; i <= limit; i++)
        if(left - i >= 0 && sec - (limit - i) >= 0)
        {
            temp = dp[place + 1][left - i] + array[place].first[i] + array[place].sec[limit - i];
            if(temp < ret)
            {
                ret = temp;
                sent_i = i;
            }
        }

    if(place > 0)
        printf(" ");
    printf("%d", sent_i);

    trace (place + 1, left - sent_i, sec - (limit - sent_i));
    return ;
}
