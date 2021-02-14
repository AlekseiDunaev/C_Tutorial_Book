#include <stdio.h>

int
main (int args, char *argv[])
{
    int i, j, c, nwhite, nother, maxFreqDigit;
    int ndigits[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; i++)
        ndigits[i] = 0;

    maxFreqDigit = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigits[c - '0'];
            if (ndigits[c - '0'] > maxFreqDigit)
                maxFreqDigit = ndigits[c - '0'];
        }
        else if (c == ' ' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }

    printf("DIGITS\n");
 
    for (i = 0; i < 10; i++)
    {
        printf("%d ", ndigits[i]);
    }
    
    printf("\n");

    for (i = 0; i <= maxFreqDigit; i++)
    {
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            if (ndigits[j] >= i)
            { 
                printf("%c ", '*');
            }
            else
            {
                printf("  ");
            }
        }
    }
    
    printf("\n\n");
    
    printf("nwhite: %d, nother: %d\n", nwhite, nother);

    return 0;
}