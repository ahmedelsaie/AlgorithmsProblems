#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

struct card
{
    char arr[5];
};

bool comp(card x, card y);
int get_num(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8);
void put(int a[], int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8);
double fn(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8);

card arr[10][6];
bool    v[5][5][5][5][5][5][5][5][5];
double dp[5][5][5][5][5][5][5][5][5];

int main()
{
    while(~scanf("%s", arr[0][1].arr))
    {
        for(int i = 0; i < 9; i++)
        {
            int s = i == 0 ? 2 : 1;
            for(int j = s; j <= 4; j++)
                scanf("%s", arr[i][j].arr);
        }

        memset(v, 0, sizeof(v));
        printf("%0.6lf\n", fn(4, 4, 4, 4, 4, 4, 4, 4, 4));
    }

    return 0;
}

double fn(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8)
{
    if(s0 + s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 == 0)
        return 1.0;

    bool& flag = v[s0][s1][s2][s3][s4][s5][s6][s7][s8];
    double& ret = dp[s0][s1][s2][s3][s4][s5][s6][s7][s8];
    if(flag == true)
        return ret;
    flag = 1, ret = 0.0;

    int num = 0; // get_num(s0, s1, s2, s3, s4, s5, s6, s7, s8);
    double fac ;
    if(num == 0)
        fac = 0.0;
    else
        fac = 1.0 / (double)num;

    int x[10];
    put(x, s0, s1, s2, s3, s4, s5, s6, s7, s8);
    // if(s0 + s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 == 36)
    // printf("%d %lf\n", num, fac);

    for(int i = 0; i < 9; i++)
        for(int j = i + 1; j < 9; j++)
        {
            if(arr[i][x[i]].arr[0] == arr[j][x[j]].arr[0] && x[i] != 0 && x[j] != 0)
            {
                num++;
                x[i]--, x[j]--;
                ret += fn(x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8]);
                x[i]++, x[j]++;
            }
        }
    if(num)
        ret = ret * (1 / (double)num);
    return ret;
}

void put(int a[], int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8)
{
    a[0] = s0;
    a[1] = s1;
    a[2] = s2;
    a[3] = s3;
    a[4] = s4;
    a[5] = s5;
    a[6] = s6;
    a[7] = s7;
    a[8] = s8;
}

int get_num(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8)
{
    card tmp[15];
    tmp[0] = arr[0][s0];
    tmp[1] = arr[1][s1];
    tmp[2] = arr[2][s2];
    tmp[3] = arr[3][s3];
    tmp[4] = arr[4][s4];
    tmp[5] = arr[5][s5];
    tmp[6] = arr[6][s6];
    tmp[7] = arr[7][s7];
    tmp[8] = arr[8][s8];

    sort(tmp, tmp + 9, comp);
    int i = 0, ret = 0;
    card prev = tmp[0];
    int accum = 0;

    while(i < 9)
    {
        if(prev.arr[0] != tmp[i].arr[0])
            ret += (accum * (accum - 1)) / 2, prev = tmp[i], accum = 1;
        else
            accum++;
        i++;
    }

    ret += (accum * (accum - 1)) / 2;

    return ret;
}

bool comp(card x, card y)
{
    return x.arr[0] < y.arr[0];
}




