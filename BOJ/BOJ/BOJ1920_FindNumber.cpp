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
}	//값을 찾으면 true, 못찾으면 false


int main(void)
{
	int n;	//A에 들어갈 원소의 수
//	int A[100001]; //몬가..몬가..안맞아
	std::vector<int> A;
	int m;	//찾을 값의 수
	int find;	//그때그때 찾을 값

	scanf("%d", &n);
	A.resize(n+1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&A[i]);
	}
	sort(A.begin()+1, A.end()); //less<int>
	//정렬 정상
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