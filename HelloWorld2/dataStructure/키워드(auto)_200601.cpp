#include <iostream>
int main(void) {
	auto a = 1; //int
	auto b = 2.0f; //float
	auto c = "A"; // char
	auto d = "CPP"; // string (std::string)
	auto e = { 5, 10 }; //int 배열 타입﻿

	std::cout << "값\t자료형" << std::endl;
	std::cout << a << '\t' << typeid(a).name() << "\n";
	std::cout << b << '\t' << typeid(b).name() << "\n";
	std::cout << c << '\t' << typeid(c).name() << "\n";
	std::cout << d << '\t' << typeid(d).name() << "\n";
	
	for (const auto &element : e) {
		std::cout << element << " ";			
	}
	std::cout << '\t' << typeid(e).name() << std::endl;
	
	return 0;
}