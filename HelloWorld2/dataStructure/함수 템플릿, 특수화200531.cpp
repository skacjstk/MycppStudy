#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

template <class T>
T add(T x, T y) {
	return x + y;
}

template <>
const char * add(const char * string1, const char * string2) {
	char * a = new char[30];
	strcpy(a, string1);
	strcat(a, string2);
	return a;
}

template<class T1, class T2>
void justPrint(T1 a, T2 b) {
	std::cout << a << b << "\n";
}


int main(void) {
	int a = 1, b = 2;
	double q = 1.0, w = 2.1;

	std::cout << add<int>(a, b) << "\n"; // 3
	//add<int> -> <int> 자료형 지정 생략 가능. 
	//단, 자료형을 붙일 경우 가독성이 오름			
	std::cout << add<double>(q, w) << std::endl;	//3.1
	justPrint<int, double>(a, w);	//int 와 double 

	std::cout << add("hello", "world") << "\n";

	return 0;
}