#include <cstdio>

int main() {
	int s, t, f, res;
	scanf("%d %d %d", &s, &t, &f);
	res = (s + t + f) % 24;
	if (res < 0) res += 24;
	printf("%d\n", res);
	return 0;
}