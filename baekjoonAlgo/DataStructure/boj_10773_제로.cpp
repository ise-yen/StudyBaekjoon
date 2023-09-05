//Á¦·Î

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int usingStack(int K) {
	stack<int> s;
	int sum{};
	for (int i = 0; i < K; i++) {
		int n{};
		cin >> n;
		if (n == 0 && !s.empty())
			s.pop();
		else
			s.push(n);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	return sum;
}

int usingVector(int K) {
	vector<int> v;
	int sum{};
	for (int i = 0; i < K; i++) {
		int n{};
		cin >> n;

		if (n == 0 && !v.empty())
			v.pop_back();
		else v.push_back(n);
	}

	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	return sum;
}

int main() {
	int K{};
	cin >> K;

	cout << usingVector(K);
}