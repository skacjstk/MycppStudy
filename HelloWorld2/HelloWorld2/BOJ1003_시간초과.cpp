
/*
�Ʒ����� ����� ��
https://www.codentalks.com/t/topic/7880
https://en.cppreference.com/w/cpp/language/value_category
(value ����{������ �����ε��� const �������� �Ǵ� ���������� ����ϴ� ����})
������ �����ε�
std vector
std pair
*/
		//std pair �� �޸� �Ҹ� ū��??
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
	//	printf("�޸������̼�: %d\n", n);
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
} 
//�ѹ��� �Է¹ް� �ѹ��� ����ϴ� ���(Ʋ�Ƚ��ϴ�)

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

