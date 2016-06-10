#include <iostream>
#include <string>

using namespace std;

int main() {
	// max is 999999
	int input;

	while (cin >> input) {
		// abc.def
		int a = (input/100000) % 10;
		int b = (input/10000) % 10;
		int c = (input/1000) % 10;
		int d = (input/100) % 10;
		int e = (input/10) % 10;
		int f = input % 10;
		bool skipc = false, skipf = false;

		switch (a) {
			case 0: break;
			case 1: cout << ((b || c) ? "cento" : "cem"); break;
			case 2: cout << "duzentos"; break;
			case 3: cout << "trezentos"; break;
			case 4: cout << "quatrocentos"; break;
			case 5: cout << "quinhentos"; break;
			case 6: cout << "seiscentos"; break;
			case 7: cout << "setecentos"; break;
			case 8: cout << "oitocentos"; break;
			case 9: cout << "novecentos"; break;
		}

		if (a && (b || c))
			cout << " e ";

		switch (b) {
			case 0: break;
			case 1: skipc = true;
				switch (c) {
					case 0: cout << "dez"; break;
					case 1: cout << "onze"; break;
					case 2: cout << "doze"; break;
					case 3: cout << "treze"; break;
					case 4: cout << "quatorze"; break;
					case 5: cout << "quinze"; break;
					case 6: cout << "dezesseis"; break;
					case 7: cout << "dezessete"; break;
					case 8: cout << "dezoito"; break;
					case 9: cout << "dezenove"; break;
				} break;
			case 2: cout << "vinte"; break;
			case 3: cout << "trinta"; break;
			case 4: cout << "quarenta"; break;
			case 5: cout << "cinquenta"; break;
			case 6: cout << "sessenta"; break;
			case 7: cout << "setenta"; break;
			case 8: cout << "oitenta"; break;
			case 9: cout << "noventa"; break;
		}

		if (b && c && !skipc)
			cout << " e ";

		if (!skipc) {
			switch (c) {
				case 0: break;
				case 1: if (a || b) cout << "um"; break;
				case 2: cout << "dois"; break;
				case 3: cout << "tres"; break;
				case 4: cout << "quatro"; break;
				case 5: cout << "cinco"; break;
				case 6: cout << "seis"; break;
				case 7: cout << "sete"; break;
				case 8: cout << "oito"; break;
				case 9: cout << "nove"; break;
			}
		}

		if (a || b || c) {
			if (a || b || c != 1)
				cout << " ";
			cout << "mil";
			if (d || e || f)
				cout << " ";
			if ((d && !e && !f) || (!d && (e || f)))
				cout << "e ";
		}

		switch (d) {
			case 0: break;
			case 1: cout << ((e || f) ? "cento" : "cem"); break;
			case 2: cout << "duzentos"; break;
			case 3: cout << "trezentos"; break;
			case 4: cout << "quatrocentos"; break;
			case 5: cout << "quinhentos"; break;
			case 6: cout << "seiscentos"; break;
			case 7: cout << "setecentos"; break;
			case 8: cout << "oitocentos"; break;
			case 9: cout << "novecentos"; break;
		}

		if (d && (e || f))
			cout << " e ";

		switch (e) {
			case 0: break;
			case 1: skipf = true;
				switch (f) {
					case 0: cout << "dez"; break;
					case 1: cout << "onze"; break;
					case 2: cout << "doze"; break;
					case 3: cout << "treze"; break;
					case 4: cout << "quatorze"; break;
					case 5: cout << "quinze"; break;
					case 6: cout << "dezesseis"; break;
					case 7: cout << "dezessete"; break;
					case 8: cout << "dezoito"; break;
					case 9: cout << "dezenove"; break;
				} break;
			case 2: cout << "vinte"; break;
			case 3: cout << "trinta"; break;
			case 4: cout << "quarenta"; break;
			case 5: cout << "cinquenta"; break;
			case 6: cout << "sessenta"; break;
			case 7: cout << "setenta"; break;
			case 8: cout << "oitenta"; break;
			case 9: cout << "noventa"; break;
		}

		if (e && f && !skipf)
			cout << " e ";

		if (!skipf) {
			switch (f) {
				case 0: if (!(a || b || c || d || e)) cout << "zero"; break;
				case 1: cout << "um"; break;
				case 2: cout << "dois"; break;
				case 3: cout << "tres"; break;
				case 4: cout << "quatro"; break;
				case 5: cout << "cinco"; break;
				case 6: cout << "seis"; break;
				case 7: cout << "sete"; break;
				case 8: cout << "oito"; break;
				case 9: cout << "nove"; break;
			}
		}

		cout << endl;
	}

	return 0;
}