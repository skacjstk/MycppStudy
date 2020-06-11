
#include <iostream>
#include <map>
#include <string>

void PrintAll(std::map<std::string, int>& m) {
	for (auto i : m) {
		std::cout << i.first << ": " << i.second << "\n";
	}
	printf("====\n");
}

int main() {
	std::map<std::string, int> m;

	m["marine"] = 70;
	m["marine"] = 40;		//갱신이 된다. 
//	std::cout << m["marine"];
	m.insert(std::make_pair("firebat", 50));
	m.insert(std::make_pair("firebat", 60));	//갱신이 안된다. 

	PrintAll(m);

	m.erase("firebat");
	m.erase("teemo");

	PrintAll(m);

	return 0;
}
//https://kamang-it.tistory.com/entry/mapunorderedmapC%EC%97%90%EC%84%9C-map%EB%94%95%EC%85%94%EB%84%88%EB%A6%ACdictionary-%EC%97%B0%EA%B4%80%EB%B0%B0%EC%97%B4associate-array%ED%95%B4%EC%8B%9C%EB%A7%B5hash-map%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0map%EA%B3%BC-unorderedmap-%EA%B7%B8%EB%A6%AC%EA%B3%A0-%EC%B0%A8%EC%9D%B4%EC%A0%90

//EOF