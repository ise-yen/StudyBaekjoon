#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> tmp;
int N{}, k{};

void divide(int x, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		divide(x * 2, left, mid);
		divide(x * 2, mid + 1, right);

		if (x < k) return;

		int pl = left, pr = mid + 1, pt = left;
		while (pl <= mid && pr <= right) {
			if (v[pl] < v[pr]) tmp[pt++] = v[pl++];
			else tmp[pt++] = v[pr++];
		}

		while (pl <= mid) tmp[pt++] = v[pl++];
		while (pr <= right) tmp[pt++] = v[pr++];

		for (int i = left; i <= right; i++) {
			v[i] = tmp[i];
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	tmp.resize(N);
	for (int i = 0; i < N; i++) {
		int t{};
		cin >> t;
		v.push_back(t);
	}
	cin >> k;

	divide(1, 0, N - 1);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}