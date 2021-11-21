#include <iostream>
#include <string>
#include <vector>
using namespace std;
int BIT = 0;
#define BITMAX 20
vector<string> opCodeTable = {"add","remove","check","toggle","all","empty"};

void AllorEmpty(const int& opCode) {
	if (opCode == 4) {	//all
		BIT |= (1 << (BITMAX + 1)) - 1;
	}
	else if (opCode == 5) { //empty
		BIT = 0; 
	}

}

void CalOpCode(const int& opCode) {
	int num;
	if (opCode == -1)
		cout << "error, Cannot find Order\n";
	else if (opCode == 0) {	//add
		cin >> num;
		BIT |= (1 << num); //1의 비트를 num만큼 << 연산한 결과를 BIT에 OR 연산
	}if (opCode == 1) {//remove
		cin >> num;
		BIT &= ~(1 << num); //1의 비트를 num만큼 <<연산한 결과를 BIT를 NOT한 결과를 AND 연산
	}if (opCode == 2) {//check
		cin >> num;
		if (BIT & (1 << num)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}if (opCode == 3) {//toggle
		cin >> num;
		BIT ^= (1 << num); //1의 비트를 num만큼 <<연산한 결과를 XOR 연산(반전)
	}if (opCode == 4 || opCode == 5) {//all
		AllorEmpty(opCode);
	}
}

int TransOrderToOpCode(const string& order) {
	int returnValue = -1;

	for (int i = 0; i < opCodeTable.size(); ++i) {
		if (order == opCodeTable[i])
		{
			returnValue = i;
			break;
		}
	}
	return returnValue;
}
int main(void)
{
	int countOfOp;
	string order;
	int opCode;
	//명령 횟수 입력
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> countOfOp;

	for (int i = 0; i < countOfOp; ++i) {
		cin >> order;
		
		opCode = TransOrderToOpCode(order);
		CalOpCode(opCode);


	}
	return 0;
}