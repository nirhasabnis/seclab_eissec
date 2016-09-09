#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int func()
{
		int i = 2 + 3;
		return i;
}

int main(int argc, char** argv)
{
		printf("%d%s%d%d%d%d%d", argc,argv[0],5,6,7,8,9);

		int i = argc;

		int l = argc - 1;
		int k = argc + 23;

		i = func();

		printf("%d%d%d", i,l,k);


		//scanf("%d", &i);
		k = i * 100;
		k = k + 10;

		printf("%d%d%d",k,i,argc);
}
