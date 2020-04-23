#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

std::vector<int> build[1000001];

int	topoLogicalSort(std::vector<int> &cost, std::vector<int> &indegree, const int& endNode) {

	std::queue<std::pair<int, int>> q;
	std::vector<int> copyCost(cost);
	//어차피 1에서 시작하기때문에 반복문 필요없기는 함.
	for (int i = 0; i < indegree.size(); ++i) {
		if (indegree[i] == 0)
			q.push(std::make_pair(copyCost[i], i + 1));
	}

	while (!q.empty()) {
		int nowCost = q.front().first;
		int nowNode = q.front().second;
		//		printf("node:%d cost:%d\n",nowNode, nowCost);
		q.pop();
		if (nowNode == endNode) continue;
		for (int edgeBuf : build[nowNode]) {
			--indegree[edgeBuf - 1];
			int newCost = std::max(nowCost + cost[edgeBuf - 1], copyCost[edgeBuf - 1]);
			//		printf(" newNode:%d newCost: %d\n",edgeBuf, newCost);
			copyCost[edgeBuf - 1] = newCost;
			if (indegree[edgeBuf - 1] == 0) {
				q.push(std::make_pair(newCost, edgeBuf));
			}
		}
	}
	return copyCost[endNode - 1];
}

void testCase(const int testCount) {
	int vertex, edge;
	for (int i = 0; i < testCount; ++i) {
		scanf("%d %d", &vertex, &edge);

		std::vector<int> cost(vertex, 0); //vertex+1 하면 foreach 문 못씀 
		std::vector<int> indegree(vertex, 0);

		//노드 수만큼 노드의 가중치 입력 
//		printf("사이즈:%d\n",cost.size());
		for (int &stuff : cost) {
			scanf("%d", &stuff);
		}
		//연결관계 입력
		for (int j = 0; j < edge; ++j) {
			int a, b;
			scanf("%d %d", &a, &b);
			++indegree[b - 1];
			build[a].push_back(b);
		}
		int endNode;
		scanf("%d", &endNode);

		printf("%d\n", topoLogicalSort(cost, indegree, endNode));

		for (int list = 1; list <= vertex; ++list) {
			build[list].clear();
		}
	}
}

int main() {

	int testCount;
	scanf("%d", &testCount);
	testCase(testCount); //testCount 횟수만큼 반복

//	printf("hi");
	return 0;

}