#include <stdio.h>
#include <cstring>
int cost_one, cost_pack, pack_times, n_rides;
using namespace std;
int fn();

int main()
{
    scanf("%d %d %d %d", &n_rides, &pack_times, &cost_one, &cost_pack);
    printf("%d\n", fn());
    return 0;
}

int fn()
{
    int ret=0;
    if(cost_one * pack_times > cost_pack)
    {
        int r = n_rides / pack_times;
        ret = r * cost_pack;
        n_rides = n_rides %pack_times;
        if(n_rides > 0)
        {
            if(n_rides * cost_one < cost_pack)
                ret += n_rides * cost_one;
            else
                ret += cost_pack;
            return ret;

        }
        else
            return ret;
    }
    else
        return n_rides * cost_one;
}
