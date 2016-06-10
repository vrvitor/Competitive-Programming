#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int ans = 0; 
	bool vis[100000];
	queue<int> q;

	q.push(n);
	q.push(-2000000000);
	memset(vis, false, sizeof vis);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == -2000000000) {
			q.push(-2000000000);
			ans++;
			continue;
		}

		if (x == m) {
			printf("%d\n", ans);
			break;
		}

		if (x >= 0 && x < 100000 && vis[x])
			continue;

		if (x >= 0 && x < 100000)
			vis[x] = true;
		q.push(x * 2);
		q.push(x * 3);
		q.push(x / 2);
		q.push(x / 3);
		q.push(x + 7);
		q.push(x - 7);
	}

	return 0;
}