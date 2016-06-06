#include <cstdio>
#include <cstring>

int pd[210][25], price[25][25];
int budget, n;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int solve(int moneyLeft, int garment) {
	if (moneyLeft < 0) return -1000000000;
	if (garment == n) return budget - moneyLeft;

	int &ans = pd[moneyLeft][garment];

	if (ans != -1) return ans;

	for (int i = 1; i <= price[garment][0]; i++) {
		ans = max(ans, solve(moneyLeft - price[garment][i], garment + 1));	
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		memset(pd, -1, sizeof pd);
		scanf("%d %d", &budget, &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &price[i][0]);

			for (int j = 1; j <= price[i][0]; j++) {
				scanf("%d", &price[i][j]);
			}
		}

		int ans = solve(budget, 0);
		if (ans > 0) printf("%d\n", ans);
		else 		 printf("no solution\n");
	}

	return 0;
}