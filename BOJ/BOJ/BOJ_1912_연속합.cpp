#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int OldSolve(vector<int>& Arr)
{
	int Result = INT32_MIN;
	int Count = Arr.size();

	for (int i = 0; i < Count; ++i)
	{
		for (int j = Count - 1; j >= i; --j)
		{
			int Sum = accumulate(&Arr[i], &Arr[j] + 1, 0);
			Result = max(Sum, Result);
		}
	}
	return Result;
}
int Solve(vector<int>& Arr)
{
	vector<int> Sums;	// 0 부터 index 까지의 합
	int Result = INT32_MIN;
	int Count = Arr.size();

	Sums = Arr;
	Result = Sums[0];
	for (int i = 1; i < Count; ++i)
	{
		Sums[i] = max(Sums[i] + Sums[(size_t)i - 1], Sums[i]); // 새로 시작하기 vs 이전 값 합치기 n-1 + n vs n 
		Result = max(Sums[i], Result);
	}
	return Result;
}
int main(void) 
{
	int N;
	vector<int> Arr;
	cin >> N;
	Arr.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Arr[i];
	}
	cout << Solve(Arr);
	return 0;
}