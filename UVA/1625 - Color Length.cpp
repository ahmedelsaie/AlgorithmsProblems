#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 5005

int fn(int x, int y, int with);

char first[MAX], sec[MAX];
int dp[MAX][MAX], visited[MAX][MAX], l1, l2, cases = 0;
int end1[30], end2[30], start1[30], start2[30], cnt1[30], cnt2[30];
const int inf = 99999999;

int main()
{
    memset(visited, -1, sizeof(visited));

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%s %s", first, sec);
        l1 = strlen(first);
        l2 = strlen(sec);

        memset(end1, -1, sizeof(end1));
        memset(end2, -1, sizeof(end2));
        memset(start2, -1, sizeof(start2));
        memset(start1, -1, sizeof(start1));
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));

        for(int i = 0; i < l1; i++)
        {
            cnt1[first[i] - 'A']++;
            if(start1[first[i] - 'A'] == -1)
                start1[first[i] - 'A'] = i;
            end1[first[i] - 'A'] = i;
        }

        for(int i = 0; i < l2; i++)
        {
            cnt2[sec[i] - 'A']++;
            if(start2[sec[i] - 'A'] == -1)
                start2[sec[i] - 'A'] = i;
            end2[sec[i] - 'A'] = i;
        }

        printf("%d\n", fn(0, 0, 0));
    }

    return 0;
}

int fn(int x, int y, int with)
{
    if(x == l1 && y == l2)
        return 0;

    int& ret = dp[x][y];
    int& flag = visited[x][y];
    if(flag == cases)
        return ret;

    ret = inf, flag = cases;
    int new_with = with;

    ///advance in x
    if(x < l1)
    {
        new_with = with;
        int tmp = first[x] - 'A';
        int sum = cnt1[tmp] + cnt2[tmp];
        ///this type is new
        if(sum > 1 && start1[tmp] == x && (start2[tmp] >= y || start2[tmp] == -1) && (end1[tmp] > x || end2[tmp] >= y))
            new_with++;

        ///last of this type
        if(sum > 1 && end1[tmp] == x && end2[tmp] < y)
            new_with--;

        ret = min(ret, fn(x + 1, y, new_with) + new_with);
    }

    if(y < l2)
    {
        new_with = with;
        int tmp = sec[y] - 'A';
        int sum = cnt1[tmp] + cnt2[tmp];

        ///this type is new
        if(sum > 1 && start2[tmp] == y && (start1[tmp] >= x || start1[tmp] == -1) && (end2[tmp] > y || end1[tmp] >= x))
            new_with++;

        ///last of this type
        if(sum > 1 && end2[tmp] == y && end1[tmp] < x)
            new_with--;

        ret = min(ret, fn(x, y + 1, new_with) + new_with);
    }

    return ret;
}
