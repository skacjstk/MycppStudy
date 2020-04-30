#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

std::vector<std::vector<int>> arr;	//원소가 담기는 곳
std::vector<int> indegree;
std::vector<int> discoverd;	//방문검사

std::vector<int> SCC;
std::stack<int> s;

int id = 0;
int another = 0; //같은 SCC임을 묶는 좌표
int dfs(int x) {
	discoverd[x] = ++id;
	s.push(x);
	int parent = discoverd[x];

	for (int adjNode : arr[x]) {//인접 노드
		if (!discoverd[adjNode])	//방문 검사 (0은 방문 한적 없음)
			parent = std::min(parent, dfs(adjNode));
		else if (!SCC[adjNode])
			parent = std::min(parent, discoverd[adjNode]);
	}

	if (parent == discoverd[x]) {
		++another;
		while (true) {
			int s_top = s.top();
			s.pop();
			SCC[s_top] = another;
			if (s_top == x)
				break;
		}
	}
	return parent;
}
void testCase() {
	another = id = 0;
	int node, edge;	//정점과 간선
	SCC.clear();
	indegree.clear();
	discoverd.clear();
	arr.clear();

	scanf("%d %d", &node, &edge);
	arr.resize(node + 1, std::vector<int>());
	discoverd.resize(node + 1, 0);
	indegree.resize(node + 1, 0);
	SCC.resize(node + 1, 0);
	//	printf("SCC 값:%d\n\n", SCC[1]);

		//관계 설정, a->b
	for (int i = 0; i < edge; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
	}
	//방문한 적이 없으면 그 노드 dfs

	for (int j = 1; j <= node; ++j) {
		if (!discoverd[j])
			dfs(j);
	}


	//indegree 구하기
	for (int i = 1; i <= node; ++i) {
		//		printf("node의 크기:%d, 현재 i의 값:%d\n", node, i);
		for (int next : arr[i])
		{
			//			printf(" arr[%d]의 값:%d\n",i,next);

			if (SCC[i] != SCC[next]) {
	//			printf("\nSCC[%d] 값:%d\n", next, SCC[next]);
				++indegree.at(SCC[next]);		// --> 두번째 testCase 부터 vector subscript out of range 발생				
			}
			//			printf("%d-> %d ->", SCC[i], SCC[next]);
			//			printf("%d\n", indegree[SCC[next]]);
		}
	}

	int answer = 0;
	//? 여기가 node 가 아니라 another 인 이유 ?

	printf("another 의 크기와 node의 크기:%d/%d\n", another, node);
	for (int i = 1; i <= another; ++i) {
		if (!indegree[i])
			++answer;
	}
	//여기까지 한번의 테스트 끝남
	printf("%d\n", answer);
}
int main()
{
	int testCaseNum;
	scanf("%d", &testCaseNum);

	//입력한 정수만큼 도미노 테스트
	while (testCaseNum > 0) {
		testCase();
		--testCaseNum;
	}
	return 0;
}

/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

std::vector<std::vector<int>> arr;	//원소가 담기는 곳
std::vector<int> indegree;
std::vector<int> discoverd;	//방문검사

std::vector<int> SCC;
std::stack<int> s;

int id = 0;
int dfs(int x) {
	discoverd[x] = ++id;
	s.push(x);
	int parent = discoverd[x];

	for (int adjNode : arr[x]) {//인접 노드
		if (discoverd[adjNode] == 0)	//방문 검사 (0은 방문 한적 없음)
			parent = std::min(parent, dfs(adjNode));
		else if (!SCC[adjNode])
			parent = std::min(parent, discoverd[adjNode]);
	}

	int another = 0; //같은 SCC임을 묶는 좌표
	if (parent == discoverd[x]) {
		++another;
		while (true) {
			int s_top = s.top();
			s.pop();
			SCC[s_top] = another;
			if (s_top == x)
				break;
		}
	}
	return parent;
}
void testCase() {

	int node, edge;	//정점과 간선
	SCC.clear();
	indegree.clear();
	discoverd.clear();
	arr.clear();

	scanf("%d %d", &node, &edge);
	arr.resize(node + 1, std::vector<int>(0));
	discoverd.resize(node + 1, 0);
	indegree.resize(node + 1, 0);
	SCC.resize(node + 1, 0);
//	printf("SCC 값:%d\n\n", SCC[1]);

	//관계 설정, a->b
	for (int i = 0; i < edge; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
	}
	//방문한 적이 없으면 그 노드 dfs

	for (int j = 1; j <= node; ++j) {
		if (!discoverd[j])
			dfs(j);
	}

	
	//indegree 구하기
	for (int i = 1; i <= node; ++i) {
//		printf("node의 크기:%d, 현재 i의 값:%d\n", node, i);
		for (int next : arr[i])
		{
//			printf(" arr[%d]의 값:%d\n",i,next);

			if (SCC[i] != SCC[next]) {
				printf("\nSCC[%d] 값:%d\n", next, SCC[next]);
				++indegree.at(SCC[next]);		// --> 두번째 testCase 부터 vector subscript out of range 발생				
			}
//			printf("%d-> %d ->", SCC[i], SCC[next]);
//			printf("%d\n", indegree[SCC[next]]);
		}
	}

	int answer = 0;
	for (int i = 1; i <= node; ++i) {
		if (!indegree[i])
			++answer;
	}
	//여기까지 한번의 테스트 끝남
	printf("%d\n", answer);
	
}
int main()
{
	int testCaseNum;
	scanf("%d", &testCaseNum);

	//입력한 정수만큼 도미노 테스트
	while (testCaseNum > 0) {
		testCase();
		--testCaseNum;
	}
	return 0;
}

*/