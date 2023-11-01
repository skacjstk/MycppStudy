#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int N, K;

vector<int> Bridges;
vector<int> DP;

int CheckVarify(int current)
{
	if (current == (N - 1))
		return 1;
	
	// 메모이제이션
	if (DP[current] != -1)
		return DP[current];

	DP[current] = 0; // 방문함

	for (int i = current + 1; i < N; ++i)
	{
		if ((i - current) >= K)
			break;

		int Power = (i - current) * (1 + abs(Bridges[current] - Bridges[i]));

		if (Power <= K)
		{
			DP[current] = CheckVarify(i);
			if (DP[current] == 1)	// 결과 나왔는데 맞으면 중단
				break;
		}
	}
	return DP[current];
}

int main()
{
	cin >> N >> K;
	Bridges.resize(N);
	DP.resize(N, -1);
	for (int i = 0; i < N; ++i)	
		cin >> Bridges[i];
	

	if (CheckVarify(0) >= 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}