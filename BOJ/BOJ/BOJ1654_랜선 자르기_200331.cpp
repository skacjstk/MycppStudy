#include <iostream>
#include <vector>
#include <algorithm>

int needNCut(const long long &i, const long long &mid)
{
	return i / mid;
}
long long maxSize(std::vector<long long> &LAN, int needN) {
	long long min = 1;
	long long max = LAN[LAN.size() - 1];
	long long mid = (min + max) / 2;
	int cutN = 0;
	long long answer = 0;

	while (min <= max)    //min�� Ŀ���� �ݺ� ����
	{
		mid = (min + max) / 2;
		cutN = 0;
		for (long long i : LAN) {
			cutN += needNCut(i, mid);
		}
		//       printf("�߸� ����:%d\n�ʿ��� ����:%d\n",cutN,needN);
		//       printf("�ڸ� ����(cm):%d\n",mid);

		if (cutN < needN)  //�� �߰� �ɰ��� �Ѵ�.
		{
			max = mid - 1;
		}
		else if (cutN >= needN) {
			answer = std::max(answer, mid);
			//          printf("���� answer ��:%d\n",answer);
			min = mid + 1;
		}
	}
	return answer;
}


int main()
{
	int haveK, needN;
	std::cin >> haveK >> needN;

	std::vector<long long> LAN;
	LAN.resize(haveK);   //10000�� ������ �ڿ��� 
	for (int i = 0; i < haveK; ++i) {
		scanf("%lld", &LAN[i]);
	}

	std::sort(LAN.begin(), LAN.end());

	printf("%lld\n", maxSize(LAN, needN));


	return 0;
}
