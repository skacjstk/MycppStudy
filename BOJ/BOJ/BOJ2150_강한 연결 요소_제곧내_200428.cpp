#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

std::vector<int> arr[MAX];	//원소가 담기는 곳
std::vector<int> discoverd;	//방문검사
bool finished[MAX];//bfs 순환이 끝났는가

std::vector<std::vector<int>> SCC;	//scc 벡터가 담기는 벡터
std::stack<int> s;
int dfs(int x) {
	static int id = 0;
	discoverd[x] = ++id;
	//	printf("%d\n", discoverd[x]);
	s.push(x);

	int parent = discoverd[x];

	for (int adjNode : arr[x]) {//인접 노드
//		printf("%d를 parent 로 하여금 %d 탐색:\n", parent, adjNode);
		if (discoverd[adjNode] == 0)	//방문 검사 (0은 방문 한적 없음)
			parent = std::min(parent, dfs(adjNode));
		else if (!finished[adjNode])
			parent = std::min(parent, discoverd[adjNode]);
	}

	if (parent == discoverd[x]) {
		std::vector<int> sccBuffer;
		while (true) {
			int s_top = s.top();
			s.pop();
			finished[s_top] = true;
			sccBuffer.push_back(s_top);
			if (s_top == x)
				break;
		}
		std::sort(sccBuffer.begin(), sccBuffer.end());
		SCC.push_back(sccBuffer);
	}
	return parent;
}
int main()
{
	int node, edge;
	scanf("%d %d", &node, &edge);
	discoverd.resize(node + 1, 0);
	for (int i = 0; i < edge; ++i) {
		int a, b;
		//a->b
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
	}

	for (int j = 1; j <= node; ++j) {
		if (discoverd[j] == 0)
			dfs(j);
	}
	printf("%lu\n", SCC.size());


	std::sort(SCC.begin(), SCC.end());

	for (unsigned int i = 0; i < SCC.size(); i++) {
		for (unsigned int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}

/*
7 9
1 4
4 5
5 1
1 6
6 7
2 7
7 3
3 7
7 2
*/