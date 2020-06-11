#include <iostream>
#include <set>

void PrintAll(std::set<int>& s) {
	//for each �� ���
	printf("���� ���\n");
	for (auto element : s) {
		std::cout << element << "\n";
	}
	printf("=====��� ��=====\n");
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
	s.insert(4);	//�ߺ� (�ι� �ȵ�.)


	PrintAll(s);
	//std::set <int>::iterator Ÿ�� 
	
	if (s.find(9) != s.end()) {
		printf("���� ����\n");
	}
	else {
		printf("���� ����\n");
	}
	if (s.find(6500) != s.end()) {
		printf("���� ����\n");
	}
	else {
		printf("���� ����\n");
	}

	s.erase(4);
	PrintAll(s);

	s.erase(s.begin(), ++s.find(3));
	//�ڽ��� ������ ������� �������������� ��� 
	PrintAll(s);
	//���� �˾Ҵ� ��, ���������� �ι��� �ǳ� 

	return 0;
}