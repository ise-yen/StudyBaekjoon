#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define INF 1e9

using namespace std;

const int MAX = 20001;

vector<pair<int, int>> graph[MAX];

int dis[MAX]{};
int V{}, E{}, K{}; // ����, ����, ���� ��� ��ȣ

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq; // 1. ���, 2. ���� ��� ��ȣ
	// ����� ������ ���� : ����� �������� �켱����ť �ȿ��� ���ĵǰ� �ϱ� ����

	pq.push({ 0, start});
	dis[start] = 0;

	while (!pq.empty()) {
		// ��뿡 ���̳ʽ��� ���̴� ���� : C++�� �켱���� ť=�ִ���
		/* ex) ���
		�⺻: 10, 9, 8, 7 : ��밪�� Ŭ���� 1��
		����: -7, -8, -9, -10  : ����� �������� 1��(�ּ���ó�� ���̰� ��)
		*/
		int nowCost = -pq.top().first; // ��������� ���
		int nowNode = pq.top().second; // ���� ��� ��ȣ
		pq.pop();

		// �̹� �湮�� ���� �н�
		if (dis[nowNode] < nowCost) continue;

		// ���� ��忡�� �� �� �ִ� ����
		for (int i = 0; i < graph[nowNode].size(); i++) {
			int cost = nowCost + graph[nowNode][i].second;

			// cost�� �� �ִ� �Ÿ���� ������Ʈ
			int nextNode = graph[nowNode][i].first;
			if (cost < dis[nextNode]) {
				dis[nextNode] = cost;
				pq.push(make_pair(-cost, nextNode));
			}
		}
	}
}

int main() {
	cin >> V >> E;

	cin >> K;

	for (int i = 0; i < E; i++) {
		int u{}, v{}, w{}; // ���� ���, ���� ���, ���
		cin >> u >> v >> w;
	
		graph[u].push_back({ v, w }); // (���) u ��� �� (����) v ��� : (���=w)
	}

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(dis, dis + MAX, INF);

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF) cout << "INF\n";
		else cout << dis[i] << "\n";
	}

}