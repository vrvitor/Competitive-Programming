#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, m;
	cin >> n >> m;

	priority_queue< ii, vector<ii>, greater<ii> > pq;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		pq.push(ii(0, i));
		cin >> v[i];
	}

	int ans = 0;

	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;

		int t = pq.top().first;
		int id = pq.top().second;

		if (t + c * v[id] > ans)
			ans = t + c * v[id];

		pq.pop();
		pq.push(ii(t + c * v[id], id));
	}

	cout << ans << endl;

	return 0;
}