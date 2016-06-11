#include <cstdio>
#include <cstring>

int value[] = {1, 5, 10, 25, 50};
long long pd[30100][5];

long long solve(int rem, int coin) {
	if (coin == 5) return 0;
	if (rem < 0) return 0;
	if (rem == 0) return 1;

	long long &ret = pd[rem][coin];
	if (ret != -1) return ret;

	return ret = solve(rem - value[coin], coin) + solve(rem, coin + 1);
}

int main() {
	int n;
	memset(pd, -1, sizeof pd);

	while (scanf("%d", &n) != EOF) {
		long long ans = solve(n, 0);
		if (ans == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", ans, n);
	}

	return 0;
}