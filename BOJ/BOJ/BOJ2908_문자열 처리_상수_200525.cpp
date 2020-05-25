#include <iostream>
#include <string>
#include <algorithm>

//���� ũ�Ⱑ �������� ��� ������
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

	//�� ���� ���� ���� �� �ڸ� ���̴�.
	std::cout << customCompare(a, b);



	return 0;
}