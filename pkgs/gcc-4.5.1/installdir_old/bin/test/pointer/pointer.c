#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int i = 100;
	int* p = &i;
	printf("%d", *p);
	return 0;
}
