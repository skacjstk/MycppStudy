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
	널포인터 별거없음 
	기존 NULL은 상수 리터럴 0과 포인터 null이 같이 있어서 
	상속을 할 때 같은 경우에 
	나는 null을 원하는데 0이라는 상수가 들어갈 수도 있어서 바꿈 

	코드는 뭔가 확실한게없어서 나중에 
*/