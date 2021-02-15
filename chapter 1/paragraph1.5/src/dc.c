#include <stdio.h>

#define IN 1
#define OUT 0

int nc, nl, nw;
int c;
int state;

int
main(int argc, char *argv[])
{
    nc = nl = nw = 0;
    for(nc = 0; (c = getchar()) != EOF; nc++)
    {
        if (c == '\n') {
            nl++;
        }
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    printf("Char ocunt: %d, world count: %d, line count: %d\n", nc, nw, nl);
    printf("EOF ASCII number: %d\n", EOF);
    printf("\\n ASCIInumber: %d\n", '\n');
    printf("\\t ASCIInumber: %d\n", '\t');
    printf("\'0\' ASCII number: %d\n", '0');
    printf("1 ASCII number: %d\n", '1');

    return 0;
}