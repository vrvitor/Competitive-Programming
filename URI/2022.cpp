#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<double, int> di;
typedef pair<string, di> sdi;

bool compare(sdi a, sdi b) {
	if (a.second.second > b.second.second) return true;
	if (a.second.second < b.second.second) return false;
	if (a.second.first < b.second.first) return true;
	if (a.second.first > b.second.first) return false;
	return (a.first < b.first);
}

int main() {
	string name;
	int n;

	while (cin >> name >> n) {
		vector<sdi> list(n);

		for (int i = 0; i < n; i++) {
			getline(cin, list[i].first);
			getline(cin, list[i].first);
			cin >> list[i].second.first >> list[i].second.second;
		}

		sort(list.begin(), list.end(), compare);

		cout << "Lista de " << name << endl;
		for (int i = 0; i < n; i++) {
			cout << list[i].first << " - R$" << fixed << setprecision(2) << list[i].second.first << endl;
		}
		cout << endl;
	}

	return 0;
}