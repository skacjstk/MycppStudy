#include <iostream>

constexpr int CFactorial(int n) {
	int total = 1;
	for (int i = 1; i <= n; i++) {
		total *= i;
	}
	return total;
}
//템플릿 메타 프로그래밍 (TMP) 으로 상수 표현식 구현 
template <int N>
struct Factorial {
  static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
  static const int value = 1;
};

template <int N>
struct A {
  int operator()() { return N; }
};

int main() {
  // 컴파일 타임에 값이 결정되므로 템플릿 인자로 사용 가능!
  A<Factorial<10>::value> a;
  std::cout << a() << std::endl;
  //상수 표현식 
  std::cout << CFactorial(9) << "\n";

}