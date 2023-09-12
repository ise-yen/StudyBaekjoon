// 요세푸스문제0

#include <iostream>
#include <queue>

using namespace std;
int main() {
	int N{}, K{};
	queue<int> q;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int cnt{};
	cout << "<";
	while (q.size() > 1) {
		cnt++;

		int f = q.front();
		q.pop();
		if (cnt % K != 0) {
			q.push(f);
		}
		else {
			cout << f << ", ";
		}
	}
	cout << q.front() << ">";
}