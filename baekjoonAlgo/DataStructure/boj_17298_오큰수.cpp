#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	// �� �Է�
	int N{};
	cin >> N;
	// �ڿ������� ����ֱ�
	stack<int> s;
	for (int i = 0; i < N; i++) {
		int n{};
		cin >> n;
		s.push(n);
	}

	stack<int> ans; // �����
	ans.push(-1); // �������� ������ -1

	stack<int> tmp; // ũ�� �񱳿�
	tmp.push(s.top());
	s.pop();
	while (!s.empty()) {
		bool isFind = false;
		// ��ū�� ã��
		while (!tmp.empty()) {
			if (s.top() < tmp.top()) {
				ans.push(tmp.top());
				isFind = true;
				break;
			}
			else tmp.pop();
		} 
		// �� ã���� == tmp�� empty�� ����
		if (!isFind) ans.push(-1);
		tmp.push(s.top());
		s.pop();
	}

	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	return 0;
}