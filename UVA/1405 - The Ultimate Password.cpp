#include <bits/stdc++.h>
using namespace std;
#define MAX 105
#define ll long long

pair<int, string> fn(int indx, int j, int left);
int gn(int indx, int first, int sec, int flag);
string getWordString(int i, int j, int len);
int tokenString();
int comp(pair<int,int> x, pair<int,int> y);
string tabular();
string trace(int indx, int j, int left);

int wordLengths[MAX];
int noOfWords;
int dp[2 * MAX][MAX][MAX];
int  dp2[2 * MAX][MAX][MAX][4];
const int inf = 1 << 29;
pair<int,int> bestArray[2 * MAX][MAX];
int last[MAX];
pair<int,int> tmpArray[MAX];
string op;

string words[2 * MAX];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        cin >> op;
        noOfWords = tokenString();

        memset(dp2, -1, sizeof(dp2));
        cout << tabular() << endl;
    }

    return 0;
}

string getWordString(int i, int j, int len)
{
    string ret = "";
    for(int k = 0; k < len; k++)
    {
        ret += words[i].at(j);

        j = (j + 1) % wordLengths[i];
    }

    return  ret;
}

string tabular()
{
    for(int indx = noOfWords; indx >= 1; indx--)
    {
        ///base case
        if(indx == noOfWords)
        {
            for(int j = 0; j < wordLengths[indx - 1]; j++)
                dp[indx][wordLengths[indx - 1]][j] = wordLengths[indx - 1];
            continue;
        }

        for(int j = 0; j < wordLengths[indx - 1]; j++)
        {
            last[j] = 0;

            for(int k = 0; k < wordLengths[indx]; k++)
            {
                tmpArray[k].second = dp[indx + 1][wordLengths[indx]][k];
                tmpArray[k].first = gn(indx, j, k, 0);
            }

            sort(tmpArray, tmpArray + wordLengths[indx], comp);

            bestArray[j][wordLengths[indx] - 1] = tmpArray[wordLengths[indx] - 1];

            for(int k = wordLengths[indx] - 2; k >= 0; k--)
            {
                bestArray[j][k].second = min(bestArray[j][k + 1].second, tmpArray[k].second);
                bestArray[j][k].first = tmpArray[k].first;
            }
        }


        for(int left = 0; left <= wordLengths[indx - 1]; left++)
        {
            for(int j = wordLengths[indx - 1] - 1; j >= 0; j--)
            {
                int &ret = dp[indx][left][j];
                ret = inf;

                if(left > 0)
                {
                    int tmp = dp[indx][left - 1][(j + 1) % wordLengths[indx - 1]];
                    tmp += 1;
                    ret = min(ret, tmp);
                }

                while(last[j] < wordLengths[indx] - 1 && bestArray[j][last[j]].first < left)
                {
                    last[j]++;
                }

                if(bestArray[j][last[j]].first >= left)
                    ret = min(ret, bestArray[j][last[j]].second);
            }
        }
    }

    int ans = inf;
    int g = -1;
    string ret = "";

    for(int i = 0; i < wordLengths[0]; i++)
    {
        if(ans > dp[1][wordLengths[0]][i])
        {
            ans = dp[1][wordLengths[0]][i];
            ret = getWordString(0, i, wordLengths[0]);
            g = i;
        }
        else if(ans == dp[1][wordLengths[0]][i])
        {
            string tmp = getWordString(0, i, wordLengths[0]);
            if(tmp < ret)
                ret = tmp, g = i;
        }
    }


    ret += trace(1, g, wordLengths[0]);

    return ret;
}

int comp(pair<int,int> x, pair<int,int> y)
{
    return x.first < y.first;
}

string trace(int indx, int j, int left)
{
    if(indx == noOfWords)
        return "";

    string ret = "";
    int flag = 0;
    int h = 0;
    int val = dp[indx][left][j];


    for(int rem = 0; rem <= left; rem++)
    {
        for(int j2 = 0; j2 < wordLengths[indx]; j2++)
        {
            if(dp[indx + 1][wordLengths[indx]][j2] + rem == val && gn(indx, (j + rem) % wordLengths[indx - 1], j2, 0) >= left - rem)
            {
                if(flag == 0)
                {
                    ret = getWordString(indx, (j2 + (left - rem)) % wordLengths[indx], wordLengths[indx] - (left - rem));
                    h = j2;
                    flag = 1;
                }
                else
                {
                    string tmp = getWordString(indx, (j2 + (left - rem)) % wordLengths[indx], wordLengths[indx] - (left - rem));

                    if(tmp < ret)
                    {
                        ret = tmp;
                        h = j2;
                    }
                }

            }

        }
    }

    ret = ret + trace(indx + 1, h, wordLengths[indx]);
    return ret;
}

int gn(int indx, int first, int sec, int flag)
{
    if(flag == 2)
        return 0;

    int &ret = dp2[indx][first][sec][flag];
    if(ret != -1)
        return ret;

    ret = 0;

    int newFlag = flag;
    if(first == wordLengths[indx] - 1)
        newFlag = flag + 1;

    if(words[indx - 1].at(first) == words[indx].at(sec))
        ret = max(ret, gn(indx, (first + 1) % wordLengths[indx - 1], (sec + 1) % wordLengths[indx], newFlag) + 1);

    return ret;
}

int tokenString()
{
    int l = op.length();
    int j = 0, noOfWords = 0;

    words[noOfWords] = "";
    for(int i = 0; i < l; i++)
    {
        if(op[i] == ';')
        {
            wordLengths[noOfWords] = words[noOfWords].length();
            noOfWords++;
            words[noOfWords] = "";
            j = 0;
        }
        else
        {
            words[noOfWords] += op[i];
        }
    }

    wordLengths[noOfWords] =  words[noOfWords].length();
    noOfWords++;

    return noOfWords;
}


