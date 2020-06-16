#include<iostream>
#include <memory>
#include <string>
#include <vector>

class Player {
private:
	std::string name;
	int * testData;
public:
	Player(const std::string &name) {
		this->name = name;
		std::cout << this->name << " �⺻ ������ ȣ��\n";
	}
	Player(const Player *pp) {
		testData = new int[5];
		std::cout <<"�⺻ ������(������) ȣ��\n";
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
		std::cout << "������ �Ҹ��� ȣ��\n";
		delete [] testData;
	}
};

int main(void) {

	//	std::unique_ptr<Player> p3 = std::make_unique<Player>("p3_unique");	
	//	auto p4(p3);


	std::shared_ptr <Player> p1 = std::make_shared<Player>("p1");
	auto p2(p1);
	std::shared_ptr <Player> p4 = std::make_shared<Player>("p4");


	//std::cout << p1.use_count() << "\n";
//	std::cout << p2.use_count() << "\n";
	p1 = p4;
	p2 = p4;		//p1 �� p2 �� �������� �Űܹ���

	//std::cout << p2.use_count() << "\n";

	p2->printName();

	Player* pp = new Player("pp");

	std::shared_ptr <Player> pp1 = std::make_shared<Player>(pp);
	std::shared_ptr <Player> pp2 = std::make_shared<Player>(pp);

	std::cout << pp1.use_count() << "\t" << pp2.use_count()<<"\n";
	//
	std::cout << "����\n";
	return 0;
}


/*
class Player {
private:
	std::string name;
	int * testData;
public:
	Player(const std::string &name) {
		this->name = name;
		testData = new int[5];
		std::cout << this->name << " �⺻ ������ ȣ��\n";
	}
	Player(const Player *pp) {
		std::cout <<"�⺻ ������(������) ȣ��\n";
	}
	~Player() {
		std::cout << "������ �Ҹ��� ȣ��\n";
		delete [] testData;
	}
};
int main(void){
	Player* pp = new Player("pp");
	std::shared_ptr <Player> pp1 = std::make_shared<Player>(pp);
	std::shared_ptr <Player> pp2 = std::make_shared<Player>(pp);

	std::cout << pp1.use_count() << "\t" << pp2.use_count()<<"\n";

	std::cout << "����\n";
}
*/
//https://modoocode.com/252