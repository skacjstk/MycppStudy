#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define UINT unsigned int
int N;
using namespace std;
vector<int> DP;	// ������ ������ ��
vector<int> Seq;

int Solve()
{
	DP[0] = 1;
	int Result = 1;
	for (UINT i = 1; i < N; ++i)
	{
		// 0 ~ i ����, Seq[i] ���� ���� ���� ���� �ֵ� �߿� ���� Dp�� ū �� + 1�� ����ֱ�
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
		// �������̽� �ڵ�����
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
		// �����Է�
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