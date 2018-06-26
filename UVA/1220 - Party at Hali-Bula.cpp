#include <stdio.h>
#include <cstring>
#define MAX 205
struct ans
{
    int val;
    bool repeat;
};

int get(char tmp[], int limit);
void cpy(char tmp1[], char input[]);
ans max(ans x, ans y);
ans fn(bool before, int curr);
ans add(ans x, ans y);

char input[MAX][MAX];
bool tree[MAX][MAX];
char tmp1[MAX];
char tmp2[MAX];
int visited[2][MAX];
ans dp[2][MAX];

int n, cases;

int main()
{
    cases = 0;
    ans result;
    int limit = 0;
    memset(visited, -1, sizeof(visited));

    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        limit = 0;
        memset(tree, false, sizeof(tree));

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                scanf("%s", tmp1);
                cpy(tmp1, input[limit]);
                limit++;
            }
            else
            {
                scanf("%s %s", tmp1, tmp2);
                int h = get(tmp1, limit);
                if(h == -1)
                {
                    cpy(tmp1, input[limit]);
                    h = limit;
                    limit++;
                }

                int t = get(tmp2, limit);
                if(t == -1)
                {
                    cpy(tmp2, input[limit]);
                    t = limit;
                    limit++;
                }
                tree[t][h] = true;

            }
        }
        result = fn(true, 0);

        printf("%d ", result.val);

        if(result.repeat == 0)
            printf("Yes");
        else
            printf("No");
        printf("\n");

        cases++;
    }

    return 0;
}

ans fn(bool before, int curr)
{
    ans &ret = dp[before][curr];
    int &flag = visited[before][curr];
    if(flag == cases)
        return ret;
    flag = cases;

    ret.val = 0;
    ret.repeat = 0;

    ans tmp1, tmp2;

    tmp1.val = 0;
    tmp1.repeat = 0;

    tmp2.val = 0;
    tmp2.repeat = 0;

    if(before)
    {
        for(int i = 0; i < n; i++)
            if(tree[curr][i] == true)
                tmp1 = add(fn(false, i), tmp1);
        tmp1.val++;
    }

    for(int i = 0; i < n; i++)
        if(tree[curr][i] == true)
            tmp2 = add(fn(true, i), tmp2);

    ret = max(tmp1, tmp2);

    if(tmp1.val == tmp2.val && before)
        ret.repeat = 1;

    return ret;
}

ans add(ans x, ans y)
{
    ans ret;
    ret.repeat = x.repeat | y.repeat;
    ret.val = x.val + y.val;
    return ret;
}

ans max(ans x, ans y)
{
    if(x.val > y.val)
        return x;
    else
        return y;
}

int get(char tmp[], int limit)
{
    for(int i = 0; i < limit; i++)
        if(strcmp(tmp, input[i]) == 0)
            return i;
    return -1;
}

void cpy(char tmp1[], char input[])
{
    int l = strlen(tmp1);
    int i;

    for(i = 0; i < l; i++)
        input[i] = tmp1[i];

    input[i] = '\0';

    return ;
}
