#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int x;
string a[300];
void print_single(int x);
void fn();
void print_tenth(int x);

int main()
{
    a[0] = "zero";
    a[1] = "one";
    a[2] = "two";
    a[3] = "three";
    a[4] = "four";
    a[5] = "five";
    a[6] = "six";
    a[7] = "seven";
    a[8] = "eight";
    a[9] = "nine";

    a[10] = "ten";
    a[11] = "eleven";
    a[12] = "twelve";
    a[13] = "thirteen";
    a[14] = "fourteen";
    a[15] = "fifteen";
    a[16] = "sixteen";
    a[17] = "seventeen";
    a[18] = "eighteen";
    a[19] = "nineteen";
    scanf("%d", &x);
    fn();

    return 0;
}

void fn()
{
    if(x <= 19)
        cout << a[x] << endl;
    else
    {
        int sec;
        int first = x % 10;
        x = x / 10;
        sec = x;

        print_tenth(sec);
        if(first != 0)
            printf("-"), print_single(first);
    }

}

void print_single(int x)
{
    switch (x)
    {
    case 0:
        printf("zero");
        return;

    case 1:
        printf("one");
        return;

    case 2:
        printf("two");
        return;
    case 3:
        printf("three");
        return;
    case 4:
        printf("four");
        return;
    case 5:
        printf("five");
        return;
    case 6:
        printf("six");
        return;
    case 7:
        printf("seven");
        return;

    case 8:
        printf("eight");
        return;

    case 9:
        printf("nine");
        return;

    }
}

void print_tenth(int x)
{
    switch (x)
    {
    case 2:
        printf("twenty");
        return;

    case 3:
        printf("thirty");
        return;
    case 4:
        printf("forty");
        return;
    case 5:
        printf("fifty");
        return;
    case 6:
        printf("sixty");
        return;
    case 7:
        printf("seventy");
        return;
    case 8:
        printf("eighty");
        return;

    case 9:
        printf("ninety");
        return;


    }
}
