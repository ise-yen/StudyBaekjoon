#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	int N{}, res{};
	cin >> N;

	for (int i = 0; i < N; i++) {
		bool alp[26]{};
		stack<char> stk;
		string str{};
		cin >> str;
		for (int s = 0; s < str.length(); s++) {
			char c = str[s];
			if (stk.empty()) stk.push(c);
			else {
				if (stk.top() != c)
					stk.push(c);
			}
		}

		bool isGroup = true;

		while (!stk.empty()) {
			char c = stk.top();
			if (alp[c - 'a']) {
				isGroup = false;
				break;
			}
			else {
				alp[c - 'a'] = true;
			}
			stk.pop();
		}

		if (isGroup) res++;
	}

	cout << res;
}