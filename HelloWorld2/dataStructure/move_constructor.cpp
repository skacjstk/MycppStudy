#include <iostream>

class A {
	int data_;

public:
	A(int data) : data_(data) { std::cout << "�Ϲ� ������ ȣ��!" << std::endl; }

	A(const A& a) : data_(a.data_) {
		std::cout << "���� ������ ȣ��!" << std::endl;
	}
};

int main() {
	A a(1);  // �Ϲ� ������ ȣ��
	A b(a);  // ���� ������ ȣ��

	// �׷��ٸ� �̰���?
	A c(A(2));	//�Ϲ� �����ڸ� ���� ���� �����ڸ� ȣ������ ����.
}
