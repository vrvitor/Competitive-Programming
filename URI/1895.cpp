#include <cstdio>
#include <cstdlib>

int main() {
	int n, t, l;
	scanf("%d %d %d", &n, &t, &l);

	int a = 0, b = 0;
	bool c = true;

	while (--n) {
		int s; 
		scanf("%d", &s);

		int r = abs(t - s);
		if (r <= l) {
			t = s;
			if (c) a += abs(r);
			else b += abs(r);
		}

		c = !c;
	}

	printf("%d %d\n", a, b);

	return 0;
}