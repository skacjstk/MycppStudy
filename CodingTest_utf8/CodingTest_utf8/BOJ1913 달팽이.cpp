#include <iostream>
#include <vector>


int main(void)
{
	int n, m;
	std::cin >> n;
	std::cin >> m;

	// 방향: 상 우 하 좌 순서 
	int direction[4][2] =
	{
		{0, -1}, {1, 0}, {0, 1}, {-1, 0}
	};
	int directionIndex = 0;
	std::vector<std::vector<int>> arr;
	arr.resize(n, std::vector<int>(n, 0));

	// 항상 시작은 n /2 , n/2
	int sX = n / 2;
	int sY = n / 2;

	int cX = sX;
	int cY = sY;

	int fX = 0, fY = 0;

	int startOffset = 1;
	int currOffset = startOffset;
	bool isAddOffset = true;	// true일 때, offset이 1 씩 증가할 것

	for (int i = 1; i <= n * n; ++i)
	{
		arr[cX][cY] = i;	// 값 넣기
		--currOffset;

		// 값 맞으면 출력준비하기 
		if (i == m)
		{
			fX = cX + 1;
			fY = cY + 1;
		}

		cX += direction[directionIndex][0];
		cY += direction[directionIndex][1];

		if (currOffset <= 0)
		{
			// 방향 바꾸기
			++directionIndex %= 4;
			isAddOffset = !isAddOffset;
			// 이게 True면, 
			if (isAddOffset)
			{
				++startOffset;	//offset 을 하나 늘리기
			}
			currOffset = startOffset;	// 그리고 받기
		}
	} // 입력 완료

	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
		{
			std::cout << arr[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << fY << " " << fX;
	return 0;
}