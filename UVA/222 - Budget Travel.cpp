#include <stdio.h>
#include <stdlib.h>

float fn(float capacity, int station, float amount);
int val(float capacity, int n);
void distance();

float total_dist;
float total_capacity;
float miles_gallon;
float cost_first;
int no_stations;

float dist[55];
float price[55];

int main()
{
    float h;
    int n = 0;
    int counter;
    scanf("%f", &total_dist);

    while(((int)total_dist) != -1)
    {

        scanf("%f %f %f %d", &total_capacity, &miles_gallon, &cost_first, &no_stations);

        for(counter = 0; counter < no_stations; counter++)
            scanf("%f%f", &dist[counter], &price[counter]);


        dist[counter] = total_dist - dist[counter - 1];

        distance();
        h = total_capacity;
        h = h - dist[0] / miles_gallon;

        printf("Data Set #%d\nminimum cost = $%.2f\n", n + 1, fn(h, 0, 0) / 100 + cost_first);
        scanf("%f", &total_dist);
        n++;
    }

    return 0;
}

void distance()
{
    int counter;

    for(counter = no_stations - 1; counter > 0; counter--)
    {
        dist[counter] = dist[counter] - dist[counter - 1];
    }

}

float fn(float capacity, int station, float amount)
{
    if(station == no_stations - 1)
    {
        if(val(capacity, station) == 1)
        {
            return amount;
        }
        else
        {
            return (amount + 200 + (total_capacity - capacity) * price[station]);
        }
    }

    if(capacity > .5 * total_capacity)
    {
        if(val(capacity, station) == 1)
            return fn(capacity - dist[station + 1] / miles_gallon, station + 1, amount);
        else
            return fn(total_capacity - dist[station + 1] / miles_gallon, station + 1, (amount + 200 + (total_capacity - capacity) * price[station]));
    }

    float r, m;
    if(val(capacity, station) == 0)
    {
        r = fn(total_capacity - dist[station + 1] / miles_gallon, station + 1, amount + 200 + (total_capacity - capacity) * price[station]);
        return r;
    }
    else
    {
        r = fn(total_capacity - dist[station + 1] / miles_gallon, station + 1, amount + 200 + (total_capacity - capacity) * price[station]);
        m = fn(capacity - dist[station + 1] / miles_gallon, station + 1, amount);
        if(m < r)
            return m;
        else
            return r;
    }
}

int val(float capacity, int n)
{
    float d;
    d = capacity * miles_gallon;
    if(d < dist[n + 1])
        return 0;
    else
        return 1;
}
