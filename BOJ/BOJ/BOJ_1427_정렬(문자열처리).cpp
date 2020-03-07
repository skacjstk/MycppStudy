#include <iostream>
#include <algorithm>
#include <string>
int main(void) {
	std::string str;
	std::cin >> str;
	sort(str.begin(), str.end(), std::greater<char>());
	std::cout << str;
	return 0;
}