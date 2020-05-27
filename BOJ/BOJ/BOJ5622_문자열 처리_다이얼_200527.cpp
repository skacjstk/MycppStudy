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
		//Dial::name 사용
		//모든 숫자는 자신의 숫자보다 1초 더 걸린다. 
		//영어는 대문자만, 26자이며 2~9를 사용한다.  ABC DEF GHI JKL MNO PQRS TUV WXYZ
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
		//S를 7로	-1
		//V를 8로   -1
		//YZ를 9로 -1 
		return answer;
	}

	int getSpendTime() {
		return spendTime;
	}

};

void solve() {
	std::string str1;
	std::cin >> str1;
	Dial dial(str1);	//Dial 클래스를 dial 이름으로 생성 
	printf("%d\n", dial.getSpendTime());
}

int main(void)
{
	solve();
	return 0;
}