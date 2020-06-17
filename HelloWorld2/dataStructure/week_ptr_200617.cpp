#include <iostream>
#include <memory>
#include <vector>
#include <string>

class TreesNode{
private:
	std::weak_ptr<TreesNode> otherPtr;
	std::string name;

public:
	TreesNode(const std::string & name) {
		this->name = name;
		std::cout << this->name << "입력: 생성자 호출\n";
	}
	~TreesNode() {
		std::cout << "포인터 소멸자 호출\n";		
	}
	std::string getName() {
		return name;
	}
	void setOtherPtr(std::weak_ptr<TreesNode> op) {
		otherPtr = op;
	}
	void checkPtr() {

	}
};
int main(void) {


	return 0;
}