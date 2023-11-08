#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = INT32_MAX;

int N, D, from, to, cost;
vector<int> graph(10001, INF);
vector<pair<int, int>> v[10001];
// 다익스트라
int main() {

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        cin >> from >> to >> cost;
        if (to > D || to - from < cost) continue;
        v[to].push_back({ from, cost });
    }
    graph[0] = 0;

    for (int i = 1; i <= D; i++) {
        graph[i] = graph[(size_t)i - 1] + 1;
        for (int j = 0; j < (int)v[i].size(); j++) {
            graph[i] = min(graph[i], graph[v[i][j].first] + v[i][j].second);
        }
    }
    cout << graph[D];
}