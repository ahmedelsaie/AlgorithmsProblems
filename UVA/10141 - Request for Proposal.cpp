#include <stdio.h>
#include <cstring>

void fn();

int n_prop;
int n_req;
char input[85];
char win[85];
int max_req, curr_req;
float price, curr_price;

int main()
{
    int cases = 1;
    bool flag = true;
    while(true)
    {
        max_req = 0;

        scanf("%d %d", &n_req, &n_prop);
        if(n_prop == 0 && n_req == 0)
            break;
        gets(input);

        for(int i = 0; i < n_req; i++)
            gets(input);

        for(int i = 0; i < n_prop; i++)
        {
            gets(input);
            scanf("%f %d", &curr_price, &curr_req);
            fn();
            gets(input);

            for(int k = 0; k < curr_req; k++)
                gets(input);
        }

        if(flag)
            flag = false;
        else
            printf("\n");

        printf("RFP #%d\n", cases);
        printf("%s\n", win);

        cases++;
    }
    return 0;
}

void fn()
{
    if(curr_req > max_req)
    {
        max_req = curr_req;
        price = curr_price;
        strcpy(win, input);
        return ;
    }

    if(curr_req == max_req)
        if(curr_price < price)
        {
            strcpy(win, input);
            price = curr_price;
            return ;
        }
    return;
}

