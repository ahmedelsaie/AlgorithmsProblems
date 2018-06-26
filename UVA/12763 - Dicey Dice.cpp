#include <bits/stdc++.h>
using namespace std;
#define MAX 105
#define ll long long

pair<double, double> max(pair<double, double> x, pair<double, double> y, int flag);
pair<double, double> fn(int player, int t1, int t2);

int dice[3][20], tc;
char input[MAX], first, sec;

int main()
{
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%s", input);
        if(input[0] == 'A')
            first = 'A', sec = 'B';
        else
            first = 'B', sec = 'A';

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 6; j++)
                scanf("%d", &dice[i][j]);
        pair<double, double> ret = fn(0, 0, 0);

        if(ret.first == ret.second)
            printf("fair");
        else if (ret.first > ret.second)
            printf("%c", first);
        else if (ret.first < ret.second)
            printf("%c", sec);

        printf("\n");
    }

    return 0;
}

pair<double, double> fn(int player, int t1, int t2)
{
    if(player == 2)
    {
        double tmp = (double)1 / (double)36.0;
        tmp = 1.0;
        pair<double, double> ret;
        ret.first = ret.second = 0.0;

        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
            {
                if(dice[t1][i] > dice[t2][j])
                    ret.first += tmp;
                else if(dice[t1][i] < dice[t2][j])
                    ret.second += tmp;
            }

        return ret;
    }

    if(player == 0)
    {
        pair<double, double> ret, tmp;
        ret.first = 0.0, ret.second = 36.0;

        for(int i = 0; i < 3; i++)
        {
            tmp = fn( player + 1, i, 0);
//            tmp.second=1-tmp.first;
            ret = max(ret, tmp, 0);
        }
        return ret;
    }

    if(player == 1)
    {
        pair<double, double> ret, tmp;
        ret.first = 36.0, ret.second = 0.0;

        for(int i = 0; i < 3; i++)
            if(i != t1)
            {
                tmp = fn(player + 1, t1, i);
                //              tmp.first = 1.0 - tmp.first;
                ret = max(ret, tmp, 1);
            }

        return ret;
    }


}

pair<double, double> max(pair<double, double> x, pair<double, double> y, int flag)
{
    if(flag == 0)
    {
        if(x.first == y.first)
        {
            if(x.second < y.second)
                return x;
            return y;
        }

        if(x.first > y.first)
            return x;

        return y;
    }
    else
    {
        if(x.second == y.second)
        {
            if(x.first < y.first)
                return x;
            return y;
        }

        if(x.second > y.second)
            return x;

        return y;
    }
}
