#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	int ans = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x) ans--;
		else ans++;
	}

	if (ans > 0) printf("Y\n");
	else printf("N\n");

	return 0;
}