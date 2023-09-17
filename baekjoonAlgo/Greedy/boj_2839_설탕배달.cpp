// 설탕배달

#include <iostream>

using namespace std;

int main() {
	int N{};
	cin >> N;

	int min = 5000;

	if (N % 5 == 0) min = N / 5;
	else {
		for (int f = N / 5; f >= 0; f--) {
			int n = N;
			int sum = f;
			n -= f * 5;
			if (n % 3 == 0) {
				sum += n / 3;
				min = min < sum ? min : sum;
			}
			else continue;
		}
	}

	if (min == 5000 ) cout << -1;
	else cout << min;
}