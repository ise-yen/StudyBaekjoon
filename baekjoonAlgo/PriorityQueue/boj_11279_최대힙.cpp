#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N{};
	cin >> N;

	priority_queue<int> pq;
	for (int n = 0; n < N; n++) {
		int x{};
		cin >> x;

		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << " ";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}

	}
}