#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

bool check(string in);
void reset();
long long min(int row, int col);
long long ways(int row, int col);

string str;
long long dp[105][105];
int map[105][105];
int main_row;
int main_col;

int main()
{
    int cases;
    cin >> cases;

    for(int counter2 = 0; counter2 < cases; counter2++)
    {
        cin >> main_row >> main_col;
        reset();


        for(int counter = 1; counter <= main_row;)
        {
            getline(cin, str, '\n');
            if(check(str) == true)
                counter++;
        }

        if(min(1, 1) >= 100000000)
            cout << "0" << endl;
        else
            cout << ways(1, 1) << endl;

        if(counter2 < cases - 1)
            cout << endl;

    }

    return 0;
}

bool check(string in)
{
    int flag = 0;
    stringstream stream_str(in);

    int main;
    int i;
    while(stream_str >> i)
    {
        if(flag == 0)
            main = i;

        else
        {
            map[main][i] = 1;
        }
        flag++;
    }

    if(flag == 0)
        return false;
    else
        return true;


}

long long ways(int row, int col)
{
    if(dp[row][col] == 100000000)
        return 0;

    if(row == main_row && col == main_col)
        return 1;

    if(row == main_row)
        return ways(row, col + 1);

    if(col == main_col)
        return ways(row + 1, col);



    if(dp[row + 1][col] == dp[row][col + 1])
    {
        return ways(row + 1, col) + ways(row, col + 1);

    }

    long long m1, m2;
    m1 = dp[row + 1][col];
    m2 = dp[row][col + 1];

    if(m1 < m2)
        return ways(row + 1, col);
    else
        return ways(row, col + 1);
}

long long min(int row, int col)
{

    if(row > main_row || col > main_col)
        return 100000000;

    if(map[row][col] == 1)
    {
        dp[row][col] = 100000000;
        return 100000000;
    }


    if(dp[row][col] != -1)
        return dp[row][col];

    if(row == main_row && col == main_col)
    {

        return 0;
    }
    long long r, d, max;

    r = min(row, col + 1);
    d = min(row + 1, col);

    max = r;

    if(d < max)
        max = d;

    dp[row][col] = max + 1;

    return max + 1;
}

void reset()
{
    for(int counter = 0; counter < main_row + 5; counter++)
    {
        for(int counter2 = 0; counter2 < main_col + 5; counter2++)
        {
            map[counter][counter2] = -1;
            dp[counter][counter2] = -1;

        }
    }
}


