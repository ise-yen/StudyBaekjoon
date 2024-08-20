#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

vector<string> substring(string str) {
	istringstream ss(str);
	string tmp;
	vector<string> v;
	while (getline(ss, tmp, '.')) {
		v.push_back(tmp);
	}
	return v;
}

void printAB(int vlen) {
	if (vlen % 4 == 2) {
		while (vlen > 2) {
			cout << "AAAA";
			vlen -= 4;
		}
		cout << "BB";
	}
	else if (vlen % 4 == 0) {
		while (vlen > 0) {
			cout << "AAAA";
			vlen -= 4;
		}
	}
	else if (vlen % 2 == 0) {
		while (vlen > 0) {
			cout << "BB";
			vlen -= 2;
		}
	}
}

int main() {
	string str{};
	cin >> str;
	vector<string> v = substring(str);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].length() % 2 == 0) continue;
		else {
			cout << "-1";
			return 0;
		}
	}

	int vi{}, cnt{};
	for (int i = 0; i < str.length(); i++) {\
		if (str[i] == '.') {
			if (cnt > 0) {
				int vlen = v[vi].length();
				printAB(vlen);
			}
			cout << ".";
			vi++;
		}
		else cnt++;
	}

	if (cnt > 0) {
		int vlen = v[vi].length();
		printAB(vlen);
	}
	return 0;
}