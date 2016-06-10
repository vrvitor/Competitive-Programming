#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int l, n, c[60], pd[60][60];

int solve(int left, int right) {
	if (right == left + 1)
		return 0;

	int &ret = pd[left][right];
	if (ret != -1) 
		return ret;

	int aux = 2000000000;
	for (int i = left + 1; i < right; i++) {
		aux = min(aux, solve(left, i) + solve(i, right));
	}

	return ret = aux + c[right] - c[left];
}

int main() {
	while (scanf("%d", &l), l) {
		scanf("%d", &n);

		c[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &c[i]);
		c[n + 1] = l;

		memset(pd, -1, sizeof pd);
		printf("The minimum cutting is %d.\n", solve(0, n + 1));
	}

	return 0;
}