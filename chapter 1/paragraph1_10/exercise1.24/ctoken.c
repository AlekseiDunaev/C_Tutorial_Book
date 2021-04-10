#include <stdio.h>

#define LINELENGHT 80

int main ()
{
	int i = 0;
	char c;

	while ((c = getchar()) != EOF)
    {
        if (c == '\n' || i == LINELENGHT)
        {
            putchar('\n');
			i = 0;
			if (c == '\n') continue;
        }
		i++;
        putchar(c);
    }
}
