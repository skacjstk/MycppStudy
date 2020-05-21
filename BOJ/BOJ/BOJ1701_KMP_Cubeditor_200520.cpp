#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::vector<int> failure_function(const std::string & S);

int correctNum = 0;

std::vector<int> kmp(const std::string& H, const std::string& S)
{
	int h_len = H.length();	//��ü���ڿ�
	int s_len = S.length(); //�񱳹��ڿ�

	// ���� �Լ����� ���س��Ҵٴ� ����.
	std::vector<int> f = failure_function(S);	//partialMatch 
	std::vector<int> r;		//result

	int begin = 0, m = 0; //matched

	while (begin <= h_len - s_len) {

		if (H[begin + m] == S[m]) { //��ġ  
			++m;
			if (m == s_len) {
				//r ���Ϳ� �ֱ� 
				r.push_back(begin + 1);
			}
		} //endif
		else {	//����ġ
			if (m == 0)
				++begin;
			else {
				begin += m - f[m - 1];
				m = f[m - 1];
			}
		}
	}

	return r;
}
std::vector<int> failure_function(const std::string & S) {
	int n = S.length();
	std::vector<int> f(n, 0);
	int begin = 1, m = 0;

	// ������ Ȯ���Ѵ�.
	while (begin + m < n) {
		// ��ġ�ϸ� m�� ������Ű�� �����Լ��� �ʱ�ȭ�Ѵ�.
		if (S[begin + m] == S[m])  //��ġ 
		{
			m++;
			f[begin + m - 1] = m;
		}
		else {	//����ġ 
			if (m == 0)
				begin++;
			else
			{
				begin += (m - f[m - 1]);
				m = f[m - 1];
			} //end if
		}//end if 
	}
	return f;
}

int main()
{
	std::string  s;

	getline(std::cin, s);

	int answer = 0;

	for (unsigned int i = 0; i < s.size(); ++i) {
		std::string subs = s.substr(i);
		std::vector<int> pi = failure_function(subs);
		std::sort(pi.begin(), pi.end());

		answer = std::max(answer, pi.back());
	}

	printf("%d\n", answer);


	return 0;
}
