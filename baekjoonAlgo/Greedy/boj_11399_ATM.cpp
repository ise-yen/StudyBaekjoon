// ATM

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N{}, min{};
	vector<int> v;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int p{};
		cin >> p;
		v.push_back(p);
	}
	
	sort(v.begin(), v.end());


	int pSum = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += v[j];
		}
		pSum += sum;
	}

	cout << pSum;
}