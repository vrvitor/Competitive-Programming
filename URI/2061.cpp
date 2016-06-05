#include <cstdio>

int main() {
	int n, m;
	char a;

	scanf("%d %d", &n, &m);
	getchar();

	while (m--) {
		scanf("%c%*s", &a);
		getchar();
		if (a == 'f') n++;
		else		  n--; 
	}
	
	printf("%d\n", n);

	return 0;
}