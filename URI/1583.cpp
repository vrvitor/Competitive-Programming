#include <cstdio>

int n, m;
char grid[60][60];

void floodfill(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (grid[x][y] != 'T' && grid[x][y] != 'A') return;
	grid[x][y] = '.';
	floodfill(x + 1, y);
	floodfill(x - 1, y);
	floodfill(x, y + 1);
	floodfill(x, y - 1);
}

int main() {
	while (scanf("%d %d", &n, &m), n || m) {
		getchar();
		for (int i = 0; i < n; i++)
			fgets(grid[i], 59, stdin);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == 'T') 
					floodfill(i, j);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == '.')
					grid[i][j] = 'T';
		for (int i = 0; i < n; i++)
			printf("%s", grid[i]);
		printf("\n");
	}

	return 0;
}