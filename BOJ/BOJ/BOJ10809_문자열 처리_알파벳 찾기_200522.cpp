#define _SRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 26  //소문자만 

int main(void) {
	std::vector<char> str(MAX);
	std::fill(str.begin(), str.end(),-1);	//크기 전체 -1 로 초기화

	for (int i = 0; ; ++i) {
		char buffer = 0;
		scanf_s("%c", &buffer);
		if (buffer == '\n')
			break;
		else if(str[buffer - 'a'] == -1)
			str[buffer - 'a'] = i;
	}
	for (int i = 0; i < MAX; ++i) {
		printf("%d ", str[i]);			
	}
	return 0;
}