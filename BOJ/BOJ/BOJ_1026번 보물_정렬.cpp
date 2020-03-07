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
	int a[50];	//�� ���Ҵ� 0~100 ������ ��
	int b[50]; 
	bool bCheck[50] = { false };  // b�迭�� max�� Ž��, b�� bCheck�� ����ü�� �����..?
			//bCheck�� bool �迭��, �⺻ �ʱ�ȭ�� false �� . 
	std::string stringArr;
	std::cin >> arrSize;	//�ִ� 50 
	
	for (int i = 0; i < arrSize; ++i){
		std::cin >> a[i];
	}
	for (int i = 0; i < arrSize; ++i) {
		std::cin >> b[i];
	}
	std::sort(a, a+arrSize); //�ּҰ� ����  
	//std::sort(b, b + arrSize, std::greater<int>());

	for (int j = 0; j < arrSize; ++j) {	
		int max = 0;
		int idx = 0;
		for (int i = 0; i < arrSize; ++i) {
			if (!bCheck[i] && b[i] > max){
				max = b[i];		
				idx = i;
			}
		}		//�迭 ������ �ִ��� ���Ѵ�
		bCheck[idx] = true;	//���������� max������ ������ �迭�� ���� max���� ������ �Ѵ�.
		minSum += a[j] * max;
		//���� �ִ밪�� ������ a[j] ��°�� ����
	}//endfor
	

	printf("%d", minSum);
	return 0;
}

/*
//��Ģ����: b�� �����Ѵ�.
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
	int a[50];	//�� ���Ҵ� 0~100 ������ ��
	int b[50];
	std::string stringArr;
	std::cin >> arrSize;	//�ִ� 50
	for (int i = 0; i < arrSize; ++i){
		std::cin >> a[i];
	}
	for (int i = 0; i < arrSize; ++i) {
		std::cin >> b[i];
	}
	std::sort(a, a+arrSize);
	std::sort(b, b + arrSize, std::greater<int>());
	//������ b �迭�� �������� ����� ����.(�ӽÿ�)
	for (int i = 0; i < arrSize; ++i) {
		minSum += (a[i] * b[i]);
	}


	printf("%d", minSum);
	return 0;
}
*/