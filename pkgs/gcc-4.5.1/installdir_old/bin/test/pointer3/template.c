#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int foo()
{
		printf("\n In foo");
}


int main()
{
		foo();
		printf("\n Hello world");
		
		return 0;
}
