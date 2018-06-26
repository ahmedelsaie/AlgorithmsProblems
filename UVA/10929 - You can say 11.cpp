#include <stdio.h>
#include <cstring>

bool fn();
int get(int temp, int i);
void fix();

char arr[1009];
char p[1009];
int l;

int main()
{
    int ans, i;
    while(true)
    {
        scanf("%s", arr);
        l = strlen(arr);

        if(arr[0] == '0' && l == 1)
            break;

        fix();
        ans = fn();
        printf("%s is ", p);

        if(ans)
            printf("a multiple of 11.");
        else
            printf("not a multiple of 11.");

        printf("\n");
    }

    return 0;
}

bool fn()
{
    int temp, prev = 0, c = 0;
    prev = arr[l - 1] - '0';

    for(int i = l - 2; i >= 0; i--)
    {
        temp = prev + c;

        prev = get(temp, i);
        c = (temp + prev) / 10;

        if(i == 0)
        {
            if(prev == 0)
                return true;
            return false;
        }
    }

}

void fix()
{
    int num = 0, i;

    for(i = 0; i < l; i++)
        p[i] = arr[i];
    p[i] = '\0';


    for(int i = 0; i < l; i++)
    {
        if(arr[i] - '0' == 0)
            num++;
        else
            break;
    }


    if(num != 0)
    {
        for(i = 0; i < l - num; i++)
            arr[i] = arr[i + num];
        arr[i] = '\0';
        l = l - num;
    }

}

int get(int temp, int i)
{
    for(int j = 0; j < 10; j++)
        if((j + temp) % 10 == arr[i] - '0')
            return j;
}
