#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
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
				r.push_back(begin+1);
			}
		} //endif
		else {	//����ġ
			if (m == 0)
				++begin;
			else{
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
	std::string h, s;

	getline(std::cin, h);
	getline(std::cin, s);

	std::vector<int> answer = kmp(h, s);

	printf("%d\n", answer.size());
	for (int element : answer) {
		printf("%d\n", element);
	}	//����: answer�� ����� ���� index�� 1���� �����ϵ��� ����ߴ�. 

	return 0;
}

//https://baeharam.github.io/posts/algorithm/kmp/
//https://jaimemin.tistory.com/627

//���� ����(�ϴ���) ����