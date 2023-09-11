// 숫자카드

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N{}, M{};
	unordered_map<int, int> ump;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n{};
		cin >> n;
		if (ump.find(n) == ump.end()) {
			ump.insert({ n, 1 });
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int m{};
		cin >> m;
		if (ump.count(m)) {
			cout << ump[m] << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
}