#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N{}, K{}, A{}, B{};

	cin >> N >> K >> A >> B;
	vector<int> v;

	for (int i = 0; i < N; i++) v.push_back(K);

	int answer{};
	bool isDie = false;
	while (!isDie) {
		answer++;
		sort(v.begin(), v.end());
		isDie = false;
		for (int i = 0, k = 0; i < v.size(); i++, k++) {
			if(k < A) v[i] += B;
			v[i]--;
			if (v[i] == 0) {
				isDie = true;
				break;
			}
		}
	}

	cout << answer;
}