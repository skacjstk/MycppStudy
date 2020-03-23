#include <iostream>
#include <algorithm>
#include <vector>
//인접 리스트로 표현해야지


class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	//adjacency 뜻: 인접
	std::vector<std::vector<int>> adjList;
//	std::vector<std::pair<bool, int>> isleaf;	//leaf 노드인지, 자식의 수가 몇인지
		//폐기됨.	

	// Graph Constructor
	Graph(int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);
	}
	void NodeConnect(const int &index, const int &myParent, int &root) {
		if (myParent == -1){
			root = index;	//root 갱신, 
			return;
		}
		else {
			adjList[myParent].push_back(index);
		}
		return;
	}	//노드 연결과 

	void numOfleaf(const int &deleteNode,const int &now_node, int& leafCnt) {
		if (now_node == deleteNode) return;
		int childSize = adjList[now_node].size();	//이 node가 가지고 있는 자식의 수
		switch (childSize) {
		case 0:	//자식이 없으면 자신이 leafNode 이다.
			++leafCnt; return; 
			break; //필요없음.
		case 1:	//자식이 1개면 
			//자기 자식이 지울 대상이라면, 자신은 leafNode 가 된다.
			if (adjList[now_node][0] == deleteNode){
				++leafCnt;
				break;
			}
		default:	//자식 수만큼 반복
			for (int i = 0; i < childSize; ++i) {
				numOfleaf(deleteNode, adjList[now_node][i], leafCnt);	
				//다른건 그대로고, now_node(부모) 의 자식 node 수 만큼 재귀함수 실행
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
	int leafCnt = 0;//0은 최상위 노드
	graph.numOfleaf(deleteNode, root, leafCnt);	

	std::cout << leafCnt;
	return 0;
}