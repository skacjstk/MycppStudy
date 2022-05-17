#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//0�� ��带 ������� ����
vector<bool> cycle; //�⺻������ false
vector<vector<int>> vertex; //�� �� �� ������� 
vector<bool> visited; //�� ������ �湮 ���� 
queue<pair<int, int>> q; // BFS�� ť

bool CheckVisited(const int& node) {
	if (!visited[node]) //�湮������ ������
		return true;
	return false;
}
//���� ���, ���� DFS���� ������ ���, ����(0���� ����)
bool DFS(int start, int vertexNode, int depth)
{
	if (depth >= 2 && start == vertexNode) {
		cycle[start] = true; // �� ������ ��ȯ���� �����Ѵ�.
		return true;
	}
	visited[vertexNode] = true;

	for (int nextVertex : vertex[vertexNode]) {
		if (CheckVisited(nextVertex)) {
			DFS(start, nextVertex, depth + 1);
		}
		//�˻��ؼ� ã�� �κ�
		else if (nextVertex == start && depth >= 2) {
			DFS(start, nextVertex, depth); //��ȯ ���ǿ� ������ �湮 �����ϰ� ȣ��
		}
	}
	visited[vertexNode] = false;
	return cycle[start]; //�̰� �´���?
}

int BFS(const int& k) {
	fill(visited.begin(), visited.end(), false); //�� bfs���� ��� �湮�� �ʱ�ȭ�ؾ� ��.
	queue<pair<int,int>> empty;
	swap(q, empty);
	q.push({ k,0 });
	while (!q.empty()) {
		int num = q.front().first;
		int time = q.front().second;
		q.pop();
		visited[num] = true;
		if (cycle[num]) //���� ��ġ�� ���� ��ȯ����� ���, �ּ� ��ȯ�Ÿ��� �ϼ���.
		{
			return time;
		}

		for (int it : vertex[num]) {
			if (CheckVisited(it)) {
				visited[num] = true;
				q.push({ it, time + 1 });
			}
		}

	}//end while
}

//����� ����
void ConnectVertex(const int& host, const int& guest) {
	vertex[host].push_back(guest);
	vertex[guest].push_back(host);
}

int main(void)
{
	int n; //���� ����
	int a, b; //�ܼ� ��� �ޱ��
	cin >> n;
	cycle.resize(n + 1, false);
	vertex.resize(n + 1);
	visited.resize(n + 1, false);

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		ConnectVertex(a, b);
	}

	//��� ��忡 ���� DFS�� ����
	for (int i = 1; i <= n; ++i) {
		DFS(i, i, 0);
	}
	for (int i = 1; i <= n; ++i) {
		if (cycle[i]){
			cout << "0 ";
		}
		else {
			cout << BFS(i) << " ";
		}
	}

	return 0;
}