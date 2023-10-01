// 거스름돈

#include <iostream>

using namespace std;

int main() {
	int unit[] = { 500, 100, 50, 10, 5, 1 };
	int money = 1000;
	int cost{};
	cin >> cost;

	int remain = money - cost;

	int res{};
	for (int i = 0; i < sizeof(unit)/sizeof(int); i++) {
		res += remain / unit[i];
		remain %= unit[i];
	}

	cout << res;
}