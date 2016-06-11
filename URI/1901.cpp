#include <cstdio>
#include <map>

using namespace std;

int main() {
	int n, matrix[210][210];

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}

		int ans = 0;
		map<int, int> m;

		for (int i = 0; i < 2 * n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;

			if (!m[matrix[x][y]]) {
				ans++;
				m[matrix[x][y]] = 1;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}