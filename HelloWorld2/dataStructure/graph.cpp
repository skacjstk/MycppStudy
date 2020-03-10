/*
�׷���
��ó : https://twpower.github.io/72-implement-graph-in-cpp
*/

#include <iostream>
#include <vector>
#include <queue>

void debug(std::vector <std::vector <int>> &graph, int n) {
	for (int i = 0; i < n; ++i) {
		printf("(%d) ��° �� \n", i);
		for (int j = 0; j < n; ++j) {
			std::cout << graph[j][i]<<" ";
		}	//���� �����
	} 
}
void bfs(int start, std::vector<int> *graph, bool check) {
	std::queue<int> q;

}

int main() {
	int n, m;
	std::cin >> n >> m; // ������ ������ ������ �Է¹���
	//�̺κ� ������.
	std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, -1));
	
		//graph ��� �̸��� ���� n+1 ���� n+1 �� �ʱⰪ -1 2���� ���� ����
	debug(graph, n+1);	//���� ���� �־������� 
	for (int i = 0; i < m; i++) {
		int u, v;
		printf("�������� ���� �� ���� �Է�(%d/%d):", i, m);
		scanf_s("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
		// �ܹ����� ��� graph[u].push_back(v);�� �ۼ�
		// ����ġ�� �ִ� ��� vector<pair<int,int>> graph[n+1];�� ����ų� ����ü�� ���� ����ġ�� �Բ� ����
		// graph[u].push_back(make_pair(v,w)); u->v ����ġ : w
	}
}

/*
int main(void) {
	int n, m;
	std::cin >> n >> m; // ������ ������ ������ �Է¹���

	//�̺κ� ������: ���� �����Ϸ��� ������ �迭ũ�� �ʱ�ȭ�� �ź���.
	int **graph;

	std::vector<int>a;
	a.resize(n);
	graph = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		graph[i] = new int [n + 1];
	}	//�޸� �����Ҵ�

	// �������� �����߱� ������ ������ ���� -1�� �ʱ�ȭ
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			graph[i][j] = -1;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf_s("%d %d", &u, &v);
		graph[u][v] = graph[v][u] = 1;
		// �ܹ����� ��� graph[u][v] = 1;
		// ����ġ�� �ִ� ��� �ܹ����� ��� graph[u][v] = ����ġ��;
	}

	//��º� �̿ϼ�
	
	
	for (int i = 0; i < n + 1; ++i) {
		delete [] graph[i];
	}	
	delete [] graph;
	//�޸� �����Ҵ� ����
	return 0;
}
*/