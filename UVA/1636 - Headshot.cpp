#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#define ll long long

char arr[MAX];
int n, cnt, keep;

int main()
{
    while(scanf("%s", arr) != EOF)
    {
        n = strlen(arr);

        cnt = keep = 0;

        for(int i = 0; i < n; i++)
        {
            if(arr[i] == '0')
            {
                if(arr[(i + 1) % n] == '0')
                    keep++;
                cnt++;
            }
        }

        double shoot = (double)keep / (double)cnt;
        double rot = (double)cnt / (double)n;

        if(shoot > rot)
            printf("SHOOT");
        else if(rot > shoot)
            printf("ROTATE");
        else
            printf("EQUAL");

        printf("\n");
    }

    return 0;
}

