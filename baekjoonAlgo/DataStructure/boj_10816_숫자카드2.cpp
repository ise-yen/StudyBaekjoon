// 숫자카드2

#include <iostream>
#include <unordered_map>
// map보다 insert, erase, find에서 O(1)O(1)로 빠르다고 함.

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N{}, M{};
	unordered_map<int, int> ump;
	
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		int keyN{};
		cin >> keyN;

		// key가 있으면 value 증가
		if (ump.find(keyN) != ump.end()) {
			++ump[keyN];
		}
		// key가 없으면 요소 추가
		else {
			ump.insert({ keyN, 1 });
		}
	}


	cin >> M;
	for (int i = 0; i < M; i++) {
		int m{};
		cin >> m;
		// key가 있으면 value 출력
		if (ump.count(m)) {
			cout << ump[m] << " ";
		}
		// key가 없으면 0 출력
		else {
			cout << 0 << " ";
		}
	}
}