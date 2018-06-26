#include <stdio.h>
#include <cstring>

int comp_cycle(int i);
bool check();

char input[50];
int array[50];
bool flags[50];

int main()
{
    int cases;
    int cnt = 0;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%s", input);

        if(check())
            printf("Yes");
        else
            printf("No");

        printf("\n");
    }

    return 0;
}

bool check()
{
    for(int i = 0; i < 26; i++)
        array[i] = input[i] - 'A';
    int arr[30];
    memset(arr, 0, sizeof(arr));
    int even = 0, odd = 0;

    memset(flags, true, sizeof(flags));

    int cyc = 0;

    for(int i = 0; i < 26; i++)
    {
        if(flags[i])
        {
            int x = comp_cycle(i);
            arr[x]++;
        }
    }

    for(int i = 2; i <= 26; i += 2)
        if(arr[i] % 2 != 0)
            return false;
    return true;

    return (cyc % 2 == 0 && even >= odd); // || (cyc%2!=0 && odd%2==0);
}

int comp_cycle(int i)
{
    flags[i] = false;

    if(array[i] == i)
        return 1;
    int curr = array[i];
    flags[curr] = false;

    int cnt = 1;
    while(curr != i)
    {
        curr = array[curr];
        flags[curr] = false;
        cnt++;
    }
    flags[curr] = false;
    return cnt;
}


