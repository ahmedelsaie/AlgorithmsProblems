#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

struct word
{
    string alpha;
    int no;
};

void reset();
bool check(string input);
void check_word(string current);
int fn(int p1, int p2);
void print();

string ordered[205];
int diff_word = 0;
int e = 0;
int array1[105];
int array2[105];
int array1_word = 0;
int array2_word = 0;
map <string, word> hash1;
map <string, word>::iterator it = hash1.begin();
int paragraph = 0;
string input_main;
int dp[105][105];

int main()
{
    while(true)
    {
        hash1.clear();
        paragraph = 1;

        if(!getline(cin, input_main, '\n'))
            break;
        while(check(input_main))
            getline(cin, input_main, '\n');


        paragraph = 2;
        getline(cin, input_main, '\n');
        while(check(input_main))
            getline(cin, input_main, '\n');

        reset();
        fn(0, 0);
        print();
        cout << endl;

        diff_word = 0;
        array1_word = 0;
        array2_word = 0;
    }

    return 0;
}

void print()
{
    int p1 = 0;
    int p2 = 0;
    int r;
    int t1;
    int t2;
    int z = 0;

    while(p1 < array1_word && p2 < array2_word)
    {
        if(array1[p1] == array2[p2])
        {
            if(z > 0)
                cout << " ";
            r = array1[p1];

            cout << ordered[r];
            p1++;
            p2++;
            z++;
        }
        else
        {
            t1 = dp[p1 + 1][p2];
            t2 = dp[p1][p2 + 1];

            if(t1 > t2)
                p1++;
            else
                p2++;
        }
    }

}

int fn(int p1, int p2)
{
    int &ret = dp[p1][p2];

    if(ret != -1)
        return ret;

    if(p1 == array1_word || p2 == array2_word)
        return 0;

    if(array1[p1] == array2[p2])
        return ret = fn(p1 + 1, p2 + 1) + 1;

    int r1 = 0;
    int r2 = 0;

    r1 = fn(p1, p2 + 1);
    r2 = fn(p1 + 1, p2);

    if(r1 > r2)
        return ret = r1;
    else
        return ret = r2;
}

bool check(string input)
{
    stringstream stream_str(input);
    string i;

    while(stream_str >> i)
    {
        //cout<<i<<endl;
        if(i[0] == '#')
            return false;

        if(i[0] == NULL)
        {
            e = 1;
            return false;
        }
        check_word(i);
    }
    return true;
}

void check_word(string current)
{
    int r;
    it = hash1.find(current);
    if(it != hash1.end())
    {
        //  cout<<"exist"<<endl;
        r = it->second.no;
        if(paragraph == 1)
        {
            array1[array1_word] = r;
            array1_word++;
        }
        else
        {
            array2[array2_word] = r;
            array2_word++;
        }
        return;
    }
    else
    {
        hash1[current] = {current, diff_word};
        ordered[diff_word] = current;
        diff_word++;
        check_word(current);
        return;
    }

}

void reset()
{
    int i = array1_word;
    if(i < array2_word)
        i = array2_word;

    for(int counter = 0; counter < i + 2; counter++)
        for(int counter2 = 0; counter2 < i + 2; counter2++)
            dp[counter][counter2] = -1;
}


