#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
void fill(vector<int>& v, T done) {
	int i = 0;
	while (!done()) {
		v.push_back(i++);
	}
}

int main(void)
{
	int total_elements = 1;
	vector<int> cardinal;
	int testEl = 5;

	cardinal.push_back(1);
	cardinal.push_back(2);
	cardinal.push_back(4);
	cardinal.push_back(8);

	for_each(cardinal.begin(), cardinal.end(), [&](int i)
	{std::cout << i << testEl<<"\n"; total_elements *= i; });
	cout << "total elements : " << total_elements << endl;

	//������ ĸó�� [] �� ������ ���� ���ϸ� ��ü���� �����̰� �������� const �ٰ� 

	vector<int> stuff;
	fill(stuff, [&stuff]() -> bool { return stuff.size() >= 8; });


	for_each(stuff.begin(), stuff.end(), [](int i) { cout << i << " "; });
	return 0;
}