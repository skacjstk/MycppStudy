#include<iostream>
#include <memory>
#include <string>
#include <vector>

class Player {
private:
	std::string name;
public:
	Player(const std::string &name) {
		this->name = name;
		std::cout << this->name << " �⺻ ������ ȣ��\n";
	}
	//����
	Player(const Player &ref) {
		this->name = ref.name;		//�̰� ������ �����ڰ� ����ǵ� ������� ������ �ȵȴ�. 
		std::cout << ref.name << " ���� ������ ȣ��\n";
	}

	void printName() {
		std::cout << this->name << " ��� �Լ� ȣ��\n";
	}
	~Player() {
		std::cout << this->name << " �Ҹ��� ȣ��\n";
	}
};


int main() {

	std::unique_ptr<Player> p3 = std::make_unique<Player>("p3_unique");		// C++14 ������ ���ܷκ��� ������ ���
//	std::unique_ptr<Player> p3(new Player("Kim"));

	std::shared_ptr<Player> p4(new Player("p4_shared"));


	Player p1("p1_Class");
	Player p2(p1);

	auto p5(p4);

	std::vector<std::unique_ptr<Player>> vec1;
	std::unique_ptr<Player> p9(new Player("p9"));

	vec1.push_back(std::move(p9));  // ���� ������ ... ?? 

	vec1.emplace_back(new Player("vec1EmpBack"));

	for (int i = 0; i < vec1.size(); ++i) {
		vec1[i]->printName();

	}
	p2.printName();
	p3->printName();	//ȭ��ǥ ������ (�����ʹϱ�)
//	p4.printName();

	return 0;
}