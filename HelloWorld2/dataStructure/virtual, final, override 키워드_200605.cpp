#include <iostream>
#include <string>
//번역: 탈것

class Vehicle {
	std::string VehicleType;
public:
	virtual void setWheel(int wheel){
		printf("재정의 안받았네요");
	} 
	virtual int getWheel() {
		printf("재정의 안받았네요");
		return -1;
	}
//	virtual void setVehicleType(std::string VehicleType) {
//	}	//귀찮아서 안만듬 
//	virtual std::string getVehicleType() {
//	}
	//인터페이스가 아니지만 상속 느낌이 안나서 이렇게 만듬
};

//동력의 종류  
class Power : public Vehicle {
private:
	std::string power;
public:
	virtual void setPowerType(std::string power) {
		this->power = power;
	}
	virtual std::string getPowerType() {
		return this->power;
	}
};

//Vehicle 을 상속받은 Power 를 상속받은 Car
class Car : public Power {
private:
	int wheel;
public:
	virtual int getWheel() final { //얘는 이제 오버라이딩 (재정의) 불가
		return this->wheel;
	}
	virtual void setWheel(int wheel) override { //얘는 아직 가능 
		this->wheel = wheel;
	}
};

int main(void)
{
	Car kart;

	kart.setWheel(4);

	printf("%d\n", kart.getWheel());

	return 0;
}
//https://unikys.tistory.com/355
//https://www.devoops.kr/52
