#include <stdio.h>

int fahr;

#define LOW  0
#define HIGH  270
#define STEP  30

int
main(int argc, char *argv[])
{
    printf("Fahr  Celsius\n");

    for (fahr = LOW; fahr <= HIGH; fahr += STEP)
    {
        printf("%4d%9.1f\n", fahr, 5.0 / 9.0 * (fahr -32));
    }

    return 0;
}