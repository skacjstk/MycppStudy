
#include <iostream>
#include <vector>


std::vector<int> arr;
void bSearch(const int &input) {
	int left = 0;
	int right = arr.size() - 1;
	int mid = right;

	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] < input)
			left = mid + 1;
		else
			right = mid;
	}

	arr[right] = input;

}

void inputCheck(const int &input) {
	if (arr.empty() || arr.back() < input) {
		arr.push_back(input);
	}
	else if (arr.back() > input) {
		bSearch(input);
	}

}

int main()
{

	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i)
	{
		int input;
		scanf("%d", &input);
		inputCheck(input);

		//���: ���� push_back, �Ϲ� continue, ���� ���ǻ���  
		//min < input = push_back
		// min > input = bSearch �� ���ǻ��� 
	}
	printf("%d\n", int(arr.size()));
	return 0;
}