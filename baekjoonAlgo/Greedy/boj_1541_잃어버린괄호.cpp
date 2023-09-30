// 잃어비린 괄호
#include <iostream>
#include <string>
#include <queue>

using namespace std;

/*
마이너스를 기준으로 앞쪽이 작게, 뒤쪽이 크게
마이너스가 처음 나오기 전까지는 전부 더하기
마이너스가 나온 뒤의 숫자들은 전부 뺴기
*/
int main() {
	int res{};
	
	string str{};
	cin >> str;

	queue<int> q;

	int bi{};

	bool isMinus = false;
	
	for (int i = 0; i < str.length(); i++) {
		// 연산자라면
		if (str[i] == '+' || str[i] == '-') {
			// 지금 연산자 나오기 이전의 숫자
			string tmp{};
			for (int b = bi; b < i; b++) {
				tmp.push_back(str[b]);
			}
			int beforeNum = stoi(tmp);
			if (!isMinus) {
				res += beforeNum;
				if (str[i] == '-') isMinus = true;
			}
			else {
				res -= beforeNum;
			}
	
			bi = i+1;
		}
	}

	string tmp{};
	for (int b = bi; b < str.length(); b++) {
		tmp.push_back(str[b]);
	}
	int beforeNum = stoi(tmp);
	
	if (!isMinus) res += beforeNum;
	else res -= beforeNum;

	cout << res;
}