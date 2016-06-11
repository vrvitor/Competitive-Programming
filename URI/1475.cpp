#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, c, t1, t2, f[1010], g[2020], pd[1010][2020];

int solve(int i, int x) {
	if (i == n) return 0;

	int &ret = pd[i][x];
	if (ret != -1) return ret;

	if (f[i] <= g[x])
		return ret = solve(i + 1, x);

	return ret = min(t1 + solve(i + 1, 2 * i + 1), t2 + solve(i + 1, 2 * i + 2));
}

int main() {
	while (scanf("%d %d %d %d", &n, &c, &t1, &t2) != EOF) {
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			f[i] = x;
			g[2 * i + 1] = f[i] + t1;
			g[2 * i + 2] = f[i] + t2;
		}
		g[0] = 0;

		memset(pd, -1, sizeof pd);
		printf("%d\n", solve(0, 0));
	}


	return 0;
}