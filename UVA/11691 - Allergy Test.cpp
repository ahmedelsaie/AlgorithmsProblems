#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

//void reset();
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
//int fn(int days_left,int mask,int taken);
void merge(int start, int end);
void merge_sort(int start, int last);

void bsort();
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int dp[10][(1 << 20) + 5];
const int inf = 99999;
int time1[25];
int help[25];
int allergen;
int max_d;
int tabular();
int comp(int x, int y);

int main()
{
    int cases;

    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        max_d = 0;
        scanf("%d", &allergen);
        for(int j = 0; j < allergen; j++)
            scanf("%d", &time1[j]);

        //for(int j=0;j<allergen;j++)
        //   max_d=max(max_d,time1[j]);

        //reset();
        //bsort();
        sort(time1, time1 + allergen, comp);
           // merge_sort(0, allergen - 1);
        max_d = time1[0];

        printf("fffffffff %d\n", max_d);

    }
    return 0;
}


int comp(int x, int y)
{
    return x >= y;
}

int tabular()
{
    int new_mask;
    int ret;
    int temp;
    int r = (1 << allergen) - 1;
    for(int j = 0; j < max_d; j++)
        dp[j][r] = j;


    for(int mask = r - 1; mask >= 0; mask--)
    {
        for(int days = 0; days < max_d; days++)
        {
            ret = inf;
            for(int i = 0; i < allergen; i++)
            {
                if(time1[i] > days)
                {
                    if(!getbit(mask, i) )
                    {
                        new_mask = setbit(mask, i, 1);
                        temp = dp[time1[i] - (days + 1)][new_mask] + days + 1;

                        ret = min(ret, temp);
                    }
                }
                else
                    break;
                if(days - 1 >= 0)
                {
                    temp = dp[days - 1][mask] + 1;
                    ret = min(ret, temp);
                }
                dp[days][mask] = ret;

            }

        }

    }
    return dp[0][0];
}





void merge_sort(int start, int last)
{
    //printf("start= %d end= %d\n",start,last);
    if(start == last)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle);
    merge_sort(middle + 1, last);
    merge(start, last);
    return;
}









void merge(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = time1[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            time1[main_p] = time1[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            time1[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1] > time1[p2])
        {
            time1[main_p] = help[p1];
            p1++;
        }
        else
        {
            time1[main_p] = time1[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}



/*
int fn(int days_left,int mask,int taken)
{
    if(days_left<0)
        return inf;
    //  printf("days _left %d mask %d\n",days_left,mask);
    if(taken==allergen)
    {
        //printf("in cases left =%d\n",days_left);
        //if(days_left==0)
        return days_left;
        //else
        //   return 1+fn(days_left-1,mask,taken);
    }


    int &ret=dp[days_left][mask];
    if(visited[days_left][mask])
       return ret;
    else
        visited[days_left][mask]=true;
    ret=inf;
    int new_mask;
    int new_days;
    int temp;
    for(int i=0; i<allergen; i++)
    {
        if(time1[i]>days_left)
        {
            if(!getbit(mask,i) )
            {
                //   printf("days _left %d mask %d\n",days_left,mask);
                //  printf("take %d\n",i);
                new_mask=setbit(mask,i,1);
                temp=fn(time1[i]-(days_left+1),new_mask,taken+1)+days_left+1;

                ret=min(ret,temp);
            }
        }
        else
            break;
    }
    temp=fn(days_left-1,mask,taken)+1;
    ret=min(ret,temp);
    return ret;
}
*/

void bsort()
{
    int swap;
    bool flag;
    for(int i = 0; i < allergen - 1; i++)
    {
        flag = true;
        for(int j = 0; j < allergen - 1; j++)
            if(time1[j] < time1[j + 1])
            {
                swap = time1[j];
                time1[j] = time1[j + 1];
                time1[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}

/*
void reset()
{
    for(int i=0;i<max_d+1;i++)
    for(int j=0;j<(1<<allergen)+5;j++)
    visited[i][j]=false;
}
*/

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

