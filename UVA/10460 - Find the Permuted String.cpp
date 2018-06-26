#include <stdio.h>
#include <cstring>

void reset();
void revers_fn(int i, int collect);
int start();
void fill_places(long long place, long long power, long long accum);
void fn(int place);
void rotate(int x);
int search(char x);
void swap(int x, int y);
int fac(int x);
void start_fn();

long long places[35];
long long desired;
char word[35];
char result[35];
long long length;
long long first;
long long startv;

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%s", word);
        scanf("%d", &desired);
        length = strlen(word);
        reset();

        start_fn();
        fill_places(first, startv, 0);
        strcpy(result, word);
        fn(0);
        printf("%s\n", result);
    }


    return 0;
}

void fill_places(long long place, long long power, long long accum)
{
    if(place == length)
        return;
    long long i = 1;
    for(i = 0; i <= place; i++)
    {
        if(i * power >= desired - accum)
            break;
    }
    places[place] = i;
    long long new_accum = (i - 1) * power;
    new_accum = accum + new_accum;
    fill_places(place + 1, power / (place + 2), new_accum);
}

void fn(int place)
{
    if(place == length)
    {
        result[length] = '\0';
        return;
    }

    int find = search(word[place]);
    rotate(place);

    for(int i = 1; i < places[place]; i++)
        swap(i - 1, i);
    fn(place + 1);
    return;
}

void start_fn()
{
    long long power = 1;
    long long fac = length;
    for(long long i = length - 1; i >= 0; i--)
    {
        for(long long j = 0; j <= i + 1; j++)
            if(j * power >= desired)
            {
                first = i;
                startv = power;
                return;
            }
        power = power * fac;
        fac--;
    }
}

void reset()
{
    for(int i = 0; i < 35; i++)
        places[i] = 1;
    return ;
}

int search(char x)
{
    for(int i = 0; i < length; i++)
        if(result[i] == x)
            return i;
}

void rotate(int x)
{
    char c = result[x];
    for(int i = x; i >= 1; i--)
        result[i] = result[i - 1];
    result[0] = c;
}

void swap(int x, int y)
{
    char help = result[x];
    result[x] = result[y];
    result[y] = help;
    return;
}
