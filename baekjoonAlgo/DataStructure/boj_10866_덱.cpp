// µ¦
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	int N{};
	cin >> N;

	deque<int> dq;
	string str{};
	for (int i = 0; i < N; i++) {
		cin >> str;

		int num{};
		if (str == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop_front") {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if (str == "size") {
			printf("%d\n", dq.size());
		}
		else if (str == "empty") {
			if (dq.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (str == "front") {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.front());
			}
		}
		else if (str == "back") {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.back());
			}
		}
	}
}