#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string str{};
	cin >> str;

	stack<char> s;

	int answer{};
	for (int i = 0; i < str.length(); i++) {
		if (s.empty() || str[i] == '(') s.push(str[i]);
		else {
			if (str[i] == ')' && (s.top() == '(')) {
				if (i > 0 && str[i - 1] == '(') { // 레이저 쏨
					s.pop();
					answer += s.size();
				}
				else { // 막대 길이 끝
					s.pop();
					answer++;
				}
			}
		}
	}

	cout << answer;
	return 0;
}