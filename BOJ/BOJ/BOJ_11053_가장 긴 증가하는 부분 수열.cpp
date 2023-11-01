#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define UINT unsigned int
int N;
using namespace std;
vector<int> DP;	// 지나간 수열의 수
vector<int> Seq;

int Solve()
{
	DP[0] = 1;
	int Result = 1;
	for (UINT i = 1; i < N; ++i)
	{
		// 0 ~ i 까지, Seq[i] 보다 작은 수를 가진 애들 중에 가장 Dp가 큰 애 + 1을 집어넣기
		DP[i] = 1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (Seq[j] < Seq[i])
				DP[i] = max(DP[j] + 1, DP[i]);
		}
		Result = max(DP[i], Result);
	}
	return Result;
}

void Sample(bool IsValid)
{
	if (IsValid)
	{
		// 샘플케이스 자동실행
		N = 6;
		DP.resize((size_t)N, 0);
		Seq.resize((size_t)N, 0);
		Seq[0] = 10;
		Seq[1] = 20;
		Seq[2] = 10;
		Seq[3] = 30;
		Seq[4] = 20;
		Seq[5] = 50;
	}
	else
	{
		// 수동입력
		cin >> N;
		DP.resize((size_t)N, 0);
		Seq.resize((size_t)N, 0);

		for (int i = 0; i < N; ++i)
			cin >> Seq[i];
	}
}
int main(void)
{
	Sample(true);
	cout << Solve();
	return 0;
}