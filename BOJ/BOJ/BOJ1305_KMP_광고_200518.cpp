#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::vector<int> failure_function(const std::string &S) {
	int n = S.length();
	std::vector<int> f(n, 0);
	int begin = 1, m = 0;
	//	int answer = 0;
		// ������ Ȯ���Ѵ�.
	while (begin + m < n) {
		// ��ġ�ϸ� m�� ������Ű�� �����Լ��� �ʱ�ȭ�Ѵ�.
		if (S[begin + m] == S[m]) {
			m++;
			f[begin + m - 1] = m;
			//     answer = std::max(answer, m);
		}
		else {
			if (m == 0)
				begin++;
			else {
				begin += (m - f[m - 1]);
				m = f[m - 1];
				//         answer = std::max(answer,m);
			}
		} // endelse
	}
	return f;
	//	return answer;
}

int main()
{
	int num;
	scanf("%d", &num);
	std::string str;
	std::cin.ignore(1, '\n');
	getline(std::cin, str);
	std::vector<int> ff = failure_function(str);
	printf("%d\n", num - ff[num - 1]);


	//	std::cout << str << std::endl;
	return 0;
}
