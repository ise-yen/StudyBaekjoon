// 요세푸스문제

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N{}, K{};
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty()) {
		int f{};
		for (int i = 1; i <= K; i++) {
			f = q.front();
			q.pop();
			if (i != K) q.push(f);
			else cout << f;
		}
		if (!q.empty()) cout << ", ";
	}

	cout << ">";
}