#include <stdio.h>

#define SYMBOLS_COUNT 94

int
main (int args, char *argv[])
{
    int i, j, c;
    int nsymbol[SYMBOLS_COUNT];

    for (i = 0; i < SYMBOLS_COUNT; i++)
        nsymbol[i] = 0;

    while ((c = getchar()) != EOF)
    {
        ++nsymbol[c - ' '];
    }

    printf("SYMBOLS\n");
 
    for (i = 0; i < SYMBOLS_COUNT; i++)
    {
        if (nsymbol[i] > 0) {
            printf("%c %4d  ", i + ' ', nsymbol[i]);
            for (j = 0; j <= nsymbol[i]; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    
    printf("\n");

    return 0;
}