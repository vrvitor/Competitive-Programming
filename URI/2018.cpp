#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<int, string> is;
typedef pair<ii, is> iiis;

bool compare(iiis a, iiis b) {
	if (a.first.first > b.first.first) return true;
	if (a.first.first < b.first.first) return false;
	if (a.first.second > b.first.second) return true;
	if (a.first.second < b.first.second) return false;
	if (a.second.first > b.second.first) return true;
	if (a.second.first < b.second.first) return false;
	return a.second.second < b.second.second;
}

int main() {
	map<string, iii> placar;
	string input;

	while (getline(cin, input)) {
		getline(cin, input);
		placar[input].first.first++;
		getline(cin, input);
		placar[input].first.second++;
		getline(cin, input);
		placar[input].second++;
	}

	vector<iiis> v;
	map<string, iii>::iterator it;
	for (it = placar.begin(); it != placar.end(); it++) {
		v.push_back(iiis(it->second.first, is(it->second.second, it->first)));
	}

	sort(v.begin(), v.end(), compare);

	cout << "Quadro de Medalhas" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second.second << " ";
		cout << v[i].first.first << " ";
		cout << v[i].first.second << " ";
		cout << v[i].second.first << endl;
	}

	return 0;
}