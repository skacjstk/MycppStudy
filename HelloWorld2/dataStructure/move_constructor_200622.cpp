#include <iostream>
#include <cstring>
#include <vector>

class Student {
	char *string_content;  // ���ڿ� �����͸� ����Ű�� ������
	int string_length;     // ���ڿ� ����

	int memory_capacity;  // ���� �Ҵ�� �뷮

public:
	Student();

	// ���ڿ��� ���� ����
	Student(const char *str);

	// ���� ������
	Student(const Student &str);

	// �̵� ������
	Student(Student &&str) noexcept;

	~Student();
};

Student::Student() {
	std::cout << "������ ȣ�� ! " << std::endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = NULL;
}

Student::Student(const char *str) {
	std::cout << "������ ȣ�� ! " << std::endl;
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
Student::Student(const Student &str) {
	std::cout << "���� ������ ȣ�� ! " << std::endl;
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
Student::Student(Student &&str) noexcept {
	std::cout << "�̵� ������ ȣ�� !" << std::endl;
	string_length = str.string_length;
	string_content = str.string_content;
	memory_capacity = str.memory_capacity;

	// �ӽ� ��ü �Ҹ� �ÿ� �޸𸮸� ��������
	// ���ϰ� �Ѵ�.
	str.string_content = nullptr;
}
Student::~Student() {
	if (string_content) delete[] string_content;
}

int main() {
	Student s("abc");
	std::vector<Student> vec;
	vec.resize(0);

	std::cout << "ù ��° �߰� ---" << std::endl;
	vec.push_back(s);
	std::cout << "�� ��° �߰� ---" << std::endl;
	vec.push_back(s);
	std::cout << "�� ��° �߰� ---" << std::endl;
	vec.push_back(s);
}																				