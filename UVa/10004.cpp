#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi color;
int n, l;

bool dfs(int u, int c) {
	color[u] = c;
	c = 1 - c;
	for (int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if (color[v] == color[u]) return false;
		if (color[v] == -1 && !dfs(v, c)) return false;
	}
	return true;
}

int main() {
	while (scanf("%d", &n), n) {
		AdjList.assign(n, vi());
		color.assign(n, -1);
		scanf("%d", &l);
		while (l--) {
			int a, b;
			scanf("%d %d", &a, &b);
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		if (dfs(0, 0)) {
			printf("BICOLORABLE.\n");
		} else {
			printf("NOT BICOLORABLE.\n");
		}
	}

	return 0;
}