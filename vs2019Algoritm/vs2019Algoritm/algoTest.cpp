#include <iostream>
#include <algorithm>

using namespace std;
constexpr int dwarfNum = 9;
int inputs[dwarfNum];
int outputs[dwarfNum - 2];

void CalCorrectDwarf(int correctIndex[]);

int main() {
	
	int allDwarf = 0;
	int correctIndex[2];
	int buffer;

	for (int i = 0; i < dwarfNum; ++i) {
		cin >> inputs[i];
		allDwarf += inputs[i];
	}

	sort(inputs, inputs + dwarfNum);
/*
	for (int i = 0; i < dwarfNum; ++i) {
		cout << inputs[i];
	}
	cout << '\n' << buffer;
*/

	for (int i = 0; i < dwarfNum - 1; ++i) {

		for (int j = i+1; j < dwarfNum; ++j) {
			buffer = 0;
			buffer = allDwarf;

			buffer -= inputs[i];
			buffer -= inputs[j];

	//		cout << buffer << "\n";

			if (buffer == 100) {
				correctIndex[0] = i;
				correctIndex[1] = j;

				CalCorrectDwarf(correctIndex);
			}
		}
	}


	for (int i = 0; i < dwarfNum-2; ++i) {
		cout << outputs[i] << "\n";
	
	}

	return 0;
}

void CalCorrectDwarf(int correctIndex[]) {

	//cout << "Àü¼ÛµÈ index: " << correctIndex[0] << " " << correctIndex[1] << "\n";

	int flag = 0;
	int outputIndex = 0;
	for (int i = 0; i < dwarfNum; ++i) {
		
		if (i == correctIndex[flag]) {
			++flag;
			continue;
		}
		outputs[outputIndex] = inputs[i];

		++outputIndex;
	}

}