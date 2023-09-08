// 숨바꼭질

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool isFind = false;

const int MAX = 100001;
bool pos[MAX]{};
int check[MAX]{};

int nextPos(int i, int N) {
	if (i == 0) return N + 1;
	if (i == 1) return N - 1;
	if (i == 2) return N*2;
}

void BFS(int N, int K) {
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		for (int i = 0; i <= 20; i++) {
			cout << check[i] << " ";
		}

		cout << endl;

		N = q.front();
		pos[N] = true;
		q.pop();
		if (N == K) {
			cout << check[N];
			return;
		}

		for (int i = 0; i < 3; i++) {
			int nextN = nextPos(i, N);
			if (nextN < 0 || nextN >= MAX || pos[nextN]) continue;

			if (nextN == K) {
				cout << check[N] + 1;
				return;
			}
			q.push(nextN);
			if(check[nextN]==0)
				check[nextN] = check[N] + 1;
			else {
				check[nextN] = check[nextN] < check[N] + 1 ? check[nextN] : check[N] + 1;
			}
		}
	}
}

int main() {
	int N{}, K{};
	cin >> N >> K;

	BFS(N, K);
}