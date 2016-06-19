#include <cstdio>
#include <cstring>

int r(char *x) {
	int res = 0;
	// puts(x);
	char *y = x;
	while (*y != 0) y++;
	y--;

	while (y != x) {
		res *= 10;
		res += *y - '0';
		// printf("%d\n", res);
		y--;
	}
	res *= 10;
	res += *y - '0';
	// printf("%d\n", res);
	return res;
}

int main() {
	char a[10], b[10], c[10], *d;
	int ra, rb, rc;

	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);

	while (1) {
		d = a;
		while ((*d = getchar()) != '+') d++;
		*d = 0;
		d = b;
		while ((*d = getchar()) != '=') d++;
		*d = 0;
		d = c;
		while ((*d = getchar()) != '\n') d++;
		*d = 0;
		ra = r(a), rb = r(b), rc = r(c);
		// printf("%d+%d=%d\n", ra, rb, rc);
		if (ra + rb == rc) printf("True\n");
		else printf("False\n");
		if (!(ra || rb || rc)) return 0;
	}
}