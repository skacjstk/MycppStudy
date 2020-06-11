#include <iostream>
#include <set>

void PrintAll(std::set<int>& s) {
	//for each 문 사용
	printf("원소 출력\n");
	for (auto element : s) {
		std::cout << element << "\n";
	}
	printf("=====출력 끝=====\n");
}
int main(void)
{
	std::set <int> s;

	s.insert(1);
	s.insert(6);
	s.insert(2);
	s.insert(4);
	s.insert(3);
	s.insert(9);
	s.insert(8);
	s.insert(7);
	s.insert(4);	//중복 (두번 안들어감.)


	PrintAll(s);
	//std::set <int>::iterator 타입 
	
	if (s.find(9) != s.end()) {
		printf("값이 있음\n");
	}
	else {
		printf("값이 없음\n");
	}
	if (s.find(6500) != s.end()) {
		printf("값이 있음\n");
	}
	else {
		printf("값이 없음\n");
	}

	s.erase(4);
	PrintAll(s);

	s.erase(s.begin(), ++s.find(3));
	//자신을 포함해 지우려면 전위증감연산자 사용 
	PrintAll(s);
	//오늘 알았던 거, 증감연산자 두번도 되네 

	return 0;
}