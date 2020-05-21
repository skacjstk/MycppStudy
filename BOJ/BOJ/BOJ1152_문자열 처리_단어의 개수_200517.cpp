#include <iostream>
#include <string>

int main(void) {
	std::string str;
	getline(std::cin, str);

	int answer = 0; //wordNum

	if (str[0] == ' ') {
		--answer;
	}
	if (str[str.length()-1] == ' ') {
		--answer;
	}
	for (unsigned int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			++answer;
		}
	}
	printf("%d",answer+1);
}