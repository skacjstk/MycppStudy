#include <iostream>
#include <vector>
#include <algorithm>

#define NEED 4

using namespace std;

vector<bool> visited;
bool findAnswer = false;

bool CheckVisited(const int node){
	if (!visited[node]) //방문한적이 없으면
		return true;
	return false;

}

void dfs(vector<vector<int>>& p, int rootNode, int depth) {
	visited[rootNode] = true;

//	cout << "현재 depth: " << depth << "\t 현재 rootNode: " << rootNode<<"\n";
	if (depth == NEED)
	{
		findAnswer = true;
		return;
	}
	if (p[rootNode].empty() || findAnswer) return;

	for (int nextVertex : p[rootNode]) {
		if (findAnswer) return;
		if (CheckVisited(nextVertex)) //미방문시 true 반환
		{
//			cout << "현재 rootNode: " << rootNode << "\t다음: " << nextVertex << "\n";
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

	//DFS로 연관관계가 0~4까지 나오면 answer ++
	return 0;
}
/*
	코드는 완벽했으나 depth 시작을 0으로 했어야 하는데 1로 시작해버려서 12 23 34 같이 ABCD 만 있어도 1로 return 해버렸음
	depth 시작을 0으로 바꾸고 나서 60ms로 성공
*/