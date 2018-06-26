#include <stdio.h>
void gen(int i,int left);
void create();
bool test();
void fill(int x);

char input[50];
int n,m;
bool array[15][50];
int num[15];
const int inf=99999;
int s=inf;
int accum[50];
bool temp[50];
int w;
int ans=0;

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%s %d",input,&num[i]);
        fill(i);
        if(num[i]<s)
        {
            s=num[i];
            w=i;
        }
    }
    gen(0,0);

    printf("%d",ans);

    return 0;
}

void gen(int i,int left)
{
    if(left==s)
        return create();

    if(i==n)
        return;

    accum[left]=i;
    gen(i+1,left+1);
    gen(i+1,left);

    return ;
}

void create()
{
    for(int i=0;i<n;i++)
        temp[i]=!array[w][i];

    for(int i=0;i<s;i++)
    {
        int t=accum[i];
        temp[t]=!temp[t];
    }

    if(test())
        ans++;
}

bool test()
{
    int y=0;
    bool calc;

    for(int i=0;i<m;i++)
    {
        y=0;
        for(int j=0;j<n;j++)
        {
            calc=temp[j] xor array[i][j];
            if(!calc)
                y++;
            if(y>num[i])
                return false;
        }
        if(y!=num[i])
            return false;
    }

    return true;
}

void fill(int x)
{
    for(int i=0; i<n; i++)
        if(input[i]=='0')
            array[x][i]=false;
        else
            array[x][i]=true;
}
