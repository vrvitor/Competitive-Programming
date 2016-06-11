#include <cstdio>

int main() {
	int m, n, p;

	while (scanf("%d %d %d", &m, &n, &p), m || n || p) {
		int ans = p;
		while (p--) {
			int x;
			scanf("%d", &x);
			if (x % n)
				ans += n - x % n;
		}
		printf("Lights: %d\n", ans);
	}

	return 0;
}