#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

struct sent
{
    char array[303];
};

int length(int i);

struct sent ans[303];

int main()
{
    int n = 0;
    int i, counter, counter2;
    char c;
    int flag = 1;
    int max = 0;
    int l;

    while(scanf("%c", &c) != EOF)
    {
        i = 0;
        while(c != '\n')
        {
            if(c != '\t')
            {
                ans[n].array[i] = c;
                i++;
            }


            scanf("%c", &c);
        }
        ans[n].array[i] = '\0';
        n++;
    }

    for(counter = 0; counter < n; counter++)
    {
        l = length(counter);
        if(l > max)
            max = l;

    }

    i = 0;
    int r = 0;


    for(counter2 = 0; counter2 < max; counter2++)
    {

        for(counter = n - 1; counter >= 0; counter--)
        {
            if(ans[counter].array[counter2] != '\0')
            {

                printf("%c", ans[counter].array[counter2]);

            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}

int length(int i)
{
    int counter;
    for(counter = 0; counter < 300; counter++)
        if (ans[i].array[counter] == '\0')
            return counter;
}


