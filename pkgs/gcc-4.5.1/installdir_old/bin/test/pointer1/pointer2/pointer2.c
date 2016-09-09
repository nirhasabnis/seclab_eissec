#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
		char* c = NULL;
		char d = *c;
		printf("%c", d);
		return 0;
}
