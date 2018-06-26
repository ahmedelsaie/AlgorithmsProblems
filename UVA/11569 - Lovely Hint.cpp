#include <stdio.h>
#include <cstring>
int inf = 9999999;

void process();
void bsort();
int fn(int last, int curr);
int max(int x, int y);

int dp[55][55];
int occur[55][55];
char temp[50];
char array[50];
int l;

int main()
{
    int cases;
    int ans;
    scanf("%d", &cases);
    while(cases--)
    {
        temp[0] = '\n';
        while(temp[0] == '\n' || (int)temp[0] == 0)
            gets(temp);
        process();
        memset(dp, -1, sizeof(dp));
        memset(occur, 0, sizeof(occur));
        ans = fn(l, 0);
        printf("%d %d\n", ans, occur[l][0]);
    }
    return 0;
}

int fn(int last, int curr)
{
    if(l == 0)
        return 0;
    if(curr == l)
    {
        occur[last][curr] = 1;
        return 0;
    }

    int &ret = dp[last][curr];
    int &sec = occur[last][curr];
    if(ret != -1)
        return ret;

    ret = 0;
    int choice1 = 0;
    int choice2 = 0;

    if(5 * (array[last] - 'A' + 1) <= 4 * (array[curr] - 'A' + 1))
        choice2 = fn(curr, curr + 1) + 1;
    choice1 = fn(last, curr + 1);

    if(choice1 == choice2  && choice2 != -1 * inf)
        sec = occur[last][curr + 1] + occur[curr][curr + 1];

    else if(choice1 > choice2 && choice1 != -1 * inf)
        sec = occur[last][curr + 1];
    else if(choice2 > choice1 && choice2 != -1 * inf)
        sec = occur[curr][curr + 1];
    ret = max(choice1, choice2);

    return ret;
}

void process()
{
    bool check[30];
    memset(check, true, sizeof(check));
    int temp_l = strlen(temp);
    int j = 0;
    for(int i = 0; i < temp_l; i++)
        if(temp[i] >= 'A' && temp[i] <= 'Z')
            if(check[temp[i] - 'A'])
            {
                array[j] = temp[i];
                j++;
                check[temp[i] - 'A'] = false;
            }

    array[j] = '\0';
    l = strlen(array);
    bsort();
    array[j] = '#';
    array[j + 1] = '\0';
    return ;
}

void bsort()
{
    char swap;
    bool flag;
    for(int i = 0; i < l - 1; i++)
    {
        flag = true;
        for(int j = 0; j < l - 1; j++)
            if(array[j] > array[j + 1])
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
