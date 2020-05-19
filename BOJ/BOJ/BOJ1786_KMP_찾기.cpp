#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
std::vector<int> failure_function(const std::string & S);

int correctNum = 0;

std::vector<int> kmp(const std::string& H, const std::string& S)
{
	int h_len = H.length();	//전체문자열
	int s_len = S.length(); //비교문자열

	// 실패 함수값을 구해놓았다는 가정.
	std::vector<int> f = failure_function(S);	//partialMatch 
	std::vector<int> r;		//result

	int begin = 0, m = 0; //matched
	
	while (begin <= h_len - s_len) {

		if (H[begin + m] == S[m]) { //일치  
			++m;
			if (m == s_len) {
				//r 벡터에 넣기 
				r.push_back(begin+1);
			}
		} //endif
		else {	//불일치
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

	// 끝까지 확인한다.
	while (begin + m < n) {
		// 일치하면 m을 증가시키고 실패함수를 초기화한다.
		if (S[begin + m] == S[m])  //일치 
		{
			m++;
			f[begin + m - 1] = m;
		}
		else {	//불일치 
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
	}	//주의: answer에 저장된 값은 index를 1에서 시작하도록 취급했다. 

	return 0;
}

//https://baeharam.github.io/posts/algorithm/kmp/
//https://jaimemin.tistory.com/627

//둘을 응용(일단은) 했음