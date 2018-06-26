#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[999];
    scanf("%s", input);
    printf("%d", check(input));
    return 0;
}




int check (char input[])
{
    int noofquestionmarl = 0;
    int noofdistinctletters = 0;
    char letters[28];
    int n = 1;
    int i = 0;
    int m = 0;
    int ans = 0;
    int flag = 0;
    int counter;
    while(input[n] != '\0')
    {
        if(input[n] == '?')
            noofquestionmarl++;
        else
        {
            if(isdigit(input[n]) != 1)
            {
                m = 0;
                while(letters[m] != '\0')
                {
                    if(input[n] == letters[m])
                    {
                        flag++;
                        break;

                    }
                    m++;
                }
                if(flag == 0)
                {
                    noofdistinctletters++;
                    letters[i] = input[n];
                    i++;
                    letters[i] = '\0';
                }

            }

        }
        n++;
    }
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////
    if(input[0] == '?')
        ans = 9;
    else if(isdigit(input[0]) != 1)
    {
        ans = 9;

        m = 0;
        while(letters[m] != '\0')
        {
            if(input[0] == letters[m])

            {
                noofdistinctletters--;
                break;
            }
            m++;


        }
    }

    ////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////
    if(ans != 0)
    {
        if(input[0] == '?')
            n = 10;
        else
            n = 9;


        for(counter = 0; counter < noofdistinctletters; counter++)
        {
            ans = ans * n;
            n--;

        }
        ans = ans * power(10, noofquestionmarl);
        return ans;
    }

    else

    {

        ans = 1;

        n = 10;
        for(counter = 0; counter < noofdistinctletters; counter++)
        {
            ans = ans * n;
            n--;


        }
        ans = ans * power(10, noofquestionmarl);
        return ans;
    }







}


int power(int x, int y)
{
    int ans, counter;
    ans = 1;
    for(counter = 0; counter < y; counter++)
        ans = ans * x;
    return ans;
}

