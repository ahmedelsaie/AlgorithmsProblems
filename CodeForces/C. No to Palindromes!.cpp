#include <stdio.h>
#include <cstring>
char arr[1005];
int array[1005];
int arr2[1005];
unsigned long long dp[1005][30][30];
bool visited[1005][30][30];

int l, p;
unsigned long long fn(int i, int before1, int before2);
unsigned long long trace(int before1, int before2);
unsigned long long target;
void make(int curr, int before1, int before2, unsigned long long with_me);

int main()
{
    long long ans;
    scanf("%d %d", &l, &p);
    scanf("%s", arr);
    for(int i = 0; i < l; i++)
        array[i] = arr[i] - 'a';

    for(int i = 0; i <= l + 2; i++)
        for(int j = 0; j <= 28; j++)
            for(int k = 0; k <= 28; k++)
                visited[i][j][k] = 0;
    // memset(dp, -1, sizeof(dp));
    ans = fn(0, 28, 28);
    //printf("%llu\n", ans);
    target = trace(28, 28);
    if(ans - 1 == target)
        printf("NO");
    else
    {
        target++;
        // printf("%lld\n", target);
        make(0, 28, 28, 0);

        for(int i = 0; i < l; i++)
            printf("%c", arr2[i] + 'a');
    }
    printf("\n");

    return 0;
}


void make(int curr, int before1, int before2, unsigned long long with_me)
{
    // printf("%d %d %d %d\n",curr,before1,before2,with_me);
    if(curr == l)
        return;
    int i, j;
    unsigned long long  all = 0;
    unsigned long long  tmp;

    tmp = 0;
   unsigned  long long accum = 0;
    for(j = 0; j < p; j++)
    {
        tmp = 0;
        if(j != before1 && j != before2)
        {
            tmp += dp[curr + 1][before2][j];

            if(tmp + accum + with_me > target)
            {
                arr2[curr] = j;
                make(curr + 1, before2, j, with_me + accum);
                return;
            }
            else
                accum += tmp;
        }
    }
}



unsigned long long trace(int before1, int before2)
{
    int i, j;
    unsigned long long  all = 0;
    unsigned long long  tmp;
    for(i = 0; i < l; i++)
    {
        tmp = 0;
        for(j = 0; j < p; j++)
        {
            if(j != before1 && j != before2)
            {
                if(j == array[i])
                    break;
                tmp += dp[i + 1][before2][j];
            }
        }
        before1 = before2;
        before2 = j;
        all += tmp;
    }

    return all;


}

unsigned long long fn(int i, int before1, int before2)
{

    unsigned long long& ret = dp[i][before1][before2];
    bool& flag = visited[i][before1][before2];

    if(flag)
        return ret;
    flag = true;
    if(i == l)
        return ret = 1;

    ret = 0;

    for(int j = 0; j < p; j++)
        if(j != before1 && j != before2)
            ret += fn(i + 1, before2, j);

    return ret;
}
