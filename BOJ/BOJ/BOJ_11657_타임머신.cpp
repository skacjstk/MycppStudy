#include <iostream>
#include <string>
#include <limits>
#include <vector>

#define INT_INF std::numeric_limits<long long>::max() / 2	// 진짜 INF면 오버플로 나...

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
std::vector<long long> distance;

void BellmanFord()
{
	distance[1] = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < (int)Edges.size(); ++j)
		{
			int Start = Edges[j].Start;
			int End = Edges[j].End;
			int Cost = Edges[j].Cost;
			// 단절된 정점끼리의 Cycle을 파악할 필요가 없음.
            if (distance[Start] == INT_INF) continue;				
			if (distance[End] > distance[Start] + Cost) {
				distance[End] = distance[Start] + Cost;
			}			
		}
	}
}

bool BellmanSearch()
{
	for (int j = 0; j < (int)Edges.size(); ++j)
	{
		int Start = Edges[j].Start;
		int End = Edges[j].End;
		int Cost = Edges[j].Cost;
		
        if (distance[Start] == INT_INF) continue;
		if (distance[End] > distance[Start] + Cost) {
			return true;	// 정상 사이클이라면 업데이트가 이뤄지지 않음
		}
	}
	return false;
}

int main()
{
	bool IsInfinite = false;

	std::cin >> N >> M;
	Edges.clear();
	distance.assign(N + 1, INT_INF);	// 0 번을 사용하지 않음
	int s, e, t;
	for (int j = 0; j < M; ++j)
	{
		std::cin >> s >> e >> t;
		Edges.push_back(Edge(s, e, t));
	}
	
	BellmanFord();
	IsInfinite = BellmanSearch();
	
	if(IsInfinite)
	{
	    std::cout << "-1";
	}
	else
	{
	    for(long long i=2; i < (long long)distance.size(); ++i)
	    {
	    	std::string result = distance[i] != INT_INF ? std::to_string(distance[i]) : "-1";
	        std::cout << result << std::endl;
	    }
	}
	return 0;
}