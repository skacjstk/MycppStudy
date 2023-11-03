#include <iostream>

using namespace std;
//X축 길이, Y축 길이, 컷당하는 둘레
long long Solve(int X, int Y, int Round)
{
	//X, Y가 각각 수직선 갯수, 수평선 갯수가 됨
	int Horizontal = Y * (Y + 1) / 2;
	int Vertical = X *(X + 1) / 2;
	int Rectangles = Horizontal * Vertical;

	// 둘레에 걸러지는 갯수 구하기
	long long UnderRound = 0;
	// Round가 6이면 2 x 1 까지만 허용 1 x 1은 탈락  6개 탈락
	// Round가 8이면 2 x 2 까지만 허용 2 x 1 과 1 x 1 은 탈락  13개 탈락

	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			int PerRectangles = (X - x) * (Y - y);
			int PerRound = (x + 1 + y + 1) * 2;
			if (PerRound >= Round)
			{
				UnderRound = UnderRound + PerRectangles;
			}
		}
	}

	return UnderRound;
/*
	1x1 =		3 x 2
	2x1 + 1x2 =  2 X 2 + 3 X 1
	2x2 = 2x1
	3x1 = 1x2
	3x2 = 1x1
	//  기존축에서 n -1 만큼 빠진 갯수
*/

	return Rectangles - UnderRound;
}

int main(void)
{
	int X, Y, R;

	cin >> X >> Y >> R;
	cout << Solve(X, Y, R);		
	
	return 0;
}