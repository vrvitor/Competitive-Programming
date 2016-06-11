#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		long long a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		double ans = (d - b) * 100.0 / (c - a);
		printf("%lld,%02lld\n", (long long) ans/100, (long long) ans % 100);
	}

	return 0;
}