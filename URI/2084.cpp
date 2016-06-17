#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	int total = 0;
	int maior = 0;
	int segun = 0;

	while (n--) {
		int x; 
		scanf("%d", &x);
		total += x;
		if (x > maior) {
			segun = maior;
			maior = x;
		} else if (x > segun) {
			segun = x;
		}
	}

	if (maior * 100.0 / total >= 45 || (maior * 100.0 / total >= 40 && maior - segun >= total / 10.0)) {
		printf("1\n");
	} else {
		printf("2\n");
	}

	return 0;
}