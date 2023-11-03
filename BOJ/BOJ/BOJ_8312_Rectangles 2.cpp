#include <iostream>

using namespace std;
//X�� ����, Y�� ����, �ƴ��ϴ� �ѷ�
long long Solve(int X, int Y, int Round)
{
	//X, Y�� ���� ������ ����, ���� ������ ��
	int Horizontal = Y * (Y + 1) / 2;
	int Vertical = X *(X + 1) / 2;
	int Rectangles = Horizontal * Vertical;

	// �ѷ��� �ɷ����� ���� ���ϱ�
	long long UnderRound = 0;
	// Round�� 6�̸� 2 x 1 ������ ��� 1 x 1�� Ż��  6�� Ż��
	// Round�� 8�̸� 2 x 2 ������ ��� 2 x 1 �� 1 x 1 �� Ż��  13�� Ż��

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
	//  �����࿡�� n -1 ��ŭ ���� ����
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