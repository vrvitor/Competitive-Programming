#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int v[1010];
int pd[1010][1010];

int solve(int left, int right) {
	if (left == right) return 1;
	if (left > right) return 0;

	int &ret = pd[left][right];
	if (ret != -1) return ret;

	if (v[left] == v[right])
		return ret = 1 + solve(left + 1, right - 1);
	return ret = 1 + min(solve(left + 1, right), solve(left, right - 1));
}

int main() {
	int t;
	scanf("%d", &t);

	for (int ct = 1; ct <= t; ct++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &v[i]);
		memset(pd, -1, sizeof pd);
		printf("Caso #%d: %d\n", ct, solve(0, n - 1));
	}

	return 0;
}