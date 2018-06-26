#include <stdio.h>
bool check(int capacity);
void fn();
void print();

int scribe;
int no;
int books[800];
int hashes[800];

int ans;

int main()
{
    int cases;
    scanf("%d", &cases);


    for(int k = 0; k < cases; k++)
    {
        scanf("%d %d", &no, &scribe);

        for(int i = 0; i < no; i++)
            scanf("%d", &books[i]);

        fn();
        print();
        if(k < cases)
            printf("\n");
    }

    return 0;
}

void fn()
{
    long long big = 0, small = 0;
    long long mid;

    for(int i = 0; i < no; i++)
        big += books[i];

    while(big > small)
    {

        mid = big - small;
        mid = small + .5 * mid;

        if(check(mid))
        {
            big = mid;
            ans = mid;
        }
        else
        {
            small = mid + 1;

        }
    }

    if(check(small))
    {
        ans = small;
    }

    if(check(big))
    {
        ans = big;
    }

}

void print()
{
    long long sum = 0;

    for(int i = 0; i < scribe; i++)
        hashes[i] = i;

    int j = scribe - 1;

    for(int i = no - 1; i > 0; i--)
    {
        if(sum + books[i] <= ans && hashes[j] <= i)
            sum += books[i];
        else
        {
            sum = 0;
            sum = books[i];
            hashes[j] = i + 1;
            j--;
        }
    }

    j = 1;

    for(int i = 0; i < no; i++)
    {
        if(hashes[j] == i && j > 0)
        {
            j++;
            printf("/ ");
        }
        printf("%d", books[i]);

        if(i < no - 1)
            printf(" ");
    }
    return ;
}

bool check(int capacity)
{
    int s = 0;
    int sum = 0;
    int i = 0;

    while(i < no)
    {
        sum += books[i];
        if(sum > capacity)
        {
            s++;
            i--;
            sum = 0;
        }
        if(s >= scribe)
            return false;
        i++;
    }
    return true;
}


