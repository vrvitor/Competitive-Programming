#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

bool compare(ii a, ii b) {
	if (a.first > b.first) return true;
	if (a.first < b.first) return false;
	if (a.second < b.second) return true;
	return false;
}

int main() {
	int n, m;

	while (scanf("%d %d", &n, &m), n || m) {
		map<int, int> M;

		for (int i = 0; i < n * m; i++) {
			int x;
			scanf("%d", &x);
			M[x]++;
		}

		vector<ii> V;
		for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
			V.push_back(ii(it->second, it->first));
		}

		sort(V.begin(), V.end(), compare);

		cout << V[1].second << " ";
		for (int i = 2; i < V.size() && V[i].first == V[1].first; i++) {
			cout << V[i].second << " ";
		}
		cout << endl;
	}

	return 0;
}