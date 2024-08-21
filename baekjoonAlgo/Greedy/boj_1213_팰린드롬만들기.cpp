#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

void fail() {
	cout << "I'm Sorry Hansoo\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int strLen = str.length();
	map<char, int> m;

	for (int i = 0; i < strLen; i++) {
		char c = str[i];
		auto it = m.find(c);
		if (it == m.end()) m.insert({ c, 1 });
		else m[c]++;
	}

	int cntOdd{};
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second % 2 == 1) cntOdd++;
	}

	string ans(strLen, ' ');

	if ((strLen % 2 == 1 && cntOdd > 1) || strLen % 2 == 0 && cntOdd > 0)
		fail();
	else {
		int pos{};
		for (auto it = m.begin(); it != m.end(); it++) {
			int cnt = it->second;
			char c = it->first;
			while (cnt > 1) {
				ans[pos] = c;
				ans[strLen - 1 - pos] = c;
				pos++;
				cnt -= 2;
			}
			if (cnt == 1) ans[strLen / 2] = c;
		}
	}

	cout << ans;

	return 0;
}