// 동전 0

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{}, K{};
	cin >> N >> K;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int cnt{};
	for (int i = N - 1; i >= 0; i--) {
		if (v[i] > K) continue;

		cnt += K / v[i];
		K %= v[i];
		if (K == 0) break;
	}

	cout << cnt;
}