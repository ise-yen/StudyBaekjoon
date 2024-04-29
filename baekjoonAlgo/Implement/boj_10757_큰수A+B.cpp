#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	string A{}, B{};
	cin >> A >> B;

	int ap = A.length() - 1;
	int bp = B.length() - 1;

	deque<char> dq;
	int upSum{};
	while (ap >= 0 && bp >= 0) {
		int sum = (A[ap] - '0') + (B[bp] - '0') + upSum;
		
		if (sum >= 10) {
			upSum = sum / 10;
			sum %= 10;
		}
		else upSum = 0;
		dq.push_front('0' + sum);
		ap--;
		bp--;
	}

	while (ap >= 0) {
		int sum{};
		if (upSum > 0) {
			sum = (A[ap] - '0') + upSum;
			if (sum >= 10) {
				upSum = sum / 10;
				sum %= 10;
			}
			else upSum = 0;
			dq.push_front('0' + sum);
		}
		else {
			dq.push_front(A[ap]);
		}
		ap--;
	}

	while (bp >= 0) {
		int sum{};
		if (upSum > 0) {
			sum = (B[bp] - '0') + upSum;
			if (sum >= 10) {
				upSum = sum / 10;
				sum %= 10;
			}
			else upSum = 0;
			dq.push_front('0' + sum);
		}
		else {
			dq.push_front(B[bp]);
		}
		bp--;
	}

	if (upSum > 0) dq.push_front('0' + upSum);
	upSum = 0;

	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}
	return 0;
}