#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> rest = { 25, 10, 5, 1 };
	int T{};
	cin >> T;
	for (int t = 0; t < T; t++) {
		int C{};
		cin >> C;
		int q{}, d{}, n{}, p{};
		for (int i = 0; i < rest.size(); i++) {
			cout << C / rest[i] << " ";
			C %= rest[i];
		}
		cout << "\n";
	}
	return 0;
}