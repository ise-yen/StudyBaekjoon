// 로프

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N{}, w{};
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int rope{};
		cin >> rope;
		v.push_back(rope);
	}
	
	sort(v.begin(), v.end());

	int res = v[N - 1]; // 가장 무거운 로프 1개만 사용할 때의 중량
	
	// k개
	for (int k = 2; k <= N; k++) {
		int w = v[N - k] * k;
		res = w > res ? w : res;
	}

	cout << res;
}