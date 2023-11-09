#include <iostream>
#include <vector>

#define DIVNUM 1234567

using namespace std;
vector < vector<int>> DP;

int NextPassword(int Depth, int current)
{
	if (Depth == 1) return 1;
	if (DP[Depth][current] != -1) 
		return DP[Depth][current];

	
}

int Solve(int N, int T)
{
	int Result = 0;
	DP.resize(T, std::vector<int>(10, 1));


	return Result;
}
int main(void)
{
	int T, N;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		cout << Solve(N, T) % 1234567;
	}	

	return 0;
}