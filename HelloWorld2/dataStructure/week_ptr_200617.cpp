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
		std::cout << this->name << "�Է�: ������ ȣ��\n";
	}
	~TreesNode() {
		std::cout << "������ �Ҹ��� ȣ��\n";		
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