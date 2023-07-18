#include <iostream>
#include <string>
#include <limits>
#include <vector>

#define INT_INF std::numeric_limits<int>::max() / 2	// 진짜 INF면 오버플로 나...

class Edge
{
public:
	// 배열 번호가 시작노드임
	int Start;
	int End;
	int Cost;
	Edge() { Start = 0; End = 0; Cost = 0; }
	Edge(int start, int end, int cost)
		:Start(start), End(end), Cost(cost)
	{}
};

int N, M, W;	// 시작, 도착, 가중치
std::vector<Edge> Edges;
std::vector<int> distance;

bool BellmanFord()
{
	distance[1] = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < (int)Edges.size(); ++j)
		{
			int Start = Edges[j].Start;
			int End = Edges[j].End;
			int Cost = Edges[j].Cost;						
			if (distance[End] > distance[Start] + Cost) {
				distance[End] = distance[Start] + Cost;
			}			
		}
	}
	for (int j = 0; j < (int)Edges.size(); ++j)
	{
		int Start = Edges[j].Start;
		int End = Edges[j].End;
		int Cost = Edges[j].Cost;

		if (distance[End] > distance[Start] + Cost) {
			return true;	// 정상 사이클이라면 업데이트가 이뤄지지 않음
		}
	}
	return false;		
}

int main()
{
	int TestCase = 0;
	bool IsInfinite = false;

	std::cin >> TestCase;
	for (int i = 0; i < TestCase; ++i)
	{
		std::cin >> N >> M >> W;
		Edges.clear();
		distance.assign(N + 1, INT_INF);	// 0 번을 사용하지 않음

		int s, e, t;
		for (int j = 0; j < M; ++j)
		{
			std::cin >> s >> e >> t;
			Edges.push_back(Edge(s, e, t));
			Edges.push_back(Edge(e, s, t));	// 워프간선과 중복되는 부분이 없나본데?
		}
		for (int k = 0; k < W; ++k)
		{
			std::cin >> s >> e >> t;
			Edges.push_back(Edge(s, e, -t));
		}
		IsInfinite = BellmanFord();

		std::string result = IsInfinite ? "YES\n" : "NO\n";
		std::cout << result;
	}
	// 시작점은 어디던 상관없음
	// 무한 사이클의 음수 간선이 존재하면 bool 값은 true가 된다
	return 0;
}