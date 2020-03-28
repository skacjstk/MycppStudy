#include <iostream>
#include <vector>
#include <queue>

// 출처: https://www.techiedelight.com/graph-implementation-using-stl/

// data structure to store graph edges
struct Edge {
	int src, dest;
};	//like pair

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	//adjacency 뜻: 인접
	std::vector<std::vector<int>> adjList;

	// Graph Constructor
	Graph(std::vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the directed graph
		for (auto &edge : edges)
		{
			// insert at the end
			adjList[edge.src].push_back(edge.dest);

			// Uncomment below line for undirected graph
			// 무향 그래프면 바로 아랫줄 주석을 지워 쌍방향으로 이을 것
			// adjList[edge.dest].push_back(edge.src);
		}
	}
};
void DFS(Graph const& graph, int v, std::vector<bool>& discoverd) {
//	if (discoverd[v]) return;	//이미 방문한 적 있으면 return 
	discoverd[v] = true;
	std::cout << v << " ";
	for (int i : graph.adjList[v]) {
		if (!discoverd[i]) //방문한 적이 없다면(사실 큐에 넣은적 없다면)
			DFS(graph, i, discoverd);		
	}
	return;
}

//2020.03.13. 수정됨
void BFS(Graph const& graph, int v, std::vector<bool>& discoverd) {
	std::queue<int> q;	//큐 생성	
	discoverd[v] = true;	//현재 탐색 지점 탐색함.
	q.push(v);		//큐에 시작지점v 넣기
	while (!q.empty())	//비어있지 않다(탐색할 정점이 남아있다)
	{
		v = q.front();
		q.pop();
		std::cout << v << " ";
		for (int i : graph.adjList[v]) {
			if (!discoverd[i]) {//방문한 적이 없다면(사실 큐에 넣은적 없다면)
				discoverd[i] = true;
				q.push(i);
			}
		}
	}
}
// print adjacency list representation of graph
void printGraph(Graph const& graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		// print current vertex number
		std::cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : graph.adjList[i])
			std::cout << v << " ";
		std::cout << std::endl;
	}
}

// Graph Implementation using STL
int main()
{
	// vector of graph edges as per above diagram.
	// Please note that initialization vector in below format will
	// work fine in C++11, C++14, C++17 but will fail in C++98.
	std::vector<Edge> edges =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }, {3, 4},
		{2 ,3}
	};

	// Number of nodes in the graph 숫자범위 0~5 까지 6개 
	int N = 6;

	// construct graph
	Graph graph(edges, N);
	std::vector<bool> discoverd(N, false);

//	BFS(graph, 0, discoverd);	//0번 과 이어진 그래프 탐색
//	std::cout << "\n";
//	for (int i = 0; i < N; ++i) {
//		BFS(graph, i, discoverd);	//i번 과 이어진 그래프 탐색
//	}	//싱글노드가 있다고 가정, 숫자가 노드의 숫자가 0~i까지 정수 단위로 이어져 있어야 함.

	// 만약 BFS DFS 연속재생 하고싶으면 false 로 바꿀것


	DFS(graph, 0, discoverd);	//0번 과 이어진 그래프 탐색
	std::cout << "\n";
	// print adjacency list representation of graph
	printGraph(graph, N);	//무향 그래프일 경우 쌍

	return 0;
}