#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// N�� �ִ� 100,000�̹Ƿ� ���� ������ �ð��ʰ�
int main() {
	int N{};
	cin >> N;
	vector<pair<int, pair<int, string>>> v; // ����, <����, �̸�>
	for (int i = 0; i < N; i++) {
		int age{};
		string name;
		cin >> age >> name;
		v.push_back({ age, {i, name} });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second.second << "\n";
	}
	return 0;
}