#include <iostream>
enum Color {	//������
	//enumerator(������)
	RED, 
	BLUE, 
	GREEN	// �� �����ڴ� ��ǥ�� �����ϸ� class ó�� �����ݷ����� enum �� ����. 
};
enum class Color2 {	//������
	//enumerator(������)
	RED = -5,
	BLUE,   // -4
	GREEN = 1,
	CYAN = 1,
	BLACK // 2
};
enum class enumClass {	//������
	//enumerator(������)
	RED = -5,
	BLUE,   // -4
	GREEN = 1,
	CYAN = 1,
	BLACK // 2
};
int main(void)
{

	printf("%d\n", RED); //enum Color �� �� 
	printf("%d\n", enumClass::RED);

	int b = RED;	//����
	enumClass a = enumClass::RED;	//����
	int a = enumClass::BLUE;	//����
	int c = Color::BLUE;	//����
	return 0;
}