#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

void cut(int start);
void fn();

map <string, int> occur;
map <string, int>::iterator it = occur.begin();
int maxl;
string message;
string sub;
string result;
int main_l;
int sub_l;

int main()
{
    while(cin >> sub_l >> message)
    {
        main_l = message.length();
        sub.resize(sub_l);
        result.resize(sub_l);
        maxl = 0;
        fn();
        cout << result << endl;
    }

    return 0;
}

void fn()
{
    for(int i = 0; main_l - i >= sub_l; i++)
    {
        cut(i);
        it = occur.find(sub);
        if(it != occur.end())
            occur[sub] = occur[sub] + 1;
        else
            occur[sub] = 1;

        if(occur[sub] > maxl)
        {
            maxl = occur[sub];
            result = sub;
        }
    }
}

void cut(int start)
{
    int n = 0;
    for(int i = start; n < sub_l; i++)
    {
        sub[n] = message[i];
        n++;
    }
    return;
}
