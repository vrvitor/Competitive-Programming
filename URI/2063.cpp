#include <cstdio>

int n, i, aux, res, count;
int v[110];
bool vis[110];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

void dfs(int i) {
	if (vis[i]) {
		if (count != 0) {
			res = lcm(res, count);
			count = 0;
		}
	} else {
		vis[i] = true;
		count++;
		dfs(v[i]);
	}
}

int main() {
	res = 1;
	count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &aux);
		v[i] = aux - 1;
		vis[i] = false;
	}

	for (i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	printf("%d\n", res);

	return 0;
}