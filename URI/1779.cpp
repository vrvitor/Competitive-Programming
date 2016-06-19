#include <cstdio>


int main() {
	int t;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		int n;
		scanf("%d", &n);

		int x, ant, maior;
		int count, max;

		scanf("%d", &x);
		maior = x;
		count = max = 1;

		while (--n) {
			ant = x;
			scanf("%d", &x);
			if (x > maior) {
				maior = x;
				count = max = 1;
			} else if (x == maior) {
				if (x == ant) {
					count++;
					if (count > max) max = count;
				}
				else count = 1;
			}
		}

		printf("Caso #%d: %d\n", c, max);
	}

	return 0;
}