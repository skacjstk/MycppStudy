#include<iostream>

void print(int n) {
	std::cout << "interger function" << "\n";
}
void print(char* n) {
	std::cout << "pointer function" << "\n";
}

int main() {
	print(0);
	print(NULL);
	print(nullptr);
	return 0;
}

/*
	�������� ���ž��� 
	���� NULL�� ��� ���ͷ� 0�� ������ null�� ���� �־ 
	����� �� �� ���� ��쿡 
	���� null�� ���ϴµ� 0�̶�� ����� �� ���� �־ �ٲ� 

	�ڵ�� ���� Ȯ���ѰԾ�� ���߿� 
*/