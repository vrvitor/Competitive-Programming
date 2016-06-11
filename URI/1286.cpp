#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, t[30], p[30], pd[30][40];

int solve(int id, int rem) {
	if (id == n) return 0;
	if (rem == 0) return 0;

	int &ret = pd[id][rem];
	if (ret != -1) return ret;

	if (p[id] > rem)
		return ret = solve(id + 1, rem);
	return ret = max(solve(id + 1, rem), t[id] + solve(id + 1, rem - p[id]));
}

int main() {
	while (scanf("%d", &n), n) {
		int P;
		scanf("%d", &P);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &t[i], &p[i]);
		}

		memset(pd, -1, sizeof pd);
		printf("%d min.\n", solve(0, P));
	}

	return 0;
}