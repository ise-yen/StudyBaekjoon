// 단지 번호 붙이기

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 25;
int map[MAX][MAX]{};
bool isVisit[MAX][MAX]{};
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

vector<int> v;

bool isInMap(int r, int c, int N) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	else return true;
}

void BFS(int r, int c, int N) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	isVisit[r][c] = true;
	int cnt = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];

			if (!isInMap(nr, nc, N) || map[nr][nc] == 0 || isVisit[nr][nc]) continue;
			isVisit[nr][nc] = true;
			q.push(make_pair(nr, nc));
			cnt++;
		}
	}

	v.push_back(cnt);
}


int main() {
	// 입력
	int N{};
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string str{};
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisit[i][j]) continue;
			
			if(map[i][j] == 1) BFS(i, j, N);
		}
	}


	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

}