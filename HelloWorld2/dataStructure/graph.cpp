/*
�׷���
��ó : https://twpower.github.io/72-implement-graph-in-cpp
*/

#include <iostream>

int main(void) {
	int n, m;
	std::cin >> n >> m; // ������ ������ ������ �Է¹���

	//�̺κ� ������: ���� �����Ϸ��� ������ �迭ũ�� �ʱ�ȭ�� �ź���.
	int **graph;

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