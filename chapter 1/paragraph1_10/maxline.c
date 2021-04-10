#include <stdio.h>

#define MAXSYMBOLS 1000

int getlinemy();
void copy(void);

int max;
char last[MAXSYMBOLS];
char longest[MAXSYMBOLS]; 

int main()
{
    int len;
    extern int max;
    extern char longest[];
    
    max = 0;

    while((len = getlinemy()) > 0)
    if (len > max)
    {
        max = len;
        copy();
    }

    if (max > 0) printf("Longest string: %s, length: %d\n", longest, max);
    
}

int getlinemy()
{
    char c;
    int i;
    extern char last[];

    for (i = 0; i < MAXSYMBOLS - 1 && (c = getchar()) != EOF && c != '\n'; ++i) last[i] = c;
    if (c == '\n') {
        last[i] = c;
        ++i;
    }
    last[i] = '\0';
    
    return i;
}

void copy(void)
{
    int i;
    extern char longest[MAXSYMBOLS], last[MAXSYMBOLS];
    
    i = 0;
    while ((longest[i] = last[i]) != '\0') ++i;
}