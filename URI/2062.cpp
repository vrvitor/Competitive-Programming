#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, i;
	cin >> n;

	for (i = 0; i < n; i++) {
		string s; 
		cin >> s;

		if (i)
			cout << " ";
		if (s.size() == 3 && s[0] == 'O' && s[1] == 'B')		
			cout << "OBI";
		else if (s.size() == 3 && s[0] == 'U' && s[1] == 'R')	
			cout << "URI";
		else													
			cout << s;
	}

	cout << endl;

	return 0;
}