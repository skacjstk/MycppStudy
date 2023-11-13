#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long
#define DIVNUM 1000000007
vector<ll> CPUs;

// DP, 120��
ll Solve(int N)
{
	ll Result = 0;

	// ��ȭ��
	Result = CPUs[1];

	ll BeforeLineSum = Result;
	for (int i = 2; i < N; ++i)
	{
		BeforeLineSum = ((BeforeLineSum + 1) * CPUs[i]) % DIVNUM;
		Result += (BeforeLineSum % DIVNUM);
		Result = Result % DIVNUM;
	}

	return Result ;
}

// 30��
ll OldSolve(int N)
{
	ll Result = 0;

	// ù°�� �Ⱦ� 2���� ����
	for (int i = 1; i < N; ++i)
	{
		ll OneLineSum = CPUs[i];
		ll BeforeSum = CPUs[i];
		for (int j = i - 1; j >= 1; --j)
		{
			BeforeSum = (CPUs[j] * BeforeSum) % DIVNUM;
			OneLineSum += (BeforeSum % DIVNUM);
		}
		Result = Result + (OneLineSum % DIVNUM);
	}
	return Result % DIVNUM;
}

int main(void)
{
	int N;
	cin >> N;
	CPUs.resize(N);
	for (int i = 1; i < N; ++i)
	{
		cin >> CPUs[i];	// 1�Ⱑ �ִ�
	}
	cout << Solve(N);
//	cout << OldSolve(N);
	return 0;
}