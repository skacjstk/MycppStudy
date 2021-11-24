#include <iostream>
#include <vector>
#include <algorithm>

#define NEED 4

using namespace std;

vector<bool> visited;
bool findAnswer = false;

bool CheckVisited(const int node){
	if (!visited[node]) //�湮������ ������
		return true;
	return false;

}

void dfs(vector<vector<int>>& p, int rootNode, int depth) {
	visited[rootNode] = true;

//	cout << "���� depth: " << depth << "\t ���� rootNode: " << rootNode<<"\n";
	if (depth == NEED)
	{
		findAnswer = true;
		return;
	}
	if (p[rootNode].empty() || findAnswer) return;

	for (int nextVertex : p[rootNode]) {
		if (findAnswer) return;
		if (CheckVisited(nextVertex)) //�̹湮�� true ��ȯ
		{
//			cout << "���� rootNode: " << rootNode << "\t����: " << nextVertex << "\n";
			dfs(p, nextVertex, depth+1);
		}
	}
	visited[rootNode] = false;
}

void ConnectVertex(vector<vector<int>>& p, const int& host, const int& guest) {
	p[host].push_back(guest);
	p[guest].push_back(host);
}

bool CheckSolution(vector<vector<int>>& p, const int& n) {
	bool flag = false;
	
	for (int i = 0; i < n; ++i) {
		dfs(p, i, 0);
		if (findAnswer) {
			break;
		}
	}

	flag = findAnswer;	
	return flag;
}

int main(void)
{
	int n, m, answer = 0;
	int host, guest ,rootNode;
	cin >> n >> m;
	vector<vector<int>> person(n);
	visited.resize(n, false);

	for (int i = 0; i < m; ++i) {
		cin >> host >> guest;
		rootNode = min(host, guest);
		ConnectVertex(person, host, guest);
	}

	answer = CheckSolution(person, n) ? 1 : 0;
	cout << answer;

	//DFS�� �������谡 0~4���� ������ answer ++
	return 0;
}
/*
	�ڵ�� �Ϻ������� depth ������ 0���� �߾�� �ϴµ� 1�� �����ع����� 12 23 34 ���� ABCD �� �־ 1�� return �ع�����
	depth ������ 0���� �ٲٰ� ���� 60ms�� ����
*/