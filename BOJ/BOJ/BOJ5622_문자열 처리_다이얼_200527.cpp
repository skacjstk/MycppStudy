#include <iostream>
#include <string>
#include <algorithm>

class Dial {
private:
	std::string name;
	int spendTime;
public:

	Dial(std::string& str) {
		name = str;
		spendTime = findSpendTime();
	}

	int findSpendTime() {
		//Dial::name ���
		//��� ���ڴ� �ڽ��� ���ں��� 1�� �� �ɸ���. 
		//����� �빮�ڸ�, 26���̸� 2~9�� ����Ѵ�.  ABC DEF GHI JKL MNO PQRS TUV WXYZ
		// 0 , 1, 2, 3, 4, 5~6, 7~8, 
		int answer = 0;

		for (char element : name) {
			//	printf("%d = %c\n",(element - 'A') / 3 + 2, element);
			int timeBuffer = element - 'A';
			if (element == 'S' || element == 'V' || element == 'Y' || element == 'Z')
			{
				timeBuffer /= 3; timeBuffer += 1;
			}
			else
			{
				timeBuffer /= 3; timeBuffer += 2;
			}

			answer += timeBuffer + 1;
		}
		//S�� 7��	-1
		//V�� 8��   -1
		//YZ�� 9�� -1 
		return answer;
	}

	int getSpendTime() {
		return spendTime;
	}

};

void solve() {
	std::string str1;
	std::cin >> str1;
	Dial dial(str1);	//Dial Ŭ������ dial �̸����� ���� 
	printf("%d\n", dial.getSpendTime());
}

int main(void)
{
	solve();
	return 0;
}