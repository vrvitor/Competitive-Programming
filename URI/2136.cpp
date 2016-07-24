#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string nome, yn, win = "";
	set<string> yes, no;

	while (cin >> nome, nome != "FIM") {
		cin >> yn;
		if (yn[0] == 'Y') yes.insert(nome);
		else no.insert(nome);
		if (yn[0] == 'Y' && nome.size() > win.size())
			win = nome;
	}

	for (set<string>::iterator it = yes.begin(); it != yes.end(); it++)
		cout << *it << endl;
	for (set<string>::iterator it = no.begin(); it != no.end(); it++)
		cout << *it << endl;

	cout << endl << "Amigo do Habay:" << endl << win << endl;

	return 0;
}