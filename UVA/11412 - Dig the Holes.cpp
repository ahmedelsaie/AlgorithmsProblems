#include <stdio.h>
#include <cstring>

struct word
{
    char array[7];
};

void gen(int i);
bool fn();
bool is_correct(bool gue, int j);
bool find(char array[], char x);

word perms[370];
int count = 0;
bool check[6];
int x1, y1, x2, y2;
char colors[] = "RGBYOV";
char accum[7];
char first[7];
char sec[7];

int main()
{
    for(int i = 0; i < 6; i++)
        check[i] = true;
    gen(0);
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%s %d %d", first, &x1, &y1);
        scanf("%s %d %d", sec, &x2, &y2);
        if(fn())
            printf("Possible");
        else
            printf("Cheat");
        printf("\n");

    }
    return 0;
}

bool fn()
{
    for(int i = 0; i < 360; i++)
    {
        if(is_correct(true, i) && is_correct(false, i))
            return true;
    }
    return false;
}

bool is_correct(bool gue, int j)
{
    if(gue)
    {
        int x = 0, y = 0;
        for(int i = 0; i < 4; i++)
        {
            if(first[i] == perms[j].array[i])
                x++;
            else if(find((first), perms[j].array[i]))
                y++;
            if(x > x1 || y > y1)
                return false;
        }
        if(x == x1 && y == y1)
            return true;
        else
            return false;
    }
    else
    {
        int x = 0, y = 0;
        for(int i = 0; i < 4; i++)
        {
            if(sec[i] == perms[j].array[i])
                x++;
            else if(find((sec), perms[j].array[i]))
                y++;
            if(x > x2 || y > y2)
                return false;
        }
        if(x == x2 && y == y2)
            return true;
        else
            return false;
    }
}

bool find(char array[], char x)
{
    for(int i = 0; i < 4; i++)
        if(array[i] == x)
            return true;
    return false;
}

void gen(int i)
{
    if(i == 4)
    {
        accum[i] = '\0';
        strcpy(perms[count].array, accum);
        count++;
        return;
    }

    for(int j = 0; j < 6; j++)
        if(check[j] == true)
        {
            accum[i] = colors[j];
            check[j] = false;
            gen(i + 1);
            check[j] = true;
        }
}
