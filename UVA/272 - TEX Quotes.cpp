#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

char arr[90000];

int main()
{
    int i = 0;
    while(true)
    {
        scanf("%c", &arr[i]);
        if(arr[i] == '\0')
            break;
        else
            i++;
    }

    i = 0;
    bool switch1 = true;

    while(arr[i] != '\0')
    {
        if(arr[i] == '"')
        {
            if(switch1)
                printf("``");
            else
                printf("''");
            switch1 = !switch1;
            i++;
            continue;
        }
        printf("%c", arr[i]);
        i++;
    }

    return 0;
}

