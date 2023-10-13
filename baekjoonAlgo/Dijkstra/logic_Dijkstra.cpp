#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define INF 1e9

using namespace std;

const int MAX = 100001;

// ��� ����, ���� ����
int n, m, start{};

// ��� ������ ���� �迭
vector<pair<int, int>> graph[MAX];

// �ִܰŸ� ���̺�
int dis[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	// ���� ���� ���� ���� �ִ� ��δ� 0���� ����. ť�� ����
	pq.push({ 0, start });
	dis[start] = 0;

	while (!pq.empty()) {
		// ���� �ִ� �Ÿ��� ª�� ��� ������
		int nowCost = -pq.top().first; // ���� �������� ��� (�ּ������� �����Ϸ��� ����(-)�� �־����)
		int nowNode = pq.top().second; // ���� ���
		pq.pop();

		// ���� ��尡 �̹� ó���� �Ÿ� ����
		if (dis[nowNode] < nowCost) continue;

		// ���� ���� ����� �ٸ� ���� ���� Ȯ��
		for (int i = 0; i < graph[nowNode].size(); i++) {
			// ���� ��带 ���ļ� �� ���� ���
			int cost = nowCost + graph[nowNode][i].second;

			// cost�� �� �ִ� �Ÿ���� ������Ʈ
			int nextNode = graph[nowNode][i].first;
			if (cost < dis[nextNode]) {
				dis[nextNode] = cost;
				pq.push(make_pair(-cost, graph[nowNode][i].first)); // (�ּ������� �����Ϸ��� ����(-)�� �־����)
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	// ��� ���� ������ �Է¹ޱ�
	for (int i = 0; i < m; i++) {
		int nowNode, nextNode, cost;
		cin >> nowNode >> nextNode >> cost;
		graph[nowNode].push_back({ nextNode, cost });
	}

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(dis, dis + MAX, INF);

	// ���ͽ�Ʈ��
	dijkstra(start);

	// ��� ���� ���� ���� �ִ� �Ÿ� ���
	for (int i = 1; i <= n; i++) {
		// ���� ���ϸ� INF ���
		if (dis[i] == INF) cout << "INF\n";
		else cout << dis[i];
	}

}