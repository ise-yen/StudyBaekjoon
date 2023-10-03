// 한수
#include<iostream>
#include<string>

using namespace std;

int main() {
	int N{};
	cin >> N; // <= 1000 (최대 네 자리 수)

	int res{};

	// 한 자리, 두 자리수는 모두 한수
	if (N < 100) {
		res += N;
	}
	else {
		res += 99; // 1~99
		for (int i = 100; i <= N; i++) {
			string str = to_string(i);
			if ((str[0] - str[1]) == (str[1] - str[2])) res++;
		}
	}

	cout << res;
}



