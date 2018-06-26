#include <stdio.h>
#include <cstring>
#define MAX 105

struct gang
{
    int state,time,prosper;
};

void merge_sort(int start,int last);
void merge(int start,int end);
int fn(int last,int current);
int max(int x,int y);
int abs(int x);
gang array[105];
gang help[105];

int n;
int dp[105][105];

int main()
{
    int k,t;
    int cases;
    array[102].state=0;
    array[102].time=0;

    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d %d",&n,&k,&t);

        for(int i=0; i<n; i++)
            scanf("%d",&array[i].time);

        for(int i=0; i<n; i++)
            scanf("%d",&array[i].prosper);

        for(int i=0; i<n; i++)
            scanf("%d",&array[i].state);

        memset(dp,-1,sizeof(dp));
        merge_sort(0,n-1);
        array[102].state=0;
        array[102].time=0;

        printf("%d\n",fn(102,0));
        if(cases)
            printf("\n");
    }
    return 0;
}

int fn(int last,int current)
{
    if(current==n)
        return 0;

    int &ret=dp[last][current];
    if(ret!=-1)
        return ret;

    ret=0;

    if(abs(array[last].state-array[current].state)<=array[current].time-array[last].time)
        ret=max(ret,fn(current,current+1)+array[current].prosper);

    ret=max(ret,fn(last,current+1));

    return ret;
}

int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int abs(int x)
{
    if(x>=0)
        return x;
    else
        return -1*x;
}

void merge_sort(int start,int last)
{
    if(last<=start)
        return;

    int middle=(last-start)/2;
    middle=start+middle;
    merge_sort(start,middle);
    merge_sort(middle+1,last);
    merge(start,last);
    return;
}

void merge(int start,int end)
{
    int middle=(end-start)/2;
    middle=middle+start;
    int p1=start;
    int p2=middle+1;
    int main_p=start;

    for(int i=start; i<=middle; i++)
        help[i]=array[i];

    while(main_p<=end)
    {
        if(p1>middle)
        {
            array[main_p]=array[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2>end)
        {
            array[main_p]=help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1].time<array[p2].time)
        {
            array[main_p]=help[p1];
            p1++;
        }
        else
        {
            array[main_p]=array[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}



