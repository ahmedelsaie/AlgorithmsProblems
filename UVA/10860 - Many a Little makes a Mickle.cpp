#include <stdio.h>
#include <cstring>
char arr[10005];
struct word
{
    char str[105];
    int l;
};
word subwords[55];
int dp[10005];
int dp2[10005][55];
int length, num_subwords;
const int inf = 99999999;

int fn(int left);
int fit(int x, int sub);
int min(int x, int y);
void reset();

int main()
{
    int cases, p = 1, ans;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%s", arr);
        scanf("%d", &num_subwords);
        length = strlen(arr);

        for(int i = 0; i < num_subwords; i++)
        {
            scanf("%s", subwords[i].str);
            subwords[i].l = strlen(subwords[i].str);
        }
        reset();
        ans = fn(0);
        printf("Set %d: ", p);
        if(ans == inf)
            printf("Not possible.");
        else
            printf("%d.", ans);

        //if(cases)
        printf("\n");
        p++;
    }

    return 0;
}

int fn(int left)
{
    if(left > length)
        return inf;

    if(left == length)
        return 0;

    int &ret = dp[left];
    if(ret != -1)
        return ret;
    ret = inf;

    for(int i = 0; i < num_subwords; i++)
    {
        int help = fit(left, i);
        if(help != -1)
            ret = min(ret, fn(help) + 1);
    }

    return ret;
}

int fit(int x, int sub)
{
    if(subwords[sub].l > length - x)
        return -1;

    int &ret = dp2[x][sub];
    if(ret != -2)
        return ret;

    int i = x;
    for(int j = 0; j < subwords[sub].l; j++)
    {
        if(arr[i] != subwords[sub].str[j])
        {
            ret = -1;
            break;
        }
        i++;
    }
    if(ret != -1)
        return ret = i;

    i = x;
    for(int j = subwords[sub].l - 1; j >= 0; j--)
    {
        if(arr[i] != subwords[sub].str[j])
            return ret = -1;
        i++;
    }

    return ret = i;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i = 0; i < length + 2; i++)
    {
        dp[i] = -1;
        for(int j = 0; j < num_subwords + 2; j++)
            dp2[i][j] = -2;
    }
}
