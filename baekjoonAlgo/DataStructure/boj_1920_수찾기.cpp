// 수 찾기
// 이진 탐색 염습
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int>& v, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] == target) return true;
		else if (v[mid] < target) start = mid + 1;
		else end = mid - 1;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0); // c와 c++ 표준 stream 동기화 비활성화

	int N{}, M{};
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n{};
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int target{};
		cin >> target;

		int res = binarySearch(v, target, 0, N - 1);
		printf("%d\n", res);
	}

	return 0;
}