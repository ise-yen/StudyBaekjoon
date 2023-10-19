#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

const int MAX = 1000000;

vector<int> map[MAX + 1]{};
bool isVisit[MAX + 1]{};
int nodes[MAX + 1]{ };

int N{}, cnt{};

void dfs(int node) {
	cnt++;
	isVisit[node] = true;
	if (cnt == N) return;

	for (int i = 0; i < map[node].size(); i++) {
		int nextNode = map[node][i];
		if (isVisit[nextNode]) continue;
		nodes[nextNode] = node;
		dfs(nextNode);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N;
	
	for (int i = 0; i < N-1; i++) {
		int a{}, b{};
		cin >> a >> b;
		
		map[a].push_back(b);
		map[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << nodes[i] << "\n";
	}

}