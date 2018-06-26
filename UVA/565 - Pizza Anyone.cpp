#include <stdio.h>
#include <cstring>

void fn_input();
int fn(int satisfied, int proper);
int check(int satisfied, int proper, bool flag);
void print();
int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);

int dp[20][4100];
int visited[20][4100];
int friends[15][20];
int accum[20];
int no_friends, interest;
bool ok;
char input[50];
int cases = 0;

int main()
{
    no_friends = 0;
    memset(friends, 0, sizeof(friends));
    bool ans;
    memset(visited, -1, sizeof(visited));
    while(gets(input))
    {
        if(input[0] != '.')
        {
            fn_input();
            no_friends++;
        }
        else
        {
            ok = false;

            ans = fn(0, 0);
            if(!ok)
                printf("No pizza can satisfy these requests.\n");
            no_friends = 0;
            interest = 0;
            memset(friends, 0, sizeof(friends));
        }
        cases++;
    }
    return 0;
}

int fn(int satisfied, int proper)
{
    if(ok)
        return true;
    if(proper == 16)
    {
        if(satisfied == (1 << no_friends) - 1)
        {
            ok = true;
            print();
            return true;
        }
        else
            return false;
    }

    int &ret = dp[proper][satisfied];
    int &flag = visited[proper][satisfied];
    if(flag == cases)
        return ret;
    flag = cases;

    if(!getbit(interest, proper))
    {
        accum[proper] = 0;
        return ret = fn(satisfied, proper + 1);
    }
    int new_satisfied;
    bool ans1, ans2, ans3;

    accum[proper] = 0;
    ans3 = fn(satisfied, proper + 1);

    accum[proper] = -1;
    new_satisfied = check(satisfied, proper, false);
    if(new_satisfied != satisfied)
        ans2 = fn(new_satisfied, proper + 1);

    accum[proper] = 1;
    new_satisfied = check(satisfied, proper, true);
    if(new_satisfied != satisfied)
        ans1 = fn(new_satisfied, proper + 1);


    return ret = (ans1 | ans2 | ans3);
}

int check(int satisfied, int proper, bool flag)
{
    for(int i = 0; i < no_friends; i++)
    {
        if(!getbit(satisfied, i))
        {
            if(flag && friends[i][proper] == 1)
                satisfied = setbit(satisfied, i, 1);
            if(!flag && friends[i][proper] == -1)
                satisfied = setbit(satisfied, i, 1);
        }
    }
    return satisfied;
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

void print()
{
    bool det = true;
    printf("Toppings:");
    for(int i = 0; i < 16; i++)
    {
        if(accum[i] == 1 && det == true)
        {
            printf(" ");
            det = false;
        }
        if(accum[i] == 1)
            printf("%c", i + 'A');
    }
    printf("\n");
}

void fn_input()
{
    int sign, i = 0;
    while(input[i] != ';')
    {
        if(input[i] == '+')
            sign = 1;
        else
            sign = -1;
        int t = input[i + 1] - 'A';
        interest = setbit(interest, t, 1);
        friends[no_friends][t] = sign;
        i += 2;
    }
}
