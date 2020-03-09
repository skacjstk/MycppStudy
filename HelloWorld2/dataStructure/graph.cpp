/*
그래프
출처 : https://twpower.github.io/72-implement-graph-in-cpp
*/

#include <iostream>

int main(void) {
	int n, m;
	std::cin >> n >> m; // 정점과 간선의 개수를 입력받음

	//이부분 수정함: 현재 컴파일러는 변수로 배열크기 초기화를 거부함.
	int **graph;

	graph = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		graph[i] = new int [n + 1];
	}	//메모리 동적할당

	// 정적으로 선언했기 때문에 값들을 전부 -1로 초기화
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			graph[i][j] = -1;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf_s("%d %d", &u, &v);
		graph[u][v] = graph[v][u] = 1;
		// 단방향의 경우 graph[u][v] = 1;
		// 가중치가 있는 경우 단방향의 경우 graph[u][v] = 가중치값;
	}

	//출력부 미완성
	
	for (int i = 0; i < n + 1; ++i) {
		delete [] graph[i];
	}	
	delete [] graph;
	//메모리 동적할당 해제
	return 0;
}