#include <stdio.h>
#include <cstring>
int array[1005];
char input[1005];
int l, p;
void complete(int curr, int letter);
bool fn();

int main()
{
    scanf("%d %d", &l, &p);
    scanf("%s", input);
    for(int i = 0; i < l; i++)
        array[i] = input[i] - 'a';
    int ans = fn();

    if(ans)
    {
        for(int i = 0; i < l; i++)
            printf("%c", array[i] + 'a');
    }
    else
        printf("NO");

    return 0;
}

bool fn()
{
    for(int i = l - 1; i >= 0; i--)
        for(int j = array[i] + 1; j < p; j++)
        {
            if(i == 0)
            {
                complete(i, j);
                return true;
            }
            else if(i == 1)
            {
                if(array[i - 1] != j)
                {
                    complete(i, j);
                    return true;
                }
            }
            else if(array[i - 2] != j && array[i - 1] != j)
            {
                complete(i, j);
                return true;
            }

        }
    return false;
}

void complete(int curr, int letter)
{
    int prev1, prev2;
    array[curr] = letter;
    prev1 = letter;
    prev2 = -1;
    if(curr > 0)
        prev2 = array[curr - 1];

    for(int i = curr + 1; i < l; i++)
        for(int j = 0; j < p; j++)
        {
            if(j != prev1 && j != prev2)
            {
                array[i] = j;
                prev2 = prev1;
                prev1 = j;
                break;
            }
        }

    return;
}

