#include <cstdio>

int main() {
	int w1, w2, r;
	int ct = 0;
	double total = 0.0;

	while (scanf("%d %d %d", &w1, &w2, &r), w1 || w2 || r) {
		double M = ((w1 + w2) * (30 + r))/60.0;
		if (M >= 1 && M < 13) {
			printf("Nao vai da nao\n");
		} else if (M >= 13 && M < 14) {
			printf("E 13\n");
		} else if (M >= 14 && M < 40) {
			printf("Bora, hora do show! BIIR!\n");
		} else if (M >= 40 && M < 60) {
			printf("Ta saindo da jaula o monstro!\n");
		} else {
			printf("AQUI E BODYBUILDER!!\n");
		}

		ct++;
		total += M;
	}

	if (total/ct > 40)
		printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");

	return 0;
}