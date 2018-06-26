#include <stdio.h>
#include <cstring>

int fn(int first, int sec, int third, bool but);
void reset();

int mod = 10007;
int dp[61][61][61][2];
char input1[65];
char input2[65];
char input3[65];
int third_length, first_length, sec_length;

int main()
{
    int cases, ans;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%s %s %s", input1, input2, input3);
        first_length = strlen(input1);
        sec_length = strlen(input2);
        third_length = strlen(input3);
        //reset();
        memset(dp, -1, sizeof(dp));
        ans = (fn(0, 0, 0, 0) + fn(0, 0, 0, 1)) % mod;
        printf("%d\n", ans);
    }
    return 0;
}

int fn(int first, int sec, int third, bool but)
{
    if(third == third_length)
        return 1;


    if(first == first_length && sec == sec_length)
        return 0;

    int &ret = dp[first][sec][third][but];
    if(ret != -1)
        return ret;
    ret = 0;

    if(but)
    {
        if(first < first_length)
        {
            if(input1[first] == input3[third])
            {
                ret += fn(first + 1, sec, third + 1, but) % mod;
                if(third + 1 < third_length)
                    ret += fn(first + 1, sec, third + 1, !but) % mod;
            }
            ret += fn(first + 1, sec, third, but) % mod;
        }
    }
    else
    {
        if(sec < sec_length)
        {
            if(input2[sec] == input3[third])
            {
                ret += fn(first, sec + 1, third + 1, but) % mod;
                if(third + 1 < third_length)
                    ret += fn(first, sec + 1, third + 1, !but) % mod;
            }
            ret += fn(first, sec + 1, third, but) % mod;
        }
    }
    return ret % mod;
}

void reset()
{
    for(int i = 0; i < first_length + 1; i++)
        for(int j = 0; j < sec_length + 1; j++)
            for(int k = 0; k < third_length + 1; k++)
                for(int a = 0; a < 2; a++)
                    dp[i][j][k][a] = -1;
}

