#include <cstdio>

int main() {
	int matrix[110][110];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);

			if (i > 0) 			
				x += matrix[i - 1][j];
			if (j > 0) 			
				x += matrix[i][j - 1];
			if (i > 0 && j > 0) 
				x -= matrix[i - 1][j - 1];

			matrix[i][j] = x;
		}
	}

	int maxSum = matrix[0][0];

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < n; y1++) {
			for (int x2 = x1; x2 < n; x2++) {
				for (int y2 = y1; y2 < n; y2++) {
					int sum = matrix[x2][y2];

					if (x1 > 0)
						sum -= matrix[x1 - 1][y2];
					if (y1 > 0) 			
						sum -= matrix[x2][y1 - 1];
					if (x1 > 0 && y1 > 0)	
						sum += matrix[x1 - 1][y1 - 1];

					if (sum > maxSum)
						maxSum = sum;
				}
			}
		}
	}

	printf("%d\n", maxSum);

	return 0;
}