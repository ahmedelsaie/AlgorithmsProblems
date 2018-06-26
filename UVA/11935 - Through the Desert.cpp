#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

struct event
{
    char type;
    int first;
    int second;
};

int pre_process();
float max(float x, float y);
void fn();

event array[55];
event imp[55];
char temp[50];
int n;

float ans = 0;

int main()
{
    while(true)
    {
        ans = 0;
        n = 0;
        gets(temp);
        if(pre_process() == -1)
            break;
        else
            n++;

        while(true)
        {
            gets(temp);
            if(pre_process() == 1)
                break;
            n++;
        }
        n++;
        fn();
        printf("%.3f\n", ans);
    }

    return 0;
}

void fn()
{
    float leaks = 0;
    float last = 0;
    float last_rate = (float)array[0].second;
    float temp = 0;

    for(int i = 1; i < n; i++)
    {
        temp += (leaks) * (float)(array[i].first - array[i - 1].first);

        if(array[i].type == 'f')
        {
            temp += ((float)(array[i].first - last) / 100) * last_rate;
            last = array[i].first;
            last_rate = array[i].second;
            continue;
        }

        if(array[i].type == 'g')
        {
            temp += ((float)(array[i].first - last) / 100) * last_rate;
            ans = max(ans, temp);
            temp = 0;
            last = array[i].first;
            continue;
        }

        if(array[i].type == 'G')
        {
            temp += ((float)(array[i].first - last) / 100) * last_rate;
            ans = max(ans, temp);
            temp = 0;
            last = array[i].first;
            continue;
        }

        if(array[i].type == 'l')
        {
            leaks++;
            continue;
        }

        if(array[i].type == 'm')
        {
            leaks = 0;
            continue;
        }
    }
    return;
}


int pre_process()
{
    char *first;
    event current;


    first = strtok(temp, " ");
    current.first = atoi(first);

    first = strtok(NULL, " ");


    if(strcmp(first, "Mechanic") == 0)
    {
        current.type = 'm';
        array[n] = current;
        return 0;
    }

    if(strcmp(first, "Leak") == 0)
    {
        current.type = 'l';
        array[n] = current;

        return 0;
    }


    if(strcmp(first, "Goal") == 0)
    {
        current.type = 'G';
        array[n] = current;
        return 1;
    }

    if(strcmp(first, "Gas") == 0)
    {
        current.type = 'g';
        array[n] = current;
        return 0;
    }

    if(strcmp(first, "Fuel") == 0)
    {
        first = strtok(NULL, " ");
        first = strtok(NULL, " ");

        current.type = 'f';


        current.second = atoi(first);
        if(current.second == 0)
            return -1;
        array[n] = current;
        return 0;
    }

    return 0;


}

float max(float x, float y)
{
    if(x > y)
        return x;
    else
        return y;
}
