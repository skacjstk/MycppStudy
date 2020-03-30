#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
bool numCheck(const std::vector<int> &A, int find) {
	int left = 1;
	int right = A.size();
	int mid = (left+right) /2;
	
	while (left <= right) {
		mid = (left + right) / 2;
		if (A[mid] < find){
			left = mid + 1;
			continue;
		}
		else if (A[mid] > find){
			right = mid - 1;
			continue;
		}
		else // if (A[mid] == find)
			return true;
	}
	return false;
}	//���� ã���� true, ��ã���� false


int main(void)
{
	int n;	//A�� �� ������ ��
//	int A[100001]; //��..��..�ȸ¾�
	std::vector<int> A;
	int m;	//ã�� ���� ��
	int find;	//�׶��׶� ã�� ��

	scanf("%d", &n);
	A.resize(n+1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&A[i]);
	}
	sort(A.begin()+1, A.end()); //less<int>
	//���� ����
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		bool answer;
		scanf("%d", &find);
		if (numCheck(A, find))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}