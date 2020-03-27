#include <iostream>
#include <algorithm>
void arrayDebug(int* a, int *b, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << "\t" << b[i] << "\n";
	}
}
void arrayDebug(int* a, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << "\t";
	}
	printf("\n");
}

int main(void)
{
	int arrSize, minSum= 0;
	int a[50];	//각 원소는 0~100 사이의 값
	int b[50]; 
	bool bCheck[50] = { false };  // b배열의 max값 탐색, b와 bCheck를 구조체로 만들까..?
			//bCheck는 bool 배열로, 기본 초기화는 false 다 . 
	std::string stringArr;
	std::cin >> arrSize;	//최대 50 
	
	for (int i = 0; i < arrSize; ++i){
		std::cin >> a[i];
	}
	for (int i = 0; i < arrSize; ++i) {
		std::cin >> b[i];
	}
	std::sort(a, a+arrSize); //최소값 정렬  
	//std::sort(b, b + arrSize, std::greater<int>());

	for (int j = 0; j < arrSize; ++j) {	
		int max = 0;
		int idx = 0;
		for (int i = 0; i < arrSize; ++i) {
			if (!bCheck[i] && b[i] > max){
				max = b[i];		
				idx = i;
			}
		}		//배열 원소의 최댓값을 구한다
		bCheck[idx] = true;	//최종적으로 max값으로 선정된 배열은 다음 max에서 못쓰게 한다.
		minSum += a[j] * max;
		//구한 최대값과 정렬한 a[j] 번째와 연산
	}//endfor	

	printf("%d", minSum);
	return 0;
}

/*
//규칙무시: b를 정렬한다.
#include <iostream>
#include <algorithm>
void arrayDebug(int* a, int *b, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << "\t" << b[i] << "\n";
	}
}
void arrayDebug(int* a, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << "\t";
	}
	printf("\n");
}

int main(void)
{
	int arrSize, minSum= 0;
	int a[50];	//각 원소는 0~100 사이의 값
	int b[50];
	std::string stringArr;
	std::cin >> arrSize;	//최대 50
	for (int i = 0; i < arrSize; ++i){
		std::cin >> a[i];
	}
	for (int i = 0; i < arrSize; ++i) {
		std::cin >> b[i];
	}
	std::sort(a, a+arrSize);
	std::sort(b, b + arrSize, std::greater<int>());
	//문제는 b 배열을 정렬하지 말라고 했음.(임시용)
	for (int i = 0; i < arrSize; ++i) {
		minSum += (a[i] * b[i]);
	}


	printf("%d", minSum);
	return 0;
}
*/