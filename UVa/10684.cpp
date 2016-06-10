#include <cstdio>

int main() {
	int n;

	while (scanf("%d", &n), n) {
		int ans = 0, sum = 0;
		while (n--) {
			int x;
			scanf("%d", &x);
			sum += x;
			if (sum > ans)
				ans = sum;
			if (sum < 0)
				sum = 0;
		}

		if (ans > 0)
			printf("The maximum winning streak is %d.\n", ans);
		else
			printf("Losing streak.\n");
	}	

	return 0;
}