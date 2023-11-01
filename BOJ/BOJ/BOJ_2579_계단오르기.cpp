#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
unsigned int N;

vector<int> Stairs;
vector<int> DP;

int CheckVarify()
{
	// ��ȭ��
	DP[1] = Stairs[1];
	DP[2] = max(Stairs[1], Stairs[1] + Stairs[2]);
	DP[3] = max(Stairs[1] + Stairs[3], Stairs[2] + Stairs[3]);

	for (size_t i = 4; i <= N; i++) {
		int left = DP[i - 2] + Stairs[i];	// n -2 + n;
		int right = DP[i - 3] + Stairs[i - 1] + Stairs[i] ;	//  n - 3 + n - 1 + n;
		DP[i] = max(left, right);
	}
	return DP[N];
}

void Sample(bool IsValid)
{
	if (IsValid)
	{
		// �������̽� �ڵ�����
		N = 6;
		Stairs.resize((size_t)N + 1, 0);
		DP.resize((size_t)N + 1, 0);
		Stairs[0] = 0;
		Stairs[1] = 10;
		Stairs[2] = 20;
		Stairs[3] = 15;
		Stairs[4] = 25;
		Stairs[5] = 10;
		Stairs[6] = 20;
	}
	else
	{
		// �����Է�
		cin >> N;
		Stairs.resize((size_t)N + 1, 0);
		DP.resize((size_t)N + 1, 0);

		for (int i = 1; i <= N; ++i)
			cin >> Stairs[i];
	}
}
int main()
{
	Sample(false);
	cout << CheckVarify();
	return 0;
}