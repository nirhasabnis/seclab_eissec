#include <stdio.h> 

#define VALUE 6 

void main()  
{    
	int i, j = 1;
	for (i=1; i<=VALUE; i++)      
  	j=j*i;    

	printf("The factorial of %d is %d\n",VALUE,j);  
} 

