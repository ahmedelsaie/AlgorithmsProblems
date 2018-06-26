#include <stdio.h>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int n;
bool visited[51][51][51][2][2];
bool dp[51][51][51][2][2];
int mf, mm, ff;
string str;
bool check(string in);
bool fn(int both_m, int both_f, int m_f, bool last, bool first, int left);

int main()
{
    memset(visited, false, sizeof(visited));

    int cases;
    scanf("%d", &cases);
    bool ans;
    while(cases--)
    {
        ans = false;
        mf = 0;
        mm = 0;
        ff = 0;
        str = "";
        while(!check(str))
            getline(cin, str, '\n');

        if(mf + mm + ff > 1)
        {
            ans = fn(mm, ff - 1, mf, false, false, mf + mm + ff - 1);
            ans = ans | fn(mm - 1, ff, mf, true, true, mf + mm + ff - 1);
            ans = ans | fn(mm, ff, mf - 1, true, false, mf + mm + ff - 1);
            ans = ans | fn(mm, ff, mf - 1, false, true, mf + mm + ff - 1);
        }

        if(ans)
            printf("LOOP");
        else
            printf("NO LOOP");
        printf("\n");
    }

    return 0;
}

bool fn(int both_m, int both_f, int m_f, bool last, bool first, int left)
{
    if(both_m < 0 || both_f < 0 || m_f < 0)
        return false;

    if(left == 0)
    {
        if(first != last)
            return true;
        else
            return false;
    }

    bool &flag = visited[both_m][both_f][m_f][last][first];
    bool &ret = dp[both_m][both_f][m_f][last][first];
    if(flag)
        return ret;
    ret = false;
    bool temp;

    if(last)
    {
        temp = fn(both_m, both_f - 1, m_f, false, first, left - 1);
        ret = ret | temp;
    }
    else
    {
        temp = fn(both_m - 1, both_f, m_f, true, first, left - 1);
        ret = ret | temp;
    }
    temp = fn(both_m, both_f, m_f - 1, last, first, left - 1);
    ret = ret | temp;
    return ret;
}

bool check(string in)
{
    bool flag = false;
    stringstream stream_str(in);
    string i = "";
    while(stream_str >> i)
    {
        if(i == "MM")
        {
            flag = true;
            mm++;
        }
        else if(i == "FF")
        {
            ff++;
            flag = true;
        }
        else if(i == "MF" || i == "FM")
        {
            flag = true;
            mf++;
        }
    }
    return flag;
}

