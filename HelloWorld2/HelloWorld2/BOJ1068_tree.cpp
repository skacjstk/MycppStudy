#include <iostream>
#include <vector>
#include <utility>
//인접 리스트로 표현해야지

;
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	//adjacency 뜻: 인접
	std::vector<std::vector<int>> adjList;
	std::vector<std::pair<bool, int>> isleaf;	//leaf 노드인지, 자식의 수가 몇인지
	

	// Graph Constructor
	Graph(int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);
		isleaf.resize(N);	//그 인덱스가 leaf 노드인지 판별한다.
		for (int i = 0; i < N; ++i) 
			isleaf[i].second = 0;		//혹시몰라
		/*
		// add edges to the directed graph
		for (auto &edge : edges)
		{
			// insert at the end
			adjList[edge.src].push_back(edge.dest);

			// Uncomment below line for undirected graph
			// 무향 그래프면 바로 아랫줄 주석을 지워 쌍방향으로 이을 것
			 adjList[edge.dest].push_back(edge.src);
		} */
	}
	void NodeConnect(const int &i, const int &myParent) {
		if (myParent == -1){
			adjList[i].push_back(myParent);
			isleaf[i].first = false;
		}
		else {
			adjList[myParent].push_back(i);
			isleaf[myParent].first = false;
			isleaf[i].first = true;

		}
	}	//노드 연결과 leaf노드 수정
	void numOfleaf(const Graph &graph) {		
		int leafCnt = 0;
		for (auto i : graph.isleaf) {
			if (i.first)
				++leafCnt;
		} 
		std::cout <<"리프노드 갯수: "<< leafCnt<< "\n";
	}

	void DeleteNode(int deleteNode) {
		isleaf[deleteNode].first = false;

	}
};			// 0 1 2 3 4
int main(void)
{
	int numOfNode = 0;
	int myParent = 0;
	int deleteNode;
	int leafCnt = 0;
	std::cin >> numOfNode;

	Graph graph(numOfNode);
	for (int i = 0; i < numOfNode; ++i) {
		std::cin >> myParent;
		graph.NodeConnect(i, myParent);
	}
	graph.numOfleaf(graph);
	
	std::cin >> deleteNode;
	graph.DeleteNode(deleteNode);
	//제거할 노드
	/*
	구현: isleaf 를 false 로 만들어야 한다.
		DFS 로 
	*/
}