#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
		int i = 0;
		scanf("%d", &i);

		char al = i & 0x000000FF;
		char ah = (i & 0x0000FF00) >> 8;

		char ax[2];
		ax[0] = (i & 0x0000FFFF);
		ax[1] = (i & 0x0000FF00) >> 8;

		printf("i=%x ax=%x:%x ah=%x al=%x", i, ax[1], ax[0], ah, al);
		return 0;
}
