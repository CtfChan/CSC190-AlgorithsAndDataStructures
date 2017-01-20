#include "lab2.h"


void readMatrix(char * filename, int * matrix)
{

	FILE *fp = fopen(filename, "r");
	int i, j;

	for (i = 0; i < MATSIZE; i++) 
	{
		for (j = 0; j < MATSIZE; j++) 
		{
			fscanf(fp, "%d", (matrix + i * MATSIZE + j));
		}
	}	
	fclose(fp);


}

void printMatrix(int n, int *A)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j ++)
		{
			printf("%d ", *(A + i * n + j));
			
		}
		printf("\n"); 
	}
}

void sum(int *A, int *B, int *res, int n)
{
	int i, j;
	for (i = 0; i < n; i++) 
	{
		for (j  = 0; j < n; j ++) 
		{
		*(res + i * n + j) = *(A + i * n + j) + *(B + i * n + j);	
		}
	}
}

void sub(int *A, int *B, int *res, int n)
{
	int i, j;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
		{
		*(res + i * n + j) = *(A + i * n + j) - *(B + i * n + j);
		}
	
	}
}

int determinant(int n, int *matrix)
{
	int res, i, j, k;
	res = 0;
	if (n == 1)
	{
		return *matrix;
	}

	else if (n == 2)
	{
		res = *(matrix + 0 * 2 + 0) * *(matrix + 1 * 2 + 1) - *(matrix + 0 * 2 + 1) * *(matrix + 1 * 2 + 0);
		return res;   	
	}
	
	else 
	{
		for (k = 0; k < n; k ++) {
			int new[n-1][n-1];
			for (i = 0; i < n-1; i++) {
				for (j = 0; j < n-1; j++) {

					if (j < k) {
					new[i][j] = *(matrix + n * (i+1) + j);
					}	
					else {
					new[i][j] = *(matrix + n * (i+1) + (j+1)); 
					}



				} 

			}
			res += *(matrix + k) * determinant(n-1, *new) * pow(-1, k + 2);

		}
		return res; 		

 
	}









}
