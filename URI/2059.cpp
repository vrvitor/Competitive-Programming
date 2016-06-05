#include <cstdio>

int main() {
	int p, j1, j2, r, a, g;
	scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a);
	if (r) {
		if (a) g = 2; 
		else g = 1;
	} else {
		if (a) g = 1;
		else if ((j1 + j2) % 2 == p) g = 2;
		else g = 1;
	}
	printf("Jogador %d ganha!\n", g);
	return 0;
}