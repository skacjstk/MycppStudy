#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int, int>> nodeData[20001];
const int INF = 9999999; //이 문제의 가중치는 10 이하의 자연수

void dijkstra(int start, std::vector<int> &cost) {
	cost[start - 1] = 0; //가중치 0
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(0, start));

	//cost 가 first, node가 second
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
	int startNode;
	//정점 node개(1~20,000) , 간선 edge 개(1~ 300,000)
	scanf("%d %d", &node, &edge);
	scanf("%d", &startNode);
	std::vector<int> cost(node);

	for (int i = 1; i <= edge; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		nodeData[a].push_back(std::make_pair(c, b));
	}
	for (int i = 0; i < node; ++i) {
		cost[i] = INF;
	}

	dijkstra(startNode, cost);


	for (const int &i : cost) {

		if (i == INF)
			printf("INF\n");
		else
			printf("%d\n", i);
	}

	return 0;

}