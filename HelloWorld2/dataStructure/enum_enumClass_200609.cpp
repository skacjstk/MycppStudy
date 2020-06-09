#include <iostream>
enum Color {	//열거형
	//enumerator(열거자)
	RED, 
	BLUE, 
	GREEN	// 각 열거자는 쉼표로 구분하면 class 처럼 세미콜론으로 enum 을 덮음. 
};
enum class Color2 {	//열거형
	//enumerator(열거자)
	RED = -5,
	BLUE,   // -4
	GREEN = 1,
	CYAN = 1,
	BLACK // 2
};
enum class enumClass {	//열거형
	//enumerator(열거자)
	RED = -5,
	BLUE,   // -4
	GREEN = 1,
	CYAN = 1,
	BLACK // 2
};
int main(void)
{

	printf("%d\n", RED); //enum Color 의 값 
	printf("%d\n", enumClass::RED);

	int b = RED;	//가능
	enumClass a = enumClass::RED;	//가능
	int a = enumClass::BLUE;	//오류
	int c = Color::BLUE;	//가능
	return 0;
}