#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vector<bool> visited;

void dfs(int u) {
	visited[u] = true;

	for (int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if (!visited[v]) dfs(v);
	}
}

int main() {
	int n;

	while (scanf("%d", &n), n) {AdjList.assign(1010, vi());
		visited.assign(1010, false);

		while (n--) {
			int x, y;
			getchar(); getchar();
			scanf("%d", &x);
			getchar();
			scanf("%d", &y);
			getchar();

			AdjList[x].push_back(y);
			AdjList[y].push_back(x);
		}

		dfs(1);
		int ans = 0;
		for (int i = 0; i < 1010; i++) {
			if (visited[i]) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}