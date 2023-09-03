// °ýÈ£
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		stack<char> s;
		string vps{};
		cin >> vps;
		s.push(vps[0]);

		for (int i = 1; i < vps.length(); i++) {
			if (s.empty()) {
				s.push(vps[i]);
				continue;
			}

			if (s.top() == '(') {
				if (vps[i] == ')') {
					s.pop();
					continue;
				}
			}
			
			s.push(vps[i]);
		}

		if (s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}