#include <cstdio>

char grid[30][30];
int n;
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int floodfill(int x, int y, char c1, char c2) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 0;
	if (grid[x][y] != c1) return 0;
	grid[x][y] = c2;
	int ans = 1;
	for (int i = 0; i < 8; i++) {
	 	floodfill(x + dx[i], y + dy[i], c1, c2);
	}
	return ans;
}

int main() {
	int tc = 1;

	while (scanf("%d", &n) != EOF) {
		getchar();

		for (int i = 0; i < n; i++)
			fgets(grid[i], 29, stdin);

		int ans = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans += floodfill(i, j, '1', '.');
			}
		}
		printf("Image number %d contains %d war eagles.\n", tc++, ans);
	}

	return 0;
}