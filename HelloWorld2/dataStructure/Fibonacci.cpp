#include <iostream>
#include <vector>
#include <chrono>
int fibonacci(std::vector<int> &memo,const int x) {
	if (x <= 2) return 1;
	if (memo[x]) return memo[x];
	else
		return memo[x] = fibonacci(memo, x - 1) + fibonacci(memo, x - 2);
}
int fibonacci(std::vector<int> &memo, const int x, bool flag){
		if (x <= 2) return 1;
	else
		return fibonacci(memo, x - 1,false) + fibonacci(memo, x - 2,false);
		//깜빡하고 여기에 아무 bool flag 를 안넣어서 두번쨰 함수부터 메모이제이션을 해버렸다.
}

int main(void)
{	
	printf("피보나치 수열 입력:");
	int num = 0;
	std::cin >> num;
	std::vector<int> memo(num+1);

	auto start = std::chrono::steady_clock::now();
	printf("%d\n", fibonacci(memo, num));
	auto fiboEnd = std::chrono::steady_clock::now();
	std::cout << "피보나치 수열(메모이제이션) 소모 시간 : "
		<< std::chrono::duration_cast<std::chrono::microseconds>(fiboEnd - start).count() << " us" << "\n";

	auto noMemoStart = std::chrono::steady_clock::now();	//정확한 측정을 위해
	printf("%d\n", fibonacci(memo, num, false));
	auto noMemoiFiboEnd = std::chrono::steady_clock::now();	
	std::cout << "피보나치 수열(no메모이제이) 소모 시간 : "
		<< std::chrono::duration_cast<std::chrono::microseconds>(noMemoiFiboEnd - noMemoStart).count() << " us" << "\n";

	//chrono 시간측정이 재대로 안된다.
	return 0;
}