#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi visited;

void dfs(int v, int i) {
	if (v == i) return;
	visited[v] = 1;
	for (int j = 0; j < AdjList[v].size(); j++) {
		if (!visited[AdjList[v][j]]) dfs(AdjList[v][j], i);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++) {
		int n;
		scanf("%d", &n);

		AdjList.assign(n, vi());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				if (x) AdjList[i].push_back(j);
			}
		}

		visited.assign(n, 0);
		dfs(0, -1);
		vi reach = visited;

		printf("Case %d:\n", tc);
		for (int i = 0; i < 2 * n + 1; i++) {
			if (i == 0 || i == 2 * n) printf("+");
			else printf("-");
		}
		printf("\n");

		for (int i = 0; i < n; i++) {
			visited.assign(n, 0);
			dfs(0, i);
			printf("|");
			for (int j = 0; j < n; j++) {
				if (reach[j] && !visited[j]) printf("Y|");
				else printf("N|");
			}
			printf("\n");
			for (int i = 0; i < 2 * n + 1; i++) {
				if (i == 0 || i == 2 * n) printf("+");
				else printf("-");
			}
			printf("\n");
		}
	}

	return 0;
}