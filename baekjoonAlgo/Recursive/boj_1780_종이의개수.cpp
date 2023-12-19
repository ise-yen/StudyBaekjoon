#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int arr[3]{};
void Cut(int r, int c, int N) {
	bool isAllSame = true;
	int tmp = map[r][c];
	for (int i = r; i < r+N; i++) {
		for (int j = c; j < c+N; j++) {
			if (map[i][j] != tmp) {
				isAllSame = false;
				break;
			}
		}
		if (!isAllSame) break;
	}

	if (!isAllSame) {
		for (int i = r; i < r + N; i += N/3) {
			for (int j = c; j < c + N; j += N/3) {
				Cut(i, j, N / 3);
			}
		}
	}
	else {
		++arr[tmp + 1];
	}
}
/*
N = 9
0, 0 (0,0)

N = 3
0,0 / 0,3 / 0,6
3,0 / 3,3 / 3,6
6,0 / 6,3 / 6,6

N = 1 (0,0)
0,0 / 0,1 / 0,2
1,0 / 1,1 / 1,2
2,0 / 2,1 / 2,2

N = 1 (0,3)
0,3 / 0,4 / 0,5
1,3 / 1,4 / 1,5
2,3 / 2,4 / 2,5

*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N{};
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			int tmp{};
			cin >> tmp;
			v.push_back(tmp);
		}
		map.push_back(v);
	}

	Cut(0, 0, N);
	
	for (int i = 0; i < 3; i++)
		cout << arr[i] << "\n";

	return 0;
}