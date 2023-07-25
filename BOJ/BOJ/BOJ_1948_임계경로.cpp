#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Node
{
public:
	// 배열 번호가 시작노드임
	int End;
	int Cost;
	Node() { End = 0; Cost = 0; }
	Node(int end, int cost)
		:End(end), Cost(cost)
	{}
};
std::vector<std::vector<Node>> Nodes;
std::vector<bool> visited;
std::vector<std::pair<int, int>> Vertex;    // Cost, 지나온경로 수
std::vector<int> Indegree;
int Start, End;

void Input()
{
    int n,m;    // 도시의 수, 간선의 갯수
    std::cin >> n >> m;
    Nodes.resize(n + 1); // 0번안씀
    visited.assign(n + 1, false);
    Vertex.assign(n + 1, std::make_pair(0,0));
    Indegree.assign(n + 1, 0);
    int s, e, t;
    for(int i = 0;i < m; ++i)
    {
        std::cin >> s >> e >> t;
        Nodes[s].push_back(Node(e, t));
        Indegree[e] += 1;
    }
    std::cin >> Start >> End;
}

void Process()
{
    std::queue<int> q;
    q.push(Start);
    
    while(!q.empty()){
        int src = q.front();
        q.pop();
        if(visited[src] || Indegree[src] != 0) continue;
        
        visited[src] = true;
        for(const Node dst : Nodes[src]) {
            if(Vertex[dst.End].first < Vertex[src].first + dst.Cost){
                Vertex[dst.End].first = Vertex[src].first + dst.Cost;
                Vertex[dst.End].second = Vertex[src].second + 1;
            }
            q.push(dst.End);
            Indegree[dst.End] -= 1;
        }
    }
    std::cout << Vertex[End].first << std::endl << Vertex[End].second;
}

int main()
{
    Input();
    Process();
    return 0;
}
