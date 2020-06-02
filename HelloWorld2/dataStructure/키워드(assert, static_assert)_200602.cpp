#include <iostream>
#include <cassert>
int main(void) {

	int arr[10] = { 0, };
	static_assert(sizeof(arr) / sizeof(int) != 10);

	int output = 10;

//	while (true)
//	{
//		assert(output > 0);
//		std::cout << "ÇöÀç °ª:" << output << "\n";
//		--output;
//	}

	return 0;
}