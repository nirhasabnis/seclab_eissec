#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
		int a[3],b[3],c[3];
		int i, j,k, max, new;

		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		scanf("%d %d %d", &b[0], &b[1], &b[2]);

		max = 0;

		for(i = 0; i < 3; i++)
		{
				new = a[i] * b[i];
				if(new > max)
						max = new;
		}

		printf("\n Answer is: %d", max);

		return 0;
}
