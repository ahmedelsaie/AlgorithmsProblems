#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

bool tabular(int left);

bool dp[60009];
int accum[6][20009], array[7], total;

int main()
{
    int ans, cases = 1;
    while(true)
    {
        total = 0;
        for(int i = 1; i <= 6; i++)
            scanf("%d", &array[i]), total += i * array[i];

        if(total == 0)
            break;

        ans = tabular(total);
        printf("Collection #%d:\n", cases++);
        printf(ans ? "Can be divided." : "Can't be divided.");
        printf("\n\n");
    }
    return 0;
}

bool tabular(int left)
{
    int val;
    if(left % 2 != 0)
        return false;
    left = left / 2;
    memset(accum, 0, sizeof(accum));
    for(int i = 0; i < 7; i++)
        accum[i][0] = 0;

    ///base case
    dp[0] = 1, accum[0][1] = 1;
    for(int i = 1; i <= left; i++)
        dp[i] = 0;

    for(int i = 0; i <= left; i++)
    {
        if(i / 6 > 0)
            accum[i % 6][i / 6 + 1] = accum[i % 6][i / 6 ] + dp[i];
    }

    for(int i = 6; i >= 1; i--)
    {
        for(int j = 0; j <= left; j++)
        {
            bool& ret = dp[j];
            ret = 0;
            val = min(array[i], j / i) * i;
            int first = j / i;
            int sec = (j - val) / i;
            if(accum[j % i][first + 1] - accum[j % i][sec] > 0)
                ret = 1;
        }

        ///update sec table
        for(int j = 0; j <= left; j++)
        {
            int new_i = i - 1;
            if(new_i > 0)
                accum[j % new_i][j / new_i + 1] = accum[j % new_i][j / new_i] + dp[j];
        }
    }

    return dp[left];
}


