#include <cstdio>

int main() {
	int n, m2, m3, m4, m5;
	m2 = m3 = m4 = m5 = 0;
	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x % 2 == 0) m2++;
		if (x % 3 == 0) m3++;
		if (x % 4 == 0) m4++;
		if (x % 5 == 0) m5++;
	}
	printf("%d Multiplo(s) de 2\n", m2);
	printf("%d Multiplo(s) de 3\n", m3);
	printf("%d Multiplo(s) de 4\n", m4);
	printf("%d Multiplo(s) de 5\n", m5);
	return 0;
}