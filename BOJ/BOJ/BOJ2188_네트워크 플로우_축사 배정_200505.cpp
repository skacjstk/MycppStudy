#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

std::vector<std::vector<int>> node;	//���Ұ� ���� ��
std::vector<bool> visited;	//�湮�˻�
std::vector<int> b; //parent 

int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = true;

	for (int there : node[here]) {
		if (!b[there] || dfs(b[there])){
			b[there] = here;
			return 1;
		}
	}	
	return 0;

}

int bmatch(const int cow) {
	int ret = 0;

	for (int i = 1; i <= cow; ++i) {
		visited.clear();
		visited.resize(cow+1,false);
		if (dfs(i)) ret++;
	}

	return ret;
}

void testCase() {
	int cow, cage;
	scanf("%d %d", &cow, &cage);

	node.resize(cow + 1, std::vector<int>());
	b.resize(cow + 1, 0);

	int wantNum;
	for (int n = 1; n <= cow; ++n) {
		scanf("%d", &wantNum);
		for (int i = 0; i < wantNum; ++i) {
			int cageNum;
			scanf("%d", &cageNum);
			node[n].push_back(cageNum);
		}
	}
	//������ �Է� �Ϸ�
	printf("%d", bmatch(cow));
}

int main(void)
{
	testCase();
	return 0;

}