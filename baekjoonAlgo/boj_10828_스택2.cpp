// Ω∫≈√
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N{};
	cin >> N;

	stack<int> s;

	for (int i = 0; i < N; i++) {
		string str{};
		cin >> str;

		if (str == "push") {
			int num{};
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			if (s.empty()) cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (str == "size") {
			cout << s.size() << endl;
		}
		else if (str == "empty") {
			cout << s.empty() << endl;
		}
		else if (str == "top") {
			if (s.empty()) cout << -1 << endl;
			else cout << s.top() << endl;
		}
		else{}
	}

}