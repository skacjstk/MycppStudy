#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int total_elements = 1;
	vector<int> cardinal;
	int testEl = 5;

	cardinal.push_back(1);
	cardinal.push_back(2);
	cardinal.push_back(4);
	cardinal.push_back(8);

	for_each(cardinal.begin(), cardinal.end(), [&](int i) {std::cout << i << testEl<<"\n"; total_elements *= i; });

	//람다의 캡처절 [] 은 변수명 지정 안하면 전범위 접근이고 가져오면 const 붙고 
	//대충 많음 (미완성)

	cout << "total elements : " << total_elements << endl;
	return 0;
}