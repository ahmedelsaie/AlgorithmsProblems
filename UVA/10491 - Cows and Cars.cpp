#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

double fn();

int cows, cars, shows;

int main()
{
    while(scanf("%d %d %d", &cows, &cars, &shows) != EOF)
        printf("%.5lf\n", fn());

    return 0;
}

double fn()
{
    double ret, dcows, dcars, dshows;
    dcows = (double)cows, dcars = (double)cars, dshows = (double)shows;

    ///choose cow
    ret = (dcows / (dcows + dcars)) * (dcars / (dcows + dcars - 1 - dshows));

    ///choose car
    ret = ret + (dcars / (dcows + dcars)) * ((dcars - 1) / (dcows + dcars - 1 - dshows));

    return ret;
}
