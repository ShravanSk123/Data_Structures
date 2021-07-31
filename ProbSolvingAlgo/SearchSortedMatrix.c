// Search an element in row & column-wise sorted matrix

int search(int matrix[][], int m, int n, int x)
{
	if (n == 0)
		return 0;

	// start from top right element
	int i = 0, j = n - 1;
	while (i < m && j >= 0)
	{
		if (matrix[i][j] == x)
		{
			printf("Element found at %d, %d\n", i, j);
			return 1;
		}
		if (matrix[i][j] > x)
			j--;
		else
			i++;
	}

	printf("Element not found in matrix\n");
	return 0;
}

// Time complexity is O(m+n)
// Space complexity is O(1)
