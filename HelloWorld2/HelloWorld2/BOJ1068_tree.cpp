#include <iostream>
#include <vector>
#include <utility>
//���� ����Ʈ�� ǥ���ؾ���

;
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	//adjacency ��: ����
	std::vector<std::vector<int>> adjList;
	std::vector<std::pair<bool, int>> isleaf;	//leaf �������, �ڽ��� ���� ������
	

	// Graph Constructor
	Graph(int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);
		isleaf.resize(N);	//�� �ε����� leaf ������� �Ǻ��Ѵ�.
		for (int i = 0; i < N; ++i) 
			isleaf[i].second = 0;		//Ȥ�ø���
		/*
		// add edges to the directed graph
		for (auto &edge : edges)
		{
			// insert at the end
			adjList[edge.src].push_back(edge.dest);

			// Uncomment below line for undirected graph
			// ���� �׷����� �ٷ� �Ʒ��� �ּ��� ���� �ֹ������� ���� ��
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
	}	//��� ����� leaf��� ����
	void numOfleaf(const Graph &graph) {		
		int leafCnt = 0;
		for (auto i : graph.isleaf) {
			if (i.first)
				++leafCnt;
		} 
		std::cout <<"������� ����: "<< leafCnt<< "\n";
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
	//������ ���
	/*
	����: isleaf �� false �� ������ �Ѵ�.
		DFS �� 
	*/
}