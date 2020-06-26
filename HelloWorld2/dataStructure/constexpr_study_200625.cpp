#include <iostream>

constexpr int CFactorial(int n) {
	int total = 1;
	for (int i = 1; i <= n; i++) {
		total *= i;
	}
	return total;
}
//���ø� ��Ÿ ���α׷��� (TMP) ���� ��� ǥ���� ���� 
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
  // ������ Ÿ�ӿ� ���� �����ǹǷ� ���ø� ���ڷ� ��� ����!
  A<Factorial<10>::value> a;
  std::cout << a() << std::endl;
  //��� ǥ���� 
  std::cout << CFactorial(9) << "\n";

}