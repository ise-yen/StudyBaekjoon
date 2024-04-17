#include <iostream>
#include <map>
#include <string>

using namespace std;

bool check_num(string str) {
	try {
		stoi(str);
	}
	catch (const invalid_argument& e) {
		return false;
	}
	catch (const out_of_range& e) {
		return false;
	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N{}, M{}; // 도감에 수록된 포켓몬 개수, 맞춰야하는 문제 개수
	cin >> N >> M;
	map<int, string> m1;
	map<string, int> m2;
	// 도감
	for (int i = 1; i <= N; i++) {
		string name;
		cin >> name;
		m1[i] = name;
		m2[name] = i;
	}

	// 맞춰야하는 문제
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		int num{};
		if(check_num(str)) cout << m1[stoi(str)] << "\n";
		else cout << m2[str] << "\n";
	}
	return 0;
}