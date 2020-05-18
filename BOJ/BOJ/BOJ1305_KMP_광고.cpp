#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::vector<int> failure_function(const std::string &S) {
	int n = S.length();
	std::vector<int> f(n, 0);
	int begin = 1, m = 0;
	//	int answer = 0;
		// 끝까지 확인한다.
	while (begin + m < n) {
		// 일치하면 m을 증가시키고 실패함수를 초기화한다.
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
