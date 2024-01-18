#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int i, int j) {
	return i > j;
}

int main() {
	int T{};
	cin >> T;

	while (T > 0) {
		int N{}, answer{};
		cin >> N;

		answer = N;
		vector<pair<int, int>> v;

		for (int i = 0; i < N; i++) {
			int a{}, b{};
			cin >> a >> b;
			v.push_back({ a, -b });
		}

		sort(v.begin(), v.end());

		int best = v[0].second;
		for (int i = 1; i < N; i++) {
			if (v[i].second < best) {
				answer--;
			}
			else {
				best = v[i].second;
			}
		}
		cout << answer << "\n";
		T--;
	}
}



/*

5
3 2
1 1
4 4
2 3
5 5

-1 -1
-2 -3
-3 -2
-4 -4
-5 -5


-1 -4
-2 -3
-3 -2
-4 -1
-5 -5
*/