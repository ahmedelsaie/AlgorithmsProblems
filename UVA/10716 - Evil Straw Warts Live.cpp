#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 50009

int can();
int fn();
pair<int, int> get(int start, char x, int flag);

char array[MAX];
int l, v[MAX], cases;
const int inf = 899999;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%s", array);
        l = strlen(array);

        int tmp = fn();
        if(tmp != -1)
            printf("%d\n", tmp);
        else
            printf("Impossible\n");
    }

    return 0;
}

int fn()
{
    int ret = 0;
    if(can() == 0)
        return -1;

    memset(v, 0, sizeof(v));

    pair<int, int> tmp_r, tmp_l, sl, sr;
    int val;
    int start = 0, end = l - 1;
    int t = 0;

    while(t < l / 2)
    {
        val = inf;
        for(int i = 0; i < 27; i++)
        {
            tmp_l = get(start, 'a' + i, 0);
            tmp_r = get(end, 'a' + i, 1);

            int tmp = tmp_l.first + tmp_r.first;

            if(tmp_r.first != -1 && tmp_l.first != -1 && tmp < val && tmp_r.second != tmp_l.second)
                val = tmp, sl = tmp_l, sr = tmp_r;

            //   printf("%c %d %d\n",'a'+i,tmp_l.first,tmp_r.first);
        }//

        // printf("%d sfsfsf\n",val);
//
        ret += val;
        v[sl.second] = v[sr.second] = 1;
        // start++, end--;
        t++;
    }

    return ret;
}

pair<int, int> get(int start, char x, int flag)
{
    int curr = 0;
    pair<int, int> ret;
    ret.first = ret.second = -1;

    if(flag == 0)
    {
        for(int i = 0; i < l; i++)
            if(v[i] == 0)
            {
                if(array[i] == x)
                {
                    ret.first = curr, ret.second = i;
                    return ret;
                }
                else
                    curr++;
            }

        return ret;
    }
    else
    {
        for(int i = l - 1; i >= 0; i--)
            if(v[i] == 0)
            {
                if(array[i] == x)
                {
                    ret.first = curr, ret.second = i;
                    return ret;
                }
                else
                    curr++;
            }

        return ret;
    }
}

int can()
{
    int chk[30], even = 0, odd = 0;
    memset(chk, 0, sizeof(chk));

    for(int i = 0; i < l; i++)
        chk[array[i] - 'a']++;

    for(int i = 0; i < 27; i++)
        odd += chk[i] % 2, even += !chk[i] % 2;

    if(odd > 1)
        return 0;

    return 1;
}
