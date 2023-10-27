#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

//��Ʈ �� ���� �˰��� ��ó:
//https://velog.io/@shmaxlee/bit-count.-%EB%B9%84%ED%8A%B8-%EC%88%98-%EC%84%B8%EA%B8%B0
//https://stackoverflow.com/questions/109023/count-the-number-of-set-bits-in-a-32-bit-integer
int BitCount(int i) {
	i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i & 0x0f0f0f0f) + ((i >> 4) & 0x0f0f0f0f);
	i = (i & 0x00ff00ff) + ((i >> 8) & 0x00ff00ff);
	i = (i & 0x0000ffff) + ((i >> 16) & 0x0000ffff);
	return i;
}

int main(void)
{
	int N, K;	// ���纸�� ������ ����, �ѹ��� �ű�� �ִ� ������ ����
	bool CalculateEnd = false;
	int Count = 0;
	int Quo = 0;
	int Remain;	// ���� ���� �� 
	cin >> N >> K;

	Quo = N;
	while (!CalculateEnd)
	{
		Remain = BitCount(Quo);
		if (Remain > K)
		{
			Count++;
			Quo ++;
			continue;
		}
		else
		{
			CalculateEnd = true;
		}
	}

	cout << Count;


	return 0;
}