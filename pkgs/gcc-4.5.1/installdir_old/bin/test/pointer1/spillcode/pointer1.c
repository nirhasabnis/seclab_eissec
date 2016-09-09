#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	  int i, j, k, l;

		scanf("%d", &i);
		scanf("%d", &j);
		scanf("%d", &k);
		scanf("%d", &l);

		int* n = &k;
		int m = (i*j*k*(l+i))*(((k*l*2*i*(*n))+(l+i-(*n)))*j);

		printf("\n m = %d, *n = %d\n", m, *n);

		return 0;
}
