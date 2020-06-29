#include <iostream>

template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
}

int main() {
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);

	return 0;
}

/*
#include <iostream>

template <typename T>
void Print(T arg) {
  std::cout << arg << "\n";
}

template <typename T, typename... Types>
void Print(T arg, Types... args) {
  std::cout << arg << ", ";
  print(args...);
}

int main() {
	 Print(1, 2.3, "string");
	 Print(1, 2, 3, 4, 5);

	return 0;
}
*/