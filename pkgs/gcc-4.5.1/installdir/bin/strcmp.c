#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int strcmp_ispaces (const char* s1, const char* s2)
{
	if (!s1 || !s2)
		return 1;

	while (1) {
		while (*s1 &&
					(*s1 == ' ' ||
					 *s1 == '\t'))
			s1++;

		while (*s2 &&
					(*s2 == ' ' ||
					 *s2 == '\t'))
			s2++;

		if (*s1 == *s2) {
			if (! *s1)
				return 0;
			s1++; s2++;
		} else {
			return 1;
		}
	}
}

int main(int argc, char* argv[])
{
		if (strcmp_ispaces (argv[1], argv[2]) == 0)
			printf ("\nEqual: %s %s\n", argv[1], argv[2]);
		else
			printf ("\n Not equal: %s %s\n", argv[1], argv[2]);
		return 0;
}
