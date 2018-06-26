#include <stdio.h>
#include <cstring>

struct name
{
    char array[20];
};
name players[16];
int x[125];

int setbit(int mask, int bit, int value);
int cntbit(int mask);
int getbit(int mask, int bit);
void update(int mask);
void fn(int i, int mask);
void gen(int i);
bool check(int t_mask);
void bsort();

int n, pairs;
char player1[20];
char player2[20];
int ans;

int main()
{
    ans = 0;

    scanf("%d %d", &n, &pairs);
    for(int i = 0; i < n; i++)
        scanf("%s", players[i].array);

    bsort();

    for(int i = 0; i < pairs; i++)
    {
        scanf("%s", player1);
        scanf("%s", player2);
        gen(i);
    }

    fn(0, 0);
    printf("%d\n", cntbit(ans));

    for(int i = 0; i < n; i++)
    {
        if(getbit(ans, i))
            printf("%s\n", players[i].array);
    }
    return 0;
}

void bsort()
{
    char swap[20];
    bool flag;
    for(int i = 0; i < n - 1; i++)
    {
        flag = true;
        for(int j = 0; j < n - 1; j++)
            if(strcmp(players[j].array, players[j + 1].array) == 1)
            {
                swap[0] = '\0';
                strcpy(swap, players[j].array);
                strcpy(players[j].array, players[j + 1].array);
                strcpy(players[j + 1].array, swap);
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}


void fn(int i, int mask)
{
    if(i == n)
    {
        update(mask);
        return ;
    }

    fn(i + 1, mask);

    int new_mask = mask;
    new_mask = setbit(new_mask, i, 1);

    if(check(new_mask))
        fn(i + 1, new_mask);

    return;
}

bool check(int t_mask)
{
    int y;
    for(int i = 0; i < pairs; i++)
    {
        y = t_mask & x[i];
        y = y xor x[i];
        if(y == 0)
            return false;
    }
    return true;
}

void update(int mask)
{
    int r = cntbit(mask);
    int l = cntbit(ans);
    if(r > l)
        ans = mask;
    return ;
}

void gen(int i)
{
    int no1, no2;
    for(int j = 0; j < n; j++)
    {
        if(strcmp(player1, players[j].array) == 0)
        {
            no1 = j;
            break;
        }
    }

    for(int j = 0; j < n; j++)
    {
        if(strcmp(player2, players[j].array) == 0)
        {
            no2 = j;
            break;
        }
    }
    int mask = 0;
    mask = setbit(mask, no1, 1);
    mask = setbit(mask, no2, 1);
    x[i] = mask;
    return;
}

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
    }
    return ret;
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
