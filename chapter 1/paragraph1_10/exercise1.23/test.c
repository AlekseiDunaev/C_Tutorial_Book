#include <stdio.h>

#define LINELENGHT 80

//Comment #1

int main ()
{
	int i = 0;
	char c;

	while ((c = getchar()) != EOF)
    {
        if (c == '\n' || i == LINELENGHT)
        {
            putchar('\n'); //Comment #2
			i = 0;
			if (c == '\n') continue;
        }

	//Comment #3
	//Comment #4

	/*
		Multistring connent #1
	*/

		i++;
        putchar(c); /* Multistring comment #2
		Multistring comment #2 /* Not comment */
		*/
    }
}

