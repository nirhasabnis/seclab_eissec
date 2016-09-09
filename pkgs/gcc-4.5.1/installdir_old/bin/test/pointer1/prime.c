#include <stdio.h>

void main()
{
		int i,num=1;

		while(num<=100)
		{ i=2; while(i<=num)
				{ if(num%i==0)
						break;
						i++; }
						if(i==num)
								printf("\n%d is Prime",num);
						num++;
		}
}
