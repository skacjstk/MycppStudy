// 01 10 이긴 한데 중요한건 변수n에서 0이 호출된 횟수는 1이 호출된 횟수 fibo(n-1) 개라는거
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

/*
아래에서 사용한 것
https://www.codentalks.com/t/topic/7880
https://en.cppreference.com/w/cpp/language/value_category
(value 종류{연산자 오버로딩에 const 참조전달 또는 복사전달을 써야하는 이유})
연산자 오버로딩
std vector
std pair
*/
/*			//std pair 는 메모리 소모가 큰가??
#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> operator + (const std::pair<int, int> &first, const std::pair<int, int> & second) {
	int x = first.first + second.first;
	int y = first.second + second.second;
	return std::make_pair(x, y);
}

std::pair<int, int> pairnacci(std::vector<std::pair<int, int>> &zeroOne, int n) {

	if (n == 0)
		return std::make_pair(1, 0);
	if (n == 1)
		return std::make_pair(0, 1);
	if (zeroOne[n].first > 0) {
	//	printf("메모이제이션: %d\n", n);
		return std::make_pair(zeroOne[n].first, zeroOne[n].second);
	}
	else {
		return zeroOne[n] = pairnacci(zeroOne, n - 1) + pairnacci(zeroOne, n - 2);
	}

}
int main() {
	std::vector<std::pair<int, int>> zeroOne;

	int coin = 0;
	std::cin >> coin;
	zeroOne.resize(41);
	for (int i = 0; i < coin; ++i) {
		int f;
		std::cin >> f;
		zeroOne[i] = pairnacci(zeroOne, f);
		printf("%d %d \n", zeroOne[i].first, zeroOne[i].second);
	}
	return 0;
} */
//한번에 입력받고 한번에 출력하는 방식(틀렸습니다)
/*
#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> operator + (const std::pair<int, int> &first, const std::pair<int, int> & second) {
	int x = first.first + second.first;
	int y = first.second + second.second;
	return std::make_pair(x, y);
}

std::pair<int, int> pairnacci(std::vector<std::pair<int, int>> &zeroOne, int n) {
	if (n == 0)
		return std::make_pair(1, 0);
	else if (n == 1)
		return std::make_pair(0, 1);
	if (zeroOne[n].first) {
		return std::make_pair(zeroOne[n].first, zeroOne[n].second);
	}
	else {
		return zeroOne[n] = pairnacci(zeroOne, n - 1) + pairnacci(zeroOne, n - 2);
	}

}
int main() {
	std::vector<std::pair<int, int>> zeroOne;

	int coin = 0;
	std::cin >> coin;
	zeroOne.resize(41);
//	printf("%d\n", zeroOne.size());
	for (int i = 0; i < coin; ++i) {
		int f;
		std::cin >> f;
		zeroOne[i] = pairnacci(zeroOne, f);
	}

for (int i = 0; i < coin; ++i) {
	printf("%d %d \n", zeroOne[i].first, zeroOne[i].second);
}
return 0;
}

*/