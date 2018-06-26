#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sent
{
    char array[256];
};

char itoc(int i);
int index(char array[]);
void parser(int i);
void print_accumulator(int flag);

sent words[150];
sent laws[1500];
char word[150];
char law[256];
int law_n = 0;
int no_words;
int no_laws;
char accumulator[256];

int main()
{
    int counter, counter2;

    while(scanf("%d", &no_words) != EOF)
    {

        for(counter = 0; counter < no_words; counter++)
            scanf("%s", words[counter].array);

        scanf("%d", &no_laws);
        for(counter = 0; counter < no_laws; counter++)
            scanf("%s", laws[counter].array);

        printf("--\n");

        for(counter = 0; counter < no_laws; counter++)
        {
            strcpy(law, laws[counter].array);
            law_n = index(law);
            for(counter2 = 0; counter2 < no_words; counter2++)
            {
                strcpy(word, words[counter2].array);
                parser(0);
            }
        }
    }

    return 0;
}

int index(char array[])
{
    int index = 0;
    while(array[index] != NULL)
        index++;
    return index;
}

void parser(int i)
{
    int counter;
    if(i == law_n - 1)
    {
        if(law[i] == '#')
        {
            accumulator[i] = '#';
            print_accumulator(0);
            return;
        }
        else
        {
            print_accumulator(1);
            return;
        }
    }

    if(law[i] == '#')
    {
        accumulator[i] = '#';
        parser(i + 1);
        return;
    }
    else
    {
        for(counter = 0; counter <= 9; counter++)
        {
            accumulator[i] = itoc(counter);
            parser(i + 1);
        }
        return;
    }
}

char itoc(int i)
{
    char ref[] = "0123456789";
    return ref[i];
}

void print_accumulator(int flag)
{
    int counter, counter2;
    if(flag == 0)
    {
        for(counter = 0; counter < law_n; counter++)
        {
            if(accumulator[counter] == '#')
                printf("%s", word);
            else
                printf("%c", accumulator[counter]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(counter2 = 0; counter2 <= 9; counter2++)
        {

            for(counter = 0; counter < law_n - 1; counter++)
            {
                if(accumulator[counter] == '#')
                    printf("%s", word);
                else
                    printf("%c", accumulator[counter]);
            }
            printf("%d", counter2);
            printf("\n");

        }
        return;
    }
}
