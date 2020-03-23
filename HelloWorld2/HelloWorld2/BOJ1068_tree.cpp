#include <iostream>
#include <algorithm>
#include <vector>
//���� ����Ʈ�� ǥ���ؾ���


class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	//adjacency ��: ����
	std::vector<std::vector<int>> adjList;
//	std::vector<std::pair<bool, int>> isleaf;	//leaf �������, �ڽ��� ���� ������
		//����.	

	// Graph Constructor
	Graph(int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);
	}
	void NodeConnect(const int &index, const int &myParent, int &root) {
		if (myParent == -1){
			root = index;	//root ����, 
			return;
		}
		else {
			adjList[myParent].push_back(index);
		}
		return;
	}	//��� ����� 

	void numOfleaf(const int &deleteNode,const int &now_node, int& leafCnt) {
		if (now_node == deleteNode) return;
		int childSize = adjList[now_node].size();	//�� node�� ������ �ִ� �ڽ��� ��
		switch (childSize) {
		case 0:	//�ڽ��� ������ �ڽ��� leafNode �̴�.
			++leafCnt; return; 
			break; //�ʿ����.
		case 1:	//�ڽ��� 1���� 
			//�ڱ� �ڽ��� ���� ����̶��, �ڽ��� leafNode �� �ȴ�.
			if (adjList[now_node][0] == deleteNode){
				++leafCnt;
				break;
			}
		default:	//�ڽ� ����ŭ �ݺ�
			for (int i = 0; i < childSize; ++i) {
				numOfleaf(deleteNode, adjList[now_node][i], leafCnt);	
				//�ٸ��� �״�ΰ�, now_node(�θ�) �� �ڽ� node �� ��ŭ ����Լ� ����
			}//endfor
			break;
		}//end switch
		return;
	}

};			// 0 1 2 3 4
int main(void)
{
	int numOfNode = 0;
	int deleteNode = 0;
	std::cin >> numOfNode;
	Graph graph(numOfNode);
	int root = 0;
	int myParent = 0;
	for (int i = 0; i < numOfNode; ++i) {
		std::cin >> myParent;
		graph.NodeConnect(i, myParent, root);
	}
	
	std::cin >> deleteNode;
	int leafCnt = 0;//0�� �ֻ��� ���
	graph.numOfleaf(deleteNode, root, leafCnt);	

	std::cout << leafCnt;
	return 0;
}