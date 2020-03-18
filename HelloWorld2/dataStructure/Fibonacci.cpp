#include <iostream>
#include <vector>
#include <chrono>
int fibonacci(std::vector<int> &memo,const int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (memo[x]) return memo[x];
	else
		return memo[x] = fibonacci(memo, x - 1) + fibonacci(memo, x - 2);
}
int fibonacci(std::vector<int> &memo, const int x, bool flag){
	if (x == 1) return 1;
	if (x == 2) return 1;
	else
		return memo[x] = fibonacci(memo, x - 1) + fibonacci(memo, x - 2);
}

int main(void)
{	
	printf("�Ǻ���ġ ���� �Է�:");
	int num = 0;
	std::cin >> num;
	std::vector<int> memo(num+1);

//	auto start = std::chrono::steady_clock::now();
	printf("%d\n", fibonacci(memo, num));
//	auto fiboEnd = std::chrono::steady_clock::now();
//	printf("%d\n", fibonacci(memo, num, false));
//	auto noMemoiFiboEnd = std::chrono::steady_clock::now();

//	std::cout << "�Ǻ���ġ ����(�޸������̼�) �Ҹ� �ð� : "
//		<< std::chrono::duration_cast<std::chrono::milliseconds>(fiboEnd - start).count()<< " ms" << "\n";
//	std::cout << "�Ǻ���ġ ����(no�޸�������) �Ҹ� �ð� : "
//		<< std::chrono::duration_cast<std::chrono::milliseconds>(noMemoiFiboEnd - fiboEnd).count() << " ms" << "\n";

	//chrono �� �̷��� ���°� �ƴѰ�����. 
	return 0;
}