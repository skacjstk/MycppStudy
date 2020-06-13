#include <iostream>
#include <array>
int main(void)
{
	std::array <int, 4> arr1;
	std::array <int, 4> arr2 = { 0,2,1,3 };

	std::array <int, 4> arr3;

	arr3 = { 0,1,2 };	//비어있는 부분은 0으로 초기화 
	// 이 생성규칙으로 초기화되는거라  아래에 4,4 도 4,4,0,0 으로 초기화됨.
	arr3 = { 4, 4 }; //이니셜라이저 초과 불가  

	printf("%d", arr3[2]);




	return 0;

}