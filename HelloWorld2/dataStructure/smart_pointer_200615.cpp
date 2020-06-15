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
		std::cout << this->name << " 기본 생성자 호출\n";
	}
	//복생
	Player(const Player &ref) {
		this->name = ref.name;		//이거 없으면 생성자가 복사되도 멤버변수 전달이 안된다. 
		std::cout << ref.name << " 복사 생성자 호출\n";
	}

	void printName() {
		std::cout << this->name << " 멤버 함수 호출\n";
	}
	~Player() {
		std::cout << this->name << " 소멸자 호출\n";
	}
};


int main() {

	std::unique_ptr<Player> p3 = std::make_unique<Player>("p3_unique");		// C++14 이후의 예외로부터 안전한 방식
//	std::unique_ptr<Player> p3(new Player("Kim"));

	std::shared_ptr<Player> p4(new Player("p4_shared"));


	Player p1("p1_Class");
	Player p2(p1);

	auto p5(p4);

	std::vector<std::unique_ptr<Player>> vec1;
	std::unique_ptr<Player> p9(new Player("p9"));

	vec1.push_back(std::move(p9));  // 복사 생성자 ... ?? 

	vec1.emplace_back(new Player("vec1EmpBack"));

	for (int i = 0; i < vec1.size(); ++i) {
		vec1[i]->printName();

	}
	p2.printName();
	p3->printName();	//화살표 연산자 (포인터니까)
//	p4.printName();

	return 0;
}