#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

#define INT_INF std::numeric_limits<int>::max() - 1000	// 적당히 큰 수

std::vector<std::vector<int>> distance;	// 도시->도시 이동 비용

void Floyd_Warshall(int n)
{
	for (int i = 0; i < n; ++i){
		for (int f = 0; f < n; ++f){
			for (int t = 0; t < n; ++t){
				if (distance[f][i] != INT_INF && distance[i][t] != INT_INF)
					distance[f][t] = std::min(distance[f][t], distance[f][i] + distance[i][t]);
				// 이동 비용을 기존 vs from -> n + n -> to 비용 중 저렴한 것으로 넣기
			}
		}
	}
}

int main(void)
{
	int n, m;
	int start, end, cost;
	std::cin >> n >> m;

	distance.resize(n);
	for (int i = 0; i < n; ++i)	
		distance[i].assign(n, INT_INF);	

	// 이번엔 실제 정점 - 1 로 대입해보려고
	for (int i = 0; i < m; ++i){
		std::cin >> start >> end >> cost;
		if(distance[start - 1][end - 1] > cost)	// 중복 버스 코스트낭비 제거용
			distance[start - 1][end - 1] = cost;	// start->end 가는 비용은 cost
	}

	Floyd_Warshall(n);

	// 출력
	int output;
	for (int f = 0; f < n; ++f){
		for (int t = 0; t < n; ++t){
			output = (distance[f][t] == INT_INF || f == t) ? 0 : distance[f][t];
			std::cout << output << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}