#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

#define INT_MAX       2147483647
using namespace std;

vector<int> Students;
unsigned int N, K;
int SolveResult = INT_MAX;
int CheckTired(int H)
{
	int Result = 0;
	if (N >= 2)
	{
		int current = Students[0];
		int after = Students[1];
		if (abs(current - after) > H)
			++Result;
	}

	for (unsigned int i = 1; i < N; ++i)
	{
		int before = Students[i - 1];
		int current = Students[i];
		int after = Students[i + 1];

		if (abs(current - before) > H || abs(current - after) > H)
			++Result;
	}

	return Result;
}

void BSearch(int low, int high)
{
	if (low > high)
		return;

	int mid = (low + high) / 2;	// H�� �뺯�ϴ� ��, ���� ����ϴ� H�� �ǹ�
	// ���� ���� mid�� ã��.
	int count = CheckTired(mid);

	// ������ ��, H Ű������
	if (K < count)
		BSearch(mid + 1, high);
	else
	{
		// ��ģ ��� �ʰ�, H �ٿ�����
		SolveResult = min(SolveResult, mid);
		BSearch(low, mid - 1);
	}
	// ��ǻ� 0 ~ 21���� �� ã�� �� ������ H ���� ������ �߶󰡸� ���ϴ� ��
}

int Solve()
{	
	BSearch(0, INT_MAX);
	return SolveResult;
}
int main()
{
	cin >> N >> K;	// �л���, ��ģ �����
	Students.resize(N + 1);
	for (int i = 0; i < N; ++i)
	{
		cin >> Students[i];
	}
	Students[N] = Students[N - 1];	// �� �л� ��� ���ϰ� �ϱ� ���� ���̰�

	cout << Solve();
}