#include <cstdio>

int main() {
	int t;

	while (scanf("%d", &t), t) {
		int x;
		double a, b;
		for (int i = 1; i <= t; i++) {
			scanf("%d %lf %lf", &x, &a, &b);
			printf("Size #%d:\n", i);
			printf("Ice Cream Used: %.2lf cm2\n", (a + b) * x * 2.5);
		}
		printf("\n");
	}

	return 0;
}