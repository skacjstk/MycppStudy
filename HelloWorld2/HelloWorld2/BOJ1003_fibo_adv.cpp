// 01 10 �̱� �ѵ� �߿��Ѱ� ����n���� 0�� ȣ��� Ƚ���� 1�� ȣ��� Ƚ�� fibo(n-1) ����°�
#include <iostream>

int fibonacci(int n) {
	static int arr[41] = { 0, };
	if (arr[n] > 0)
		return arr[n];
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
int main(void)
{	
	int numOfCase, num;
	std::cin >> numOfCase;
	for (int i = 0; i < numOfCase; ++i) {
		std::cin >> num;
		if 
			(num == 0)printf("1 0\n");		
		else 
			printf("%d %d\n", fibonacci(num - 1), fibonacci(num));
	}//endfor
	return 0;
}
