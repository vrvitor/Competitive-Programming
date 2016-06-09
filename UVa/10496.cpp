#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, x[15], y[15], dist[15][15], pd[15][1 << 15];

int solve(int id, int bitmask) {
	if (bitmask == (1 << (n + 1)) - 1) return dist[id][0];

	int &ret = pd[id][bitmask];
	if (ret != -1) return ret;

	int aux = 2000000000;
	for (int i = 0; i <= n; i++) {
		if (i != id && !((1 << i) & bitmask)) {
			aux = min(aux, dist[i][id] + solve(i, bitmask | (1 << i)));
		}
	}

	return ret = aux;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int xs, ys;
		scanf("%d %d", &xs, &ys);

		scanf("%d %d", &x[0], &y[0]);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dist[i][j] = abs(x[j] - x[i]) + abs(y[j] - y[i]);
				dist[j][i] = dist[i][j];
			}
		}

		memset(pd, -1, sizeof pd);
		printf("The shortest path has length %d\n", solve(0, 0));
	}

	return 0;
}