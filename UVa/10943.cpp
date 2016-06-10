#include <cstdio>

int main() {
	int pd[110][110];
	for (int i = 1; i <= 100; i++) {
		pd[1][i] = 1;
		pd[i][0] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			pd[i][j] = (pd[i][j - 1] + pd[i - 1][j]) % 1000000;
		}
	}

	int a, b;
	while (scanf("%d %d", &a, &b), a || b) {
		printf("%d\n", pd[b][a]);
	}

	return 0;
}