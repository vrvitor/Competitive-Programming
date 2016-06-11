#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, p[60], w[60], P, W, pd[60][110];

int solve(int i, int rem) {
	if (i == n) return 0;
	if (rem == 0) return 0;

	int &ret = pd[i][rem];
	if (ret != -1) return ret;

	if (w[i] > rem)
		return ret = solve(i + 1, rem);
	return ret = max(solve(i + 1, rem), p[i] + solve(i + 1, rem - w[i]));
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p[i], &w[i]);
		}
		scanf("%d", &W);
		scanf("%d", &P);

		memset(pd, -1, sizeof pd);
		if (solve(0, W) >= P)
			printf("Missao completada com sucesso\n");
		else
			printf("Falha na missao\n");
	}

	return 0;
}