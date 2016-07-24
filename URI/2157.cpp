#include <cstdio>

void printInverse(int x) {
	while (x) {
		printf("%d", x % 10);
		x /= 10;
	}
}

int main() {
	int ct; 
	scanf("%d", &ct);

	while (ct--) {
		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = a; i <= b; i++) printf("%d", i);
		for (int i = b; i >= a; i--) printInverse(i);
		printf("\n");
	}

	return 0;
}