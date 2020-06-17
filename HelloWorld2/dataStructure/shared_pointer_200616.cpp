#include<iostream>
#include <memory>
#include <string>
#include <vector>

class Player : public std::enable_shared_from_this<Player> {
private:
	std::string name;
	int * testData;
public:
	Player() {
		testData = new int[5];
		std::cout <<  "생성자 호출\n";
	}
	~Player() {
		std::cout << "포인터 소멸자 호출\n";
		delete[] testData;
	}
	// 이걸 사용할 경우 이전과 같은 메모리 오류 발생
	 //std::shared_ptr<Player> get_shared_ptr() { return std::shared_ptr<Player>(this); }

	std::shared_ptr<Player> get_shared_ptr() { return shared_from_this(); }
};
int main(void) {

	std::shared_ptr <Player> pp1 = std::make_shared<Player>();
	//	std::shared_ptr <Player> pp2 = std::make_shared<Player>();
	std::shared_ptr <Player> pp2 = pp1->get_shared_ptr();

	std::cout << pp1.use_count() << "\t" << pp2.use_count() << "\n";
	std::cout << "종료\n";
	return 0;
}
/*
class Player : public std::enable_shared_from_this<Player> {
private:
	std::string name;
	int * testData;
public:
	Player() {
		testData = new int[5];
		std::cout <<  "생성자 호출\n";
	}
	~Player() {
		std::cout << "포인터 소멸자 호출\n";
		delete[] testData;
	}
	// 이걸 사용할 경우 이전과 같은 메모리 오류 발생
	 //std::shared_ptr<Player> get_shared_ptr() { return std::shared_ptr<Player>(this); }

	std::shared_ptr<Player> get_shared_ptr() { return shared_from_this(); }
};
int main(void) {

	std::shared_ptr <Player> pp1 = std::make_shared<Player>();
	//	std::shared_ptr <Player> pp2 = std::make_shared<Player>();
	std::shared_ptr <Player> pp2 = pp1->get_shared_ptr();

	std::cout << pp1.use_count() << "\t" << pp2.use_count() << "\n";
	std::cout << "종료\n";
	return 0;
}
*/
/*
class Player {
private:
	std::string name;
	int * testData;
public:
	Player(const std::string &name) {
		this->name = name;
		std::cout << this->name << " 기본 생성자 호출\n";
	}
	Player(const Player *pp) {
		testData = new int[5];
		std::cout <<"기본 생성자(포인터) 호출\n";
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
		std::cout << "포인터 소멸자 호출\n";
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
	p2 = p4;		//p1 과 p2 의 포인팅을 옮겨버림

	//std::cout << p2.use_count() << "\n";

	p2->printName();

	Player* pp = new Player("pp");

	std::shared_ptr <Player> pp1 = std::make_shared<Player>(pp);
	std::shared_ptr <Player> pp2 = std::make_shared<Player>(pp);

	std::cout << pp1.use_count() << "\t" << pp2.use_count()<<"\n";
	//
	std::cout << "종료\n";
	return 0;
}

*/
/*

//변경점: Player 객체가 enable... 을 상속받았다.
class Player : public std::enable_shared_from_this<Player> {
private:
	std::string name;
	int * testData;
public:
	Player(const std::string &name) {
		this->name = name;
		testData = new int[5];
		std::cout << this->name << " 기본 생성자 호출\n";
	}
	Player(const Player *pp) {
		std::cout <<"기본 생성자(포인터) 호출\n";
	}
	~Player() {
		std::cout << "포인터 소멸자 호출\n";
		delete [] testData;
	}
   // 이걸 사용할 경우 이전과 같은 메모리 오류 발생
   // std::shared_ptr<Player> get_shared_ptr() { return std::shared_ptr<Player>(this); }

  std::shared_ptr<Player> get_shared_ptr() { return shared_from_this(); }
};
int main(void){
	Player* pp = new Player("pp");
	std::shared_ptr <Player> pp1 = std::make_shared<Player>(pp);
//	std::shared_ptr <Player> pp2 = std::make_shared<Player>(pp);
	std::shared_ptr <Player> pp2 = pp1->get_shared_ptr();

	std::cout << pp1.use_count() << "\t" << pp2.use_count()<<"\n";
	std::cout << "종료\n";
	return 0;
}
*/
//https://modoocode.com/252