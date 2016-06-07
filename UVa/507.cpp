#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int S;
		scanf("%d", &S);

		int h, i, j, sum, maxsum;
		h = i = j = sum = maxsum = 0;

		for (int s = 1; s < S; s++) {
			int x;
			scanf("%d", &x);

			sum += x;
			if (sum > maxsum || (sum == maxsum && s - i > j - h)) {
				maxsum = sum;
				h = i;
				j = s;
			}
			if (sum < 0) {
				sum = 0;
				i = s;
			}
		}

		if (maxsum > 0) {
			printf("The nicest part of route %d is between stops %d and %d\n", t + 1, h + 1, j + 1);
		} else {
			printf("Route %d has no nice parts\n", t + 1);
		}
	}

	return 0;
}