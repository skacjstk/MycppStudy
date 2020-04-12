#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int, int>> nodeData[1001];
const int INF = 100000001; //�� ������ ����ġ�� 100,000, ���� 1000���ϱ� ������ �� �ִ��� ���� 1��, �׺��� ũ���� 1��+1

void dijkstra(int start, std::vector<int> &cost) {
	cost[start - 1] = 0; //����ġ 0
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(0, start));

	//cost �� first, node�� second
	while (!pq.empty()) {
		int nowCost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (cost[node - 1] < nowCost) continue;
		for (std::pair<int, int> &next : nodeData[node]) {
			int nextNode = next.second;
			int nextCost = nowCost + next.first;
			if (nextCost < cost[nextNode - 1]) {
				cost[nextNode - 1] = nextCost;
				pq.push(std::make_pair(-nextCost, nextNode));
			}
		}
	}//endwhile
}

int main() {
	int node, edge;
	int startNode, endNode;
	//���� node��(1~20,000) , ���� edge ��(1~ 300,000)
	scanf("%d", &node);
	scanf("%d", &edge);
	std::vector<int> cost(node);

	for (int i = 1; i <= edge; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		nodeData[a].push_back(std::make_pair(c, b));
	}
	for (int i = 0; i < node; ++i) {
		cost[i] = INF;
	}

	scanf("%d %d", &startNode, &endNode);
	dijkstra(startNode, cost);


	printf("%d", cost[endNode - 1]);

	return 0;

}