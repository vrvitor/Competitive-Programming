#include <cstdio>
#include <cstring>

int pd[7500][5];
int value[] = {1, 5, 10, 25, 50};

int solve(int money, int coin) {
	if (money < 0) return 0;
	if (coin == 5) return 0;
	if (money == 0) return 1;

	int &ans = pd[money][coin];
	if (ans != -1) return ans;

	return ans = solve(money, coin + 1) + solve(money - value[coin], coin);
}

int main() {
	int n;
	memset(pd, -1, sizeof pd);

	while (scanf("%d", &n) != EOF) {
		printf("%d\n", solve(n, 0));
	}

	return 0;
}