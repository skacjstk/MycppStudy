#include <iostream>
#include <queue>	//queue
#include <utility>	//pair
#include <vector>
#include <algorithm>	//sort
//#include <string>

//�ʿ��� ������
/*
	//��������Ʈ, ������� �� �غ���.
	vertex�� edge ǥ���� vector ��������Ʈ ǥ����  (2���� ����)
	vertex �� �湮�� ǥ���� 1���� ����

	vertex �� : N -?1~1000
	edge ��: 1~49900 ��



	BFS : �ִܰ�� Ž�� ����
		��尡 ������ ť�� Ŀ��.
		���̰� ������ ����

	DFS: �ִܰ�� ���� X 
		������� �ʿ伺 ����
		ã�ƾ� �ϴ°� ��ų� ���ʿ� �������� ���� 
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
	}	//������ 

	void vertexConnect(const int a,const int b) {
		adjList[a].push_back(b);
	}

	void DFS(const int vertex) {
		visited[vertex] = true;
			for (int &nextVertex : adjList[vertex]) {
//			printf("vertex:%d --> %d",vertex, list);		
				if (visitedCheck(nextVertex))	//�� ��ġ�� �湮���� �ʾҴٸ�
				{
	//				printf("\t true\n");
					DFS(nextVertex);
				}
			}		
	}
	bool visitedCheck(const int &next){
		if (!visited[next]) {	//�湮�� �������� false 		
			return true;
		}
		return false;	}

};

Graph graphMake(bool flag) {
	int vertex;
	int edge;
	std::cin >> vertex >> edge;
	if (flag)	//true �� ��������Ʈ 
	{
		return Graph(vertex, edge);
	}
	else
	{
		printf("��������� ���� �ȸ������.\n");
		exit(1);//������� �����ȸ���
	}
}
	int main(void)
{		
		Graph graph = graphMake(true); //true�� ��������Ʈ, false�� �������
//		printf("%d",graph.edgeCnt);
		for(int i=0;i < graph.edgeCnt; ++i){
			int a, b;
			std::cin >> a >> b;
			graph.vertexConnect(a, b);
			graph.vertexConnect(b, a); //����
		}		

		int graphCnt = 0;

//		printf("VertexCnt:%d\n", graph.vertexCnt);
		for (int i = 1; i <= graph.vertexCnt; ++i) {
//			int edgeSize = graph.adjList[i].size();
//			printf("%d -> edgeSize:%d\n",i, edgeSize);
//			if(edgeSize > 0) {	//����� 1 �̻��� ���
				if (graph.visitedCheck(i)) {
					++graphCnt;
					graph.DFS(i);
				}
//			}		//������ �˻縦 �ϸ� ���ؿ��� Ʋ�ȴٰ� �Ѵ�.
		}

		printf("%d\n", graphCnt);
		return 0;
}

	