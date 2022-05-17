#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//0번 노드를 사용하지 않음
vector<bool> cycle; //기본적으로 false
vector<vector<int>> vertex; //각 역 간 연결관계 
vector<bool> visited; //각 정점의 방문 여부 
queue<pair<int, int>> q; // BFS용 큐

bool CheckVisited(const int& node) {
	if (!visited[node]) //방문한적이 없으면
		return true;
	return false;
}
//시작 노드, 현재 DFS에서 추출한 노드, 깊이(0에서 시작)
bool DFS(int start, int vertexNode, int depth)
{
	if (depth >= 2 && start == vertexNode) {
		cycle[start] = true; // 이 정점은 순환선에 포함한다.
		return true;
	}
	visited[vertexNode] = true;

	for (int nextVertex : vertex[vertexNode]) {
		if (CheckVisited(nextVertex)) {
			DFS(start, nextVertex, depth + 1);
		}
		//검색해서 찾은 부분
		else if (nextVertex == start && depth >= 2) {
			DFS(start, nextVertex, depth); //순환 조건에 맞으니 방문 무시하고 호출
		}
	}
	visited[vertexNode] = false;
	return cycle[start]; //이게 맞던가?
}

int BFS(const int& k) {
	fill(visited.begin(), visited.end(), false); //매 bfs마다 모든 방문을 초기화해야 함.
	queue<pair<int,int>> empty;
	swap(q, empty);
	q.push({ k,0 });
	while (!q.empty()) {
		int num = q.front().first;
		int time = q.front().second;
		q.pop();
		visited[num] = true;
		if (cycle[num]) //지금 위치한 곳이 순환노드일 경우, 최소 순환거리가 완성됨.
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

//양방향 연결
void ConnectVertex(const int& host, const int& guest) {
	vertex[host].push_back(guest);
	vertex[guest].push_back(host);
}

int main(void)
{
	int n; //역의 개수
	int a, b; //단순 노드 받기용
	cin >> n;
	cycle.resize(n + 1, false);
	vertex.resize(n + 1);
	visited.resize(n + 1, false);

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		ConnectVertex(a, b);
	}

	//모든 노드에 대해 DFS를 실행
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