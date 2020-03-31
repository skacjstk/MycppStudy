#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>


int bSearch(int n,int k) {
	int left = 1;
	int right = k;
	int mid = (left + right) / 2;
	long long compare = 0;
	int answer = 0;

	while (left <= right) {
		compare = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= n; ++i) {
			compare += std::min(n,mid/i);
			/*
				mid/i �� �� �࿡�� k���� ���� ���� ���� ���ϴ� ��.
			*/
		}
		if (compare < k) {
			left = mid + 1;
		}
		else {
			answer = mid;
			/*
			1. � �� x�� ���� ��, x-1 ������ ���� ������ K�� �̸��̰� x ������ ���� ������ K�� �̻��� ���
			�츮�� ã�� K��° ���� x �̴�.
			2. ��,  x�� x ������ ���� ������ K�� �̻��̸鼭 ���� ���� ���̴�.

			��ó: https://stack07142.tistory.com/298 [Hello World]
			���� ��� 3*3���� 7���� �� x�� ���� 6�ε�
			123
			246
			369
			6������ ���� 8���� 7������ ����
			5������ ���� 6���� 7������ ����
			6�� �� ������ �����ϸ鼭 ���� ���� ���̱� ������ 7��° ���� 6�̴�.
			*/
			right = mid - 1;
		}
	} //endwhile
	return answer;
}

int main(void)
{
	int n=-1;
	int k=-1;
	scanf("%d", &n);
	scanf("%d", &k);
	printf("%d", bSearch(n,k));	
	return 0;
}