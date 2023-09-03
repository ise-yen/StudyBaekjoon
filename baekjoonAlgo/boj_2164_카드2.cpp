// Ä«µå
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		int f = q.front();
		q.push(f);
		q.pop();
	}

	cout << q.front();
}