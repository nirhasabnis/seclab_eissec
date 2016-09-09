#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	  int i, j, k, l, m, n, o, p, q, r, *s, res;

		scanf("%d", &i);
		scanf("%d", &j);
		scanf("%d", &k);
		scanf("%d", &l);

		scanf("%d", &m);
		scanf("%d", &n);
		scanf("%d", &o);
		scanf("%d", &p);
		
		scanf("%d", &q);
		scanf("%d", &r);
		scanf("%d", s);

		res = (
					 (i + j) +
					 (k + l + 
						 (m + n + 
							 (o + p + 
								 (q + r + 
									 (*s) 
								 )
							 )
						 )
					 )
				  );							 

		printf("\n res = %d, *s = %d\n", res, *s);

		return 0;
}
