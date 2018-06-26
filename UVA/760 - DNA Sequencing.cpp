#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

int max(int x, int y);
int fn(int x, int y);
void trace(int x, int y, string accum);

int visited[305][305];
int dp[305][305];
string arr1;
string arr2;
set<string> ans;
int l1, l2, cases = 0, j, res;

int main()
{
    int kk = 1;
    memset(visited, -1, sizeof(visited));

    while(getline(cin, arr1))
    {
        cases++;
        if(kk != 1)
            getline(cin, arr1);
        getline(cin, arr2);
        l1 = arr1.length();
        l2 = arr2.length();
        res = 0;
        for(int i = 0; i < l1; i++)
            for(int j = 0; j < l2; j++)
                res = max(res, fn(i, j));

        if(kk != 1)
            cout << endl;

        if(!res)
            cout << "No common sequence." << endl;
        else
        {
            for(int i = 0; i < l1; i++)
                for(int j = 0; j < l2; j++)
                    trace(i, j, "");

            while (!ans.empty())
            {
                string s = *ans.begin();
                cout << *ans.begin() << endl;
                ans.erase(ans.begin());
            }
        }
        kk++;
    }
}

void trace(int x, int y, string accum)
{
    if(x == l1 || y == l2 || arr1[x] != arr2[y])
    {
        if(accum.length() == res)
            ans.insert(accum);
        return;
    }

    if(arr1[x] == arr2[y])
        return trace(x + 1, y + 1, accum += arr1[x]);
}

int fn(int x, int y)
{
    if(x == l1 || y == l2)
        return 0;

    int& ret = dp[x][y];
    int& flag = visited[x][y];
    if(flag == cases)
        return ret;

    ret = 0;
    flag = cases;

    if(arr1[x] == arr2[y])
        ret = fn(x + 1, y + 1) + 1;
    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

