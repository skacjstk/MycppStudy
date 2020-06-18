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
		std::shared_ptr<TreesNode> o = otherPtr.lock();
		if (o) {
			std::cout << "������ : " << o->getName() <<"\n";
		}
		else {
			std::cout << "�̹� �Ҹ�Ǿ���" << "\n";
		}
	}
};
int main(void) {
	std::vector<std::shared_ptr<TreesNode>> vec1;
	vec1.push_back(std::make_shared<TreesNode>("0��°"));
	vec1.push_back(std::make_shared<TreesNode>("1��°"));

	vec1[0]->setOtherPtr(vec1[1]);
	vec1[1]->setOtherPtr(vec1[0]);	//������ weakPtr ����

	// ���� ������ �״��
	std::cout << "vec1[0] "<<vec1[0]->getName() <<" ���� ���� : " << vec1[0].use_count() << "\n";
	std::cout << "vec1[1] "<< vec1[1]->getName() <<" ���� ���� : " << vec1[1].use_count() << "\n";

	// weak_ptr �� �ش� ��ü �����ϱ�
	vec1[0]->checkPtr(); 
	vec1[1]->checkPtr();

	// ���� ������ ���� ���� (vec[1] �Ҹ�)
	vec1.pop_back();
	vec1[0]->checkPtr(); //vec1[1] ��ü�� �̹� �Ҹ�Ǿ���. 

	return 0;
}