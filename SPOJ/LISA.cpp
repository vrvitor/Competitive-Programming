#include <cstdio>
#include <cstring>

char input[110];
int k, pdmax[110][110], pdmin[110][110];

int solvemax(int l, int r) {
	if (l == r)	return input[l] - '0';

	int &ret = pdmax[l][r];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = l + 1; i < r; i += 2) {
		int aux;
		if (input[i] == '+')
			aux = solvemax(l, i - 1) + solvemax(i + 1, r);
		else
			aux = solvemax(l, i - 1) * solvemax(i + 1, r);
		if (aux > ret)
			ret = aux;
	}

	return ret;
}

int solvemin(int l, int r) {
	if (l == r) return input[l] - '0';

	int &ret = pdmin[l][r];
	if (ret != -1) return ret;

	ret = 2000000000;
	for (int i = l + 1; i < r; i += 2) {
		int aux;
		if (input[i] == '+')
			aux = solvemin(l, i - 1) + solvemin(i + 1, r);
		else
			aux = solvemin(l, i - 1) * solvemin(i + 1, r);
		if (aux < ret)
			ret = aux;
	}

	return ret;
}

int main() {
	scanf("%d", &k);
	getchar();

	while (k--) {
		char c;
		int count = 0;
		while ((c = getchar()) != '\n') {
			input[count++] = c;
		}
		memset(pdmax, -1, sizeof pdmax);
		memset(pdmin, -1, sizeof pdmin);
		printf("%d %d\n", solvemax(0, count - 1), solvemin(0, count - 1));
	}

	return 0;
}