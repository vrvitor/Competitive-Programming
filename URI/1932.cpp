#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, pd[200100][2], v[200100];

int solve(int i, bool a) {
	if (i == n) return 0;

	int &ret = pd[i][a ? 1 : 0];
	if (ret != -1) return ret;

	if (a)
		return ret = max(solve(i + 1, true), solve(i + 1, false) + v[i]);
	return ret = max(solve(i + 1, false), solve(i + 1, true) - v[i] - k);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	memset(pd, -1, sizeof pd);
	printf("%d\n", solve(0, false));
	return 0;
}