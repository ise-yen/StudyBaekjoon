// ť

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int N{};
	cin >> N;

	string order{};

	queue<int> q;
	for (int i = 0; i < N; i++) {
		cin >> order;
		
		if (order == "push") {
			int num{};
			cin >> num;
			q.push(num);
		}
		else if (order == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (order == "size") {
			cout << q.size() << endl;
		}
		else if (order == "empty") {
			cout << q.empty() << endl;
		}
		else if (order == "front") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else if (order == "back") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
		else {}
	}
}