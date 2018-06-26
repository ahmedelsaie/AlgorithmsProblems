#include <stdio.h>
#include <cstring>
#define inf 99999999999
struct weap
{
    int power, energy;
    char id[102];
};
struct enem
{
    int power, x;
    int ids[500];
};

bool check(int curr_weap, int curr_enemy);
long long fn(int curr_weap, int curr_enemy);
long long min(long long x, long long y);
void fill(int x);
int get(char array[]);

long long desired;
char buffer[1000];
char input[1050];
char temp[1050];
int num_weap, num_enemies;
weap weapons[1050];
enem enemies[1050];

long long dp[1050][1050];

int main()
{
    long long  ans;
    while(true)
    {
        scanf("%d %d %lld", &num_weap, &num_enemies, &desired);
        if(num_weap == 0 && num_enemies == 0 && desired == 0)
            break;

        for(int i = 0; i < num_weap; i++)
            scanf("%s %d %d", weapons[i].id, &weapons[i].power, &weapons[i].energy);

        for(int i = 0; i < num_enemies; i++)
        {
            scanf("%s %d %s", temp, &enemies[i].power, input);
            fill(i);
        }
        memset(dp, -1, sizeof(dp));
        ans = fn(0, 0);

        if(ans <= desired)
            printf("Yes");
        else
            printf("No");

        printf("\n");
    }
    return 0;
}

void fill(int x)
{
    int i = 0;
    int j = 0;
    int b;
    int k;
    while(input[i] != '\0')
    {
        buffer[0] = '\0';
        b = 0;
        while(input[i] != ',' && input[i] != '\0')
        {
            buffer[b] = input[i];
            b++;
            i++;
        }

        buffer[b] = '\0';
        k = get(buffer);

        // printf("%s\n",buffer);
        // printf("%s\n",input);
        enemies[x].ids[j] = k;
        j++;

        if(input[i] == '\0')
            break;
        i++;
    }
    enemies[x].x = j;
    return ;
}

int get(char array[])
{
    for(int i = 0; i < num_weap; i++)
        if(strcmp(array, weapons[i].id) == 0)
            return i;
    return 0;
}

long long fn(int curr_weap, int curr_enemy)
{
    if(curr_enemy == num_enemies)
        return 0;

    if(curr_weap == num_weap)
        return inf;
    long long &ret = dp[curr_weap][curr_enemy];
    if(ret != -1)
        return ret;
    ret = inf;
    int temp = inf;

    temp = fn(curr_weap + 1, curr_enemy);
    ret = min(ret, temp);
    if(check(curr_weap, curr_enemy))
        temp = fn(curr_weap + 1, curr_enemy + 1) + weapons[curr_weap].energy;
    ret = min(ret, temp);
    return ret;
}

bool check(int curr_weap, int curr_enemy)
{
    if(weapons[curr_weap].power >= enemies[curr_enemy].power)
    {
        for(int i = 0; i < enemies[curr_enemy].x; i++)
            if(curr_weap == enemies[curr_enemy].ids[i])
                return true;
        return false;
    }
    else
        return false;
}

long long min(long long x, long long y)
{
    if(x < y)
        return x;
    else
        return y;
}
