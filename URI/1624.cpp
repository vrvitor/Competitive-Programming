#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, p[110], w[110], pd[100100][110];

int solve(int rem, int i) {
	if (i == n) return 0;
	if (rem == 0) return 0;

	int &ret = pd[rem][i];
	if (ret != -1) return ret;

	if (w[i] > rem)
		return ret = solve(rem, i + 1);
	return ret = max(solve(rem, i + 1), p[i] + solve(rem - w[i], i + 1));
}

int main() {
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p[i], &w[i]);
		}

		int W;
		scanf("%d", &W);

		memset(pd, -1, sizeof pd);
		printf("%d\n", solve(W, 0));
	}

	return 0;
}