#include <iostream>

class A {
	int data_;

public:
	A(int data) : data_(data) { std::cout << "일반 생성자 호출!" << std::endl; }

	A(const A& a) : data_(a.data_) {
		std::cout << "복사 생성자 호출!" << std::endl;
	}
};

int main() {
	A a(1);  // 일반 생성자 호출
	A b(a);  // 복사 생성자 호출

	// 그렇다면 이것은?
	A c(A(2));	//일반 생성자를 만들어서 복사 생성자를 호출하지 않음.
}
/*
#include <iostream>
#include <cstring>

class MyString {
  char *string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

  int memory_capacity;  // 현재 할당된 용량

 public:
  MyString();

  // 문자열로 부터 생성
  MyString(const char *str);

  // 복사 생성자
  MyString(const MyString &str);

  void reserve(int size);
  MyString operator+(const MyString &s);
  ~MyString();

  int length() const;

  void print();
  void println();
};

MyString::MyString() {
  std::cout << "생성자 호출 ! " << std::endl;
  string_length = 0;
  memory_capacity = 0;
  string_content = nullptr;
}

MyString::MyString(const char *str) {
  std::cout << "생성자 호출 ! " << std::endl;
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString &str) {
  std::cout << "복사 생성자 호출 ! " << std::endl;
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
	string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
	char *prev_string_content = string_content;

	string_content = new char[size];
	memory_capacity = size;

	for (int i = 0; i != string_length; i++)
	  string_content[i] = prev_string_content[i];

	if (prev_string_content != nullptr) delete[] prev_string_content;
  }
}
MyString MyString::operator+(const MyString &s) {
  MyString str;
  str.reserve(string_length + s.string_length);
  for (int i = 0; i < string_length; i++)
	str.string_content[i] = string_content[i];
  for (int i = 0; i < s.string_length; i++)
	str.string_content[string_length + i] = s.string_content[i];
  str.string_length = string_length + s.string_length;
  return str;
}
int MyString::length() const { return string_length; }
void MyString::print() {
  for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() {
  for (int i = 0; i != string_length; i++) std::cout << string_content[i];

  std::cout << std::endl;
}

int main() {
  MyString str1("abc");
  MyString str2("def");
  std::cout << "-------------" << std::endl;
  MyString str3 = str1 + str2;
  str3.println();
}
*/