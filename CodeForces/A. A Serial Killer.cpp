#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

pair<string, string> arr[MAX];
string first, sec;
int n;

int main()
{
    cin >> first >> sec;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    for(int i = 0; i < n + 1; i++)
    {
        cout << first << " " << sec << endl;
        if(arr[i].first == first)
            first = arr[i].second;
        else
            sec = arr[i].second;
    }

    return 0;
}
