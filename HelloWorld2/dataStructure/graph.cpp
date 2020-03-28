#include <iostream>
#include <vector>
#include <queue>

// ��ó: https://www.techiedelight.com/graph-implementation-using-stl/

// data structure to store graph edges
struct Edge {
	int src, dest;
};	//like pair

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	//adjacency ��: ����
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
			// ���� �׷����� �ٷ� �Ʒ��� �ּ��� ���� �ֹ������� ���� ��
			// adjList[edge.dest].push_back(edge.src);
		}
	}
};
void DFS(Graph const& graph, int v, std::vector<bool>& discoverd) {
//	if (discoverd[v]) return;	//�̹� �湮�� �� ������ return 
	discoverd[v] = true;
	std::cout << v << " ";
	for (int i : graph.adjList[v]) {
		if (!discoverd[i]) //�湮�� ���� ���ٸ�(��� ť�� ������ ���ٸ�)
			DFS(graph, i, discoverd);		
	}
	return;
}

//2020.03.13. ������
void BFS(Graph const& graph, int v, std::vector<bool>& discoverd) {
	std::queue<int> q;	//ť ����	
	discoverd[v] = true;	//���� Ž�� ���� Ž����.
	q.push(v);		//ť�� ��������v �ֱ�
	while (!q.empty())	//������� �ʴ�(Ž���� ������ �����ִ�)
	{
		v = q.front();
		q.pop();
		std::cout << v << " ";
		for (int i : graph.adjList[v]) {
			if (!discoverd[i]) {//�湮�� ���� ���ٸ�(��� ť�� ������ ���ٸ�)
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

	// Number of nodes in the graph ���ڹ��� 0~5 ���� 6�� 
	int N = 6;

	// construct graph
	Graph graph(edges, N);
	std::vector<bool> discoverd(N, false);

//	BFS(graph, 0, discoverd);	//0�� �� �̾��� �׷��� Ž��
//	std::cout << "\n";
//	for (int i = 0; i < N; ++i) {
//		BFS(graph, i, discoverd);	//i�� �� �̾��� �׷��� Ž��
//	}	//�̱۳�尡 �ִٰ� ����, ���ڰ� ����� ���ڰ� 0~i���� ���� ������ �̾��� �־�� ��.

	// ���� BFS DFS ������� �ϰ������ false �� �ٲܰ�


	DFS(graph, 0, discoverd);	//0�� �� �̾��� �׷��� Ž��
	std::cout << "\n";
	// print adjacency list representation of graph
	printGraph(graph, N);	//���� �׷����� ��� ��

	return 0;
}