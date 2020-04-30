#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

std::vector<std::vector<int>> arr;	//���Ұ� ���� ��
std::vector<int> indegree;
std::vector<int> discoverd;	//�湮�˻�

std::vector<int> SCC;
std::stack<int> s;

int id = 0;
int another = 0; //���� SCC���� ���� ��ǥ
int dfs(int x) {
	discoverd[x] = ++id;
	s.push(x);
	int parent = discoverd[x];

	for (int adjNode : arr[x]) {//���� ���
		if (!discoverd[adjNode])	//�湮 �˻� (0�� �湮 ���� ����)
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
	int node, edge;	//������ ����
	SCC.clear();
	indegree.clear();
	discoverd.clear();
	arr.clear();

	scanf("%d %d", &node, &edge);
	arr.resize(node + 1, std::vector<int>());
	discoverd.resize(node + 1, 0);
	indegree.resize(node + 1, 0);
	SCC.resize(node + 1, 0);
	//	printf("SCC ��:%d\n\n", SCC[1]);

		//���� ����, a->b
	for (int i = 0; i < edge; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
	}
	//�湮�� ���� ������ �� ��� dfs

	for (int j = 1; j <= node; ++j) {
		if (!discoverd[j])
			dfs(j);
	}


	//indegree ���ϱ�
	for (int i = 1; i <= node; ++i) {
		//		printf("node�� ũ��:%d, ���� i�� ��:%d\n", node, i);
		for (int next : arr[i])
		{
			//			printf(" arr[%d]�� ��:%d\n",i,next);

			if (SCC[i] != SCC[next]) {
	//			printf("\nSCC[%d] ��:%d\n", next, SCC[next]);
				++indegree.at(SCC[next]);		// --> �ι�° testCase ���� vector subscript out of range �߻�				
			}
			//			printf("%d-> %d ->", SCC[i], SCC[next]);
			//			printf("%d\n", indegree[SCC[next]]);
		}
	}

	int answer = 0;
	//? ���Ⱑ node �� �ƴ϶� another �� ���� ?

	printf("another �� ũ��� node�� ũ��:%d/%d\n", another, node);
	for (int i = 1; i <= another; ++i) {
		if (!indegree[i])
			++answer;
	}
	//������� �ѹ��� �׽�Ʈ ����
	printf("%d\n", answer);
}
int main()
{
	int testCaseNum;
	scanf("%d", &testCaseNum);

	//�Է��� ������ŭ ���̳� �׽�Ʈ
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

std::vector<std::vector<int>> arr;	//���Ұ� ���� ��
std::vector<int> indegree;
std::vector<int> discoverd;	//�湮�˻�

std::vector<int> SCC;
std::stack<int> s;

int id = 0;
int dfs(int x) {
	discoverd[x] = ++id;
	s.push(x);
	int parent = discoverd[x];

	for (int adjNode : arr[x]) {//���� ���
		if (discoverd[adjNode] == 0)	//�湮 �˻� (0�� �湮 ���� ����)
			parent = std::min(parent, dfs(adjNode));
		else if (!SCC[adjNode])
			parent = std::min(parent, discoverd[adjNode]);
	}

	int another = 0; //���� SCC���� ���� ��ǥ
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

	int node, edge;	//������ ����
	SCC.clear();
	indegree.clear();
	discoverd.clear();
	arr.clear();

	scanf("%d %d", &node, &edge);
	arr.resize(node + 1, std::vector<int>(0));
	discoverd.resize(node + 1, 0);
	indegree.resize(node + 1, 0);
	SCC.resize(node + 1, 0);
//	printf("SCC ��:%d\n\n", SCC[1]);

	//���� ����, a->b
	for (int i = 0; i < edge; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
	}
	//�湮�� ���� ������ �� ��� dfs

	for (int j = 1; j <= node; ++j) {
		if (!discoverd[j])
			dfs(j);
	}

	
	//indegree ���ϱ�
	for (int i = 1; i <= node; ++i) {
//		printf("node�� ũ��:%d, ���� i�� ��:%d\n", node, i);
		for (int next : arr[i])
		{
//			printf(" arr[%d]�� ��:%d\n",i,next);

			if (SCC[i] != SCC[next]) {
				printf("\nSCC[%d] ��:%d\n", next, SCC[next]);
				++indegree.at(SCC[next]);		// --> �ι�° testCase ���� vector subscript out of range �߻�				
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
	//������� �ѹ��� �׽�Ʈ ����
	printf("%d\n", answer);
	
}
int main()
{
	int testCaseNum;
	scanf("%d", &testCaseNum);

	//�Է��� ������ŭ ���̳� �׽�Ʈ
	while (testCaseNum > 0) {
		testCase();
		--testCaseNum;
	}
	return 0;
}

*/