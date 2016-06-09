#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int p[1010], w[1010];
int pd[1010][1010];

int solve(int rw, int i) {
	if (i == n) return 0;
	if (rw <= 0) return 0;

	int &ret = pd[rw][i];
	if (ret != -1) return ret;

	if (w[i] > rw)
		return ret = solve(rw, i + 1);

	return ret = max(p[i] + solve(rw - w[i], i + 1), solve(rw, i + 1));	
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p[i], &w[i]);
		}

		int g;
		scanf("%d", &g);

		int ans = 0;
		memset(pd, -1, sizeof pd);

		while (g--) {
			int mw;
			scanf("%d", &mw);
			ans += solve(mw, 0);
		}

		printf("%d\n", ans);
	}

	return 0;
}