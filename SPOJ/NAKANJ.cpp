#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

int di[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dj[] = {1, 2, 2, 1, -1, -2, -2, -1};
vector<ii> AdjList[8][8];
int dij[8][8];

void addEdge(int i, int j, int x, int y) {
	if (x < 0 || x >= 8 || y < 0 || y >= 8) return;
	AdjList[i][j].push_back(ii(x, y));
}

void dijkstra(int x, int y) {
	queue<ii> q;
	q.push(ii(x, y));
	dij[x][y] = 0;

	while (!q.empty()) {
		ii u = q.front();
		q.pop();

		int i = u.first, j = u.second;
		for (int k = 0; k < AdjList[i][j].size(); k++) {
			ii v = AdjList[i][j][k];
			if (dij[v.first][v.second] == -1 || dij[v.first][v.second] > dij[i][j] + 1) {
				dij[v.first][v.second] = dij[i][j] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				addEdge(i, j, i + di[k], j + dj[k]);
			}
		}
	}

	while (t--) {
		char s[3];
		char d[3];
		scanf("%s %s", s, d);
		memset(dij, -1, sizeof dij);
		dijkstra(s[0] - 'a', s[1] - '1');
		printf("%d\n", dij[d[0] - 'a'][d[1] - '1']);
	}

	return 0;
}