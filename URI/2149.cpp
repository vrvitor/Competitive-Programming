#include <cstdio>

int main() {
	long long unsigned v[] = {0, 1, 1, 1, 2, 2, 4, 8, 12, 96, 108, 10368, 10476, 108615168, 108625644, 11798392572168192, 11798392680793836};

	int x;
	while (scanf("%d", &x) != EOF) {
		printf("%llu\n", v[x - 1]);
	}

	return 0;
}