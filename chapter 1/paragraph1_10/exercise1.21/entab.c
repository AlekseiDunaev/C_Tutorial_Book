#include <stdio.h>

#define ENINTABSYMBOLS 4
#define ENSWAP "\t"

int main()
{
    char c;
    int en;

    en = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            en++;
            while (en < ENINTABSYMBOLS && (c = getchar()) == ' ')
            {
                en++;
            }
            if (en == ENINTABSYMBOLS)
            {
                printf(ENSWAP);
                en = 0;
            }
            else
            {
                while (en != 0)
                {
                    printf(" ");
                    en--;
                }
            }
        }

        putchar(c);
    }

    return 0; 
}