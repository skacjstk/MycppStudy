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
		std::shared_ptr<TreesNode> o = otherPtr.lock();
		if (o) {
			std::cout << "존재함 : " << o->getName() <<"\n";
		}
		else {
			std::cout << "이미 소멸되었다" << "\n";
		}
	}
};
int main(void) {
	std::vector<std::shared_ptr<TreesNode>> vec1;
	vec1.push_back(std::make_shared<TreesNode>("0번째"));
	vec1.push_back(std::make_shared<TreesNode>("1번째"));

	vec1[0]->setOtherPtr(vec1[1]);
	vec1[1]->setOtherPtr(vec1[0]);	//서로의 weakPtr 연결

	// 참조 개수는 그대로
	std::cout << "vec1[0] "<<vec1[0]->getName() <<" 참조 개수 : " << vec1[0].use_count() << "\n";
	std::cout << "vec1[1] "<< vec1[1]->getName() <<" 참조 개수 : " << vec1[1].use_count() << "\n";

	// weak_ptr 로 해당 객체 접근하기
	vec1[0]->checkPtr(); 
	vec1[1]->checkPtr();

	// 벡터 마지막 원소 제거 (vec[1] 소멸)
	vec1.pop_back();
	vec1[0]->checkPtr(); //vec1[1] 객체는 이미 소멸되었다. 

	return 0;
}