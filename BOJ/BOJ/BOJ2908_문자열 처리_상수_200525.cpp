#include <iostream>
#include <string>
#include <algorithm>

//양쪽 크기가 같을때만 사용 가능함
std::string customCompare(const std::string& a, const std::string& b) {

	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == b[i])
			continue;
		else if (a[i] > b[i])
			return a;
		else
			return b;
	}


	return "-1";
}



int main(void)
{
	std::string a, b;
	std::cin >> a >> b;

	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	//두 수는 같지 않은 세 자리 수이다.
	std::cout << customCompare(a, b);



	return 0;
}