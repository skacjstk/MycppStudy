#include <iostream>
#include <string>
#include <limits>
#include <vector>

#define INT_INF std::numeric_limits<int>::max() / 2	// ��¥ INF�� �����÷� ��...

class Edge
{
public:
	// �迭 ��ȣ�� ���۳����
	int Start;
	int End;
	int Cost;
	Edge() { Start = 0; End = 0; Cost = 0; }
	Edge(int start, int end, int cost)
		:Start(start), End(end), Cost(cost)
	{}
};

int N, M, W;	// ����, ����, ����ġ
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
			return true;	// ���� ����Ŭ�̶�� ������Ʈ�� �̷����� ����
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
		distance.assign(N + 1, INT_INF);	// 0 ���� ������� ����

		int s, e, t;
		for (int j = 0; j < M; ++j)
		{
			std::cin >> s >> e >> t;
			Edges.push_back(Edge(s, e, t));
			Edges.push_back(Edge(e, s, t));	// ���������� �ߺ��Ǵ� �κ��� ��������?
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
	// �������� ���� �������
	// ���� ����Ŭ�� ���� ������ �����ϸ� bool ���� true�� �ȴ�
	return 0;
}