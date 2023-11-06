#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int Solve(vector<int>& Arr)
{
	vector<int> Sums;	// 0 부터 index 까지의 합
	int Result = INT32_MIN;
	int Count = Arr.size();
	Sums = Arr;

	Result = Sums[0];
	for (int i = 1; i < Count; ++i)
	{

		if (Sums[(size_t)i -1] < 0)		
			Sums[i] = Arr[i];		
		else
			Sums[i] = Sums[i] + Sums[(size_t)i - 1];

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