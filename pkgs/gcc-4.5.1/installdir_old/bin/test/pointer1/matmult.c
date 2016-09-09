#include <stdio.h>

void main()
{
		int a[10][10],b[10][10],c[10][10],i,j,k,m,n,p,q;

		printf("Enter The Rows And Cloumns And Of The First Matrix:");
		scanf("%d %d",&m,&n);
		printf("\nEnter The Rows And Cloumns And Of The Second Matrix:");
		scanf("%d %d",&p,&q);

		printf("\nEnter Elements Of The First Matrix:\n");

		for(i=0;i< m;i++)
		{
				for(j=0;j< n;j++)
				{
						scanf("%d",&a[i][j]);
				}
		}

		printf("\nEnter Elements Of The Second Matrix:\n");

		for(i=0;i< p;i++) {
				for(j=0;j< q;j++)
						scanf("%d",&b[i][j]);
		}

		printf("The First Matrix Is:\n"); /* Print the first matrix */

		for(i=0;i< m;i++) {
				for(j=0;j< n;j++)
						printf(" %d ",a[i][j]);
				printf("\n");
		}

		printf("The Second Matrix Is:\n"); /* Print the second matrix */

		for(i=0;i< p;i++) {
				for(j=0;j< q;j++)
						printf(" %d ",b[i][j]);
				printf("\n");
		}

		if(n!=p) {
				printf("Aborting./nMultiplication Of The Above Matrices Not Possible.");
				exit(0);
		}
		else {
				for(i=0;i< m;i++) {
						for(j=0;j< q;j++) {
								c[i][j] = 0;

								for(k=0;k< n;k++) {
										c[i][j] = c[i][j] + a[i][k] * b[k][j];
								}
						}
				}

				printf("\nThe Product Of The Two Matrices Is:\n\n");

				for(i=0;i< m;i++) {
						for(j=0;j< q;j++) {
								printf(" %d ",c[i][j]);
						}

						printf("\n");
				}
		}

		return 0;

} 
