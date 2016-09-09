#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
		int i, j;
		char buf1[256];
		char buf2[256];
		char combined[512];
		register char ch1;
		register char ch2;
		register char ch3;

		for(i = 0; i < 256; i++)
		{
			for(j = 0; j < 256; j++)
			{
				ch1 = buf1[j+1];
				if(ch1 < buf1[j]) 
				{
						buf1[j+1] = buf1[j];
						buf1[j] = ch1;
				}

				ch2 = buf2[j+1];
				if(ch2 < buf2[j]) 
				{
						buf2[j+1] = buf2[j];
						buf2[j] = ch2;
				}

				if(ch1 < ch2)
				{
						combined[j] = ch1;
						combined[j+1] = ch2;
				}
				else
				{
						combined[j] = ch2;
						combined[j+1] = ch1;
				}
			}
		}

		for(i = 0; i < 256; i++)
		{
			printf("\n %c %c %c", buf1[i], buf2[i], combined[i]); 
		}

		return 0;
}
