#include "../inc/temperature.h"

int fahr;

#define LOW  0
#define HIGH  270
#define STEP  30

float FtoC (int fahr);

int
main(int argc, char *argv[])
{
    printf("Fahr  Celsius\n\n");

    for (fahr = LOW; fahr <= HIGH; fahr += STEP)
    {
        printf("%4d%9.2f\n", fahr, FtoC(fahr));
    }

    return 0;
}

float
FtoC (int fahr)
{
    return (5.0/9.0 * (fahr - 32));
} 
