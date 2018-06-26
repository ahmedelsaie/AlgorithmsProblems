#include <stdio.h>
#include <cstring>
#include <string>

struct topic
{
    char array[20];
    int l;
};

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
void bsort();
int search(char array[]);
bool check(int mask);
void print(int mask);
void fn(int mask, int taken, int level);
void capitalizar(topic &x);
void capitalizar(char array[]);

topic speech[20];
int n, contra, grp;
int masks[200];
char temp1[20];
char temp2[20];

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d %d %d", &n, &contra, &grp);
        for(int j = 0; j < n; j++)
        {
            scanf("%s", speech[j].array);
            speech[j].l = strlen(speech[j].array);
            capitalizar(speech[j]);
        }
        bsort();
        for(int j = 0; j < contra; j++)
        {
            scanf("%s %s", temp1, temp2);
            capitalizar(temp1);
            capitalizar(temp2);
            int first = search(temp1);
            int sec = search(temp2);
            int new_mask = 0;
            new_mask = setbit(new_mask, first, 1);
            new_mask = setbit(new_mask, sec, 1);
            masks[j] = new_mask;
        }
        printf("Set %d:\n", i + 1);
        fn(0, 0, 0);
        printf("\n");
    }
    return 0;
}

void fn(int mask, int taken, int level)
{
    if(taken == grp)
    {
        print(mask);
        printf("\n");
        return;
    }

    if(level == n)
        return;

    int new_mask = mask;
    new_mask = setbit(new_mask, level, 1);
    if(check(new_mask))
        fn(new_mask, taken + 1, level + 1);

    fn(mask, taken, level + 1);
}

void print(int mask)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(getbit(mask, i))
        {
            if(cnt)
                printf(" ");
            printf("%s", speech[i].array);
            cnt++;
        }
        if(cnt == grp)
            return;
    }

}

bool check(int mask)
{
    int new_mask;
    for(int i = 0; i < contra; i++)
    {
        new_mask = mask & masks[i];
        new_mask = new_mask ^ masks[i];
        if(!new_mask)
            return false;
    }
    return true;
}

void capitalizar(topic &x)
{
    for(int i = 0; i < x.l; i++)
        x.array[i] = toupper(x.array[i]);
    return ;
}

void capitalizar(char array[])
{
    int l = strlen(array);
    for(int i = 0; i < l; i++)
        array[i] = toupper(array[i]);
    return ;
}

int search(char array[])
{
    for(int i = 0; i < n; i++)
        if(strcmp(array, speech[i].array) == 0)
            return i;
    return -1;
}

void bsort()
{
    topic swap;
    bool flag;
    for(int i = 0; i < n - 1; i++)
    {
        flag = true;
        for(int j = 0; j < n - 1; j++)
            if(speech[j].l < speech[j + 1].l)
            {
                swap = speech[j];
                speech[j] = speech[j + 1];
                speech[j + 1] = swap;
                flag = false;
            }
            else if(speech[j].l == speech[j + 1].l && strcmp(speech[j].array, speech[j + 1].array) > 0)
            {
                swap = speech[j];
                speech[j] = speech[j + 1];
                speech[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}

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
