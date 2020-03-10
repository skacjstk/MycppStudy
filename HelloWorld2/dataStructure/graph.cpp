/*
그래프
출처 : https://twpower.github.io/72-implement-graph-in-cpp
*/

#include <iostream>
#include <vector>
#include <queue>

void debug(std::vector <std::vector <int>> &graph, int n) {
	for (int i = 0; i < n; ++i) {
		printf("(%d) 번째 줄 \n", i);
		for (int j = 0; j < n; ++j) {
			std::cout << graph[j][i]<<" ";
		}	//벡터 디버그
	} 
}
void bfs(int start, std::vector<int> *graph, bool check) {
	std::queue<int> q;

}

int main() {
	int n, m;
	std::cin >> n >> m; // 정점과 간선의 개수를 입력받음
	//이부분 수정함.
	std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, -1));
	
		//graph 라는 이름의 가로 n+1 세로 n+1 의 초기값 -1 2차원 벡터 선언
	debug(graph, n+1);	//벡터 재대로 넣어졌는지 
	for (int i = 0; i < m; i++) {
		int u, v;
		printf("간선으로 이을 두 정점 입력(%d/%d):", i, m);
		scanf_s("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
		// 단방향의 경우 graph[u].push_back(v);만 작성
		// 가중치가 있는 경우 vector<pair<int,int>> graph[n+1];로 만들거나 구조체를 만들어서 가중치와 함께 저장
		// graph[u].push_back(make_pair(v,w)); u->v 가중치 : w
	}
}

/*
int main(void) {
	int n, m;
	std::cin >> n >> m; // 정점과 간선의 개수를 입력받음

	//이부분 수정함: 현재 컴파일러는 변수로 배열크기 초기화를 거부함.
	int **graph;

	std::vector<int>a;
	a.resize(n);
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
*/