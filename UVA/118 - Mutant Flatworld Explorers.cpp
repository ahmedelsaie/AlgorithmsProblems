#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void pointing_W();
void pointing_N();
void pointing_S();
void pointing_E();
int check_lost();

int x = 0, y = 0, x_limit = 0, y_limit = 0, printed_before = 0, nooflost = 0;
int x_lost[100];
int y_lost[100];
char arr[110];
char direction = 'd';
int n = 0;

int main()
{
    scanf("%d %d", &x_limit, &y_limit);
    while((scanf("%d", &x)) != EOF)
    {
        n = 0;
        printed_before = 0;
        scanf("%d", &y);
        scanf("%c", &direction);
        scanf("%c", &direction);
        scanf("%s", arr);

        switch(direction)
        {
        case 'W':
            pointing_W();
            break;

        case 'N':
            pointing_N();
            break;

        case 'E':
            pointing_E();
            break;

        case 'S':
            pointing_S();
            break;
        }

        if(printed_before == 0)
            printf("%d %d %c\n", x, y, direction);
    }

    return 0;
}

void pointing_N()
{
    direction = 'N';
    while(arr[n] != '\0')
    {
        if (arr[n] == 'F')
        {
            if(y + 1 > y_limit)
            {
                if(nooflost > 0 && check_lost() == 1)
                    n++;
                else
                {
                    x_lost[nooflost] = x;
                    y_lost[nooflost] = y;
                    nooflost++;
                    printed_before = 1;
                    printf("%d %d %c LOST\n", x, y, direction);
                    return;
                }
            }
            else
            {
                y = y + 1;
                n++;
            }
        }

        if(arr[n] == 'L')
        {
            n++;
            pointing_W();
            return;
        }

        if(arr[n] == 'R')
        {
            n++;
            pointing_E();
            return;
        }
    }

}

void pointing_S()
{
    direction = 'S';
    while(arr[n] != '\0')
    {
        if (arr[n] == 'F')
        {
            if(y - 1 < 0)
            {
                if(nooflost > 0 && check_lost() == 1)
                    n++;
                else
                {
                    x_lost[nooflost] = x;
                    y_lost[nooflost] = y;
                    nooflost++;
                    printed_before = 1;
                    printf("%d %d %c LOST\n", x, y, direction);
                    return;
                }
            }
            else
            {
                y = y - 1;
                n++;
            }
        }

        if(arr[n] == 'L')
        {
            n++;
            pointing_E();
            return;
        }

        if(arr[n] == 'R')
        {
            n++;
            pointing_W();
            return;
        }
    }
}

void pointing_E()
{
    direction = 'E';
    while(arr[n] != '\0')
    {
        if (arr[n] == 'F')
        {
            if(x + 1 > x_limit)
            {
                if(nooflost > 0 && check_lost() == 1)
                    n++;
                else
                {
                    x_lost[nooflost] = x;
                    y_lost[nooflost] = y;
                    nooflost++;
                    printed_before = 1;
                    printf("%d %d %c LOST\n", x, y, direction);
                    return;
                }
            }
            else
            {
                x = x + 1;
                n++;
            }
        }

        if(arr[n] == 'L')
        {
            n++;
            pointing_N();
            return;
        }

        if(arr[n] == 'R')
        {
            n++;
            pointing_S();
            return;
        }
    }
}

void pointing_W()
{
    direction = 'W';
    while(arr[n] != '\0')
    {
        if (arr[n] == 'F')
        {
            if(x - 1 < 0)
            {
                if(nooflost > 0 && check_lost() == 1)
                    n++;
                else
                {
                    x_lost[nooflost] = x;
                    y_lost[nooflost] = y;
                    nooflost++;
                    printed_before = 1;
                    printf("%d %d %c LOST\n", x, y, direction);
                    return;
                }
            }
            else
            {
                x = x - 1;
                n++;
            }
        }

        if(arr[n] == 'L')
        {
            n++;
            pointing_S();
            return;
        }

        if(arr[n] == 'R')
        {
            n++;
            pointing_N();
            return;
        }
    }
}

int check_lost()
{
    int counter;
    for(counter = 0; counter < nooflost; counter++)
    {
        if(x_lost[counter] == x && y_lost[counter] == y)
            return 1;
    }
    return 0;
}








