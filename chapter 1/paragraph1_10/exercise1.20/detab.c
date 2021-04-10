#include <stdio.h>

#define TABSWAP "        "

int main()
{
    char c;

    while((c = getchar()) != EOF) {
        if (c == '\t') {
            printf(TABSWAP);
        }
        else {
            putchar(c);
        }
    }

    return 0; 
}