#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define INF 9999999
#define UINT unsigned int
vector<vector<int>> Matrix;
vector<vector<int>> OutputMatrix;

void SolveFloyd(int N)
{ 
	// 간선 노드
	for (int i = 0; i < N; ++i)
	{
		// 출발노드
		for (int j = 0; j < N; ++j)
		{
			// 끝노드
			for (int k = 0; k < N; ++k)
			{
				if (OutputMatrix[j][i] + OutputMatrix[i][k] < OutputMatrix[j][k]) {
					OutputMatrix[j][k] = 1;// OutputMatrix[j][i] + OutputMatrix[i][k];
				}
			}
		}
	}
}

void Output(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(OutputMatrix[i][j] >= INF)	
				cout << "0 ";
			else
				cout << OutputMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(void)
{
	int N;
	cin >> N;

	Matrix.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Matrix[i][j];
			if (Matrix[i][j] == 0)
				Matrix[i][j] = INF;
		}
	}
	OutputMatrix = Matrix;
	SolveFloyd(N);
	Output(N);

	return 0;
}