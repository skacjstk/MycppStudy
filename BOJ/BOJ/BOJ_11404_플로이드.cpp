#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

#define INT_INF std::numeric_limits<int>::max() - 1000	// ������ ū ��

std::vector<std::vector<int>> distance;	// ����->���� �̵� ���

void Floyd_Warshall(int n)
{
	for (int i = 0; i < n; ++i){
		for (int f = 0; f < n; ++f){
			for (int t = 0; t < n; ++t){
				if (distance[f][i] != INT_INF && distance[i][t] != INT_INF)
					distance[f][t] = std::min(distance[f][t], distance[f][i] + distance[i][t]);
				// �̵� ����� ���� vs from -> n + n -> to ��� �� ������ ������ �ֱ�
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

	// �̹��� ���� ���� - 1 �� �����غ�����
	for (int i = 0; i < m; ++i){
		std::cin >> start >> end >> cost;
		if(distance[start - 1][end - 1] > cost)	// �ߺ� ���� �ڽ�Ʈ���� ���ſ�
			distance[start - 1][end - 1] = cost;	// start->end ���� ����� cost
	}

	Floyd_Warshall(n);

	// ���
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