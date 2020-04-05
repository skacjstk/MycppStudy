#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> card;

int bSearch(int cardNum) {	//stl 없이 upper bound 구현 
	int left = 0;
	int right = card.size()-1;
	int mid;

	//lower bound 
	auto lower = card.begin() - std::lower_bound(card.begin(),card.end(), cardNum);		
	int upper = card.begin() - std::upper_bound(card.begin(), card.end(), cardNum);
	
	/*	
	while (left < right) {	//upper bound
		mid = (left + right) / 2;
		if (card[mid] <= cardNum)
			left = mid + 1;
		else
			right = mid;
	}	//return right
	*/

	return right+lower;
}

int main(void)
{
	int numOfCard = 0;//1 ~ 500,000
	scanf("%d", &numOfCard);
	card.resize(numOfCard); // 계수정렬 취소 (나중에 따로해봐야지)

	for (int i = 0; i < numOfCard; ++i) {
		// -10,000,000 ~ 10,000,000	
		scanf("%d", &card[i]);	
	}
	sort(card.begin(), card.end());

	int findCardNum;
	scanf("%d", &findCardNum);


	for (int i = 0; i < findCardNum; ++i) {
		// -10,000,000 ~ 10,000,000	
		int cardNum;
		scanf("%d", &cardNum);
		printf("%d ", bSearch(cardNum));
		
	}	
	return 0;
}