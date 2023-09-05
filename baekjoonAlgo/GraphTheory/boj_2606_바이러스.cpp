// 바이러스

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;
int com[MAX][MAX]{};
bool isVisit[MAX]{};
int cnt{};

void DFS_2606(int c, int N) {
	if (cnt == N) return;

	isVisit[c] = true;

	for (int i = 1; i <= N; i++) {
		if (isVisit[i] || com[c][i] == 0) continue;
		cnt++;
		DFS_2606(i, N);
	}

}

void BFS_2606(int c, int N) {
	queue<int> q;
	q.push(c);
	isVisit[c] = true;

	while (!q.empty()) {
		c = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (isVisit[i] || com[c][i] == 0) continue;
			isVisit[i] = true;
			cnt++;
			q.push(i);
		}
	}
}

int main() {
	int N{}, M{}; // 컴퓨터 수, 직접 연결된 컴퓨터 쌍의 수
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int com1{}, com2{};
		cin >> com1 >> com2;

		com[com1][com2] = 1;
		com[com2][com1] = 1;
	}

	BFS_2606(1, N);
	cout << cnt;
}