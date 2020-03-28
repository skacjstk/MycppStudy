#include <iostream>
#include <queue>	//queue
#include <utility>	//pair
#include <vector>
#include <algorithm>	//sort
//#include <string>

//필요한 데이터
/*
	//인접리스트, 인접행렬 다 해보자.
	vertex와 edge 표기할 vector 인접리스트 표현식  (2차원 벡터)
	vertex 의 방문을 표기할 1차원 벡터

	vertex 수 : N -?1~1000
	edge 수: 1~49900 개



	BFS : 최단경로 탐색 용이
		노드가 많으면 큐가 커짐.
		깊이가 얕으면 좋음

	DFS: 최단경로 보장 X 
		저장공간 필요성 적음
		찾아야 하는게 깊거나 왼쪽에 있을수록 유리 
*/



class Graph {
public:
	std::vector<std::vector<int>> adjList;
	std::vector<int> visited;
	int vertexCnt;
	int edgeCnt;
	Graph(int vertex, int edge) {
		vertexCnt = vertex;
		adjList.resize(vertex+1);
		visited.resize(vertex+1,false);
		edgeCnt = edge;
	}	//생성자 

	void vertexConnect(const int a,const int b) {
		adjList[a].push_back(b);
	}

	void DFS(const int vertex) {
		visited[vertex] = true;
			for (int &nextVertex : adjList[vertex]) {
//			printf("vertex:%d --> %d",vertex, list);		
				if (visitedCheck(nextVertex))	//이 위치가 방문하지 않았다면
				{
	//				printf("\t true\n");
					DFS(nextVertex);
				}
			}		
	}
	bool visitedCheck(const int &next){
		if (!visited[next]) {	//방문을 안했으면 false 		
			return true;
		}
		return false;	}

};

Graph graphMake(bool flag) {
	int vertex;
	int edge;
	std::cin >> vertex >> edge;
	if (flag)	//true 는 인접리스트 
	{
		return Graph(vertex, edge);
	}
	else
	{
		printf("인접행렬은 아직 안만들었음.\n");
		exit(1);//인접행렬 아직안만듬
	}
}
	int main(void)
{		
		Graph graph = graphMake(true); //true는 인접리스트, false는 인접행렬
//		printf("%d",graph.edgeCnt);
		for(int i=0;i < graph.edgeCnt; ++i){
			int a, b;
			std::cin >> a >> b;
			graph.vertexConnect(a, b);
			graph.vertexConnect(b, a); //무향
		}		

		int graphCnt = 0;

//		printf("VertexCnt:%d\n", graph.vertexCnt);
		for (int i = 1; i <= graph.vertexCnt; ++i) {
//			int edgeSize = graph.adjList[i].size();
//			printf("%d -> edgeSize:%d\n",i, edgeSize);
//			if(edgeSize > 0) {	//사이즈가 1 이상일 경우
				if (graph.visitedCheck(i)) {
					++graphCnt;
					graph.DFS(i);
				}
//			}		//사이즈 검사를 하면 백준에서 틀렸다고 한다.
		}

		printf("%d\n", graphCnt);
		return 0;
}

	