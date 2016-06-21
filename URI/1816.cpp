#include <cstdio>

int main() {
	int n;
	int inst = 1;

	while (scanf("%d", &n), n) {
		char alf[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

		printf("Instancia %d\n", inst++);
		while (n--) {
			int x;
			scanf("%d", &x);
			char c = alf[x - 1];
			printf("%c", c);
			for (int i = x - 1; i > 0; i--) {
				alf[i] = alf[i - 1];
			}
			alf[0] = c;
		}
		printf("\n\n");
	}

	return 0;
}