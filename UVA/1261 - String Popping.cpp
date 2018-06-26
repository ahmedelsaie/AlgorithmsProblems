#include <stdio.h>
#include <cstring>

struct word
{
    char array[30];
    int l;
};

word pop(int start, word x);
void fn(word x);

bool ok;

int main()
{
    int cases;
    word temp;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%s", temp.array);
        temp.l = strlen(temp.array);
        ok = false;
        fn(temp);
        if(ok)
            printf("1");
        else
            printf("0");
        printf("\n");
    }

    return 0;
}

void fn(word x)
{
    if(ok)
        return ;
    if(x.l == 0)
    {
        ok = true;
        return ;
    }
    word temp;
    char before = 'c';
    for(int i = 0; i < x.l; i++)
    {
        if(x.array[i] != before)
        {
            temp = pop(i, x);
            if(temp.l != -1)
                fn(temp);
        }
        before = x.array[i];
    }
}

word pop(int start, word x)
{
    char c = x.array[start];
    int i = start;
    while(i < x.l && x.array[i] == c)
        i++;
    int end = i;
    if(end - start == 1)
    {
        x.l = -1;
        return x;
    }
    for(i = start; i < x.l; i++)
    {
        x.array[i] = x.array[end - start + i];
    }
    x.array[i] = '\0';
    x.l = strlen(x.array);
    return x;
}
