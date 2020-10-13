# define SIZE 10
# define INT_MAX 2147483647


int main()
{
	int numberOfMatrix;

    printf("How many matrices do you have for multiplication? : ");
     scanf("%d",&numberOfMatrix);

    int matrixOrdersArray[++numberOfMatrix];

    printf("Enter %d dimensions of matrices in array :-\n", numberOfMatrix);
    for(int i=0; i < numberOfMatrix; i++)
        scanf("%d", &matrixOrdersArray[i]);


	printf("\n\nResultant Matrix :- \n");

	int res = chainMultiply(matrixOrdersArray, numberOfMatrix);
	printf("Minimum Multiplication : %d\n\n", res);
}


int chainMultiply(int p[], int n)
{
	int m[SIZE][SIZE];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
            m[i][j] = 0;
	}


	for(int z = 1; z < n; z++)
	{
		for(int i=1, j=z+1; i<n-1 && j<n; i++, j++)
		{
			int res = INT_MAX;

			for(int k = i; k < j; k++)
			{
				res = min(res, m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
			}
			m[i][j] = res;
		}
	}

	printMatrix(m, n);

	return m[1][n-1];
}


int min(int a, int b)
{
	return a < b ? a : b;
}


void printMatrix(int arr[SIZE][SIZE], int n)
{
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
            printf("%-10d", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}
