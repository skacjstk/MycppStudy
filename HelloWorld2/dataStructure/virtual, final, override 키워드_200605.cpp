#include <iostream>
#include <string>
//����: Ż��

class Vehicle {
	std::string VehicleType;
public:
	virtual void setWheel(int wheel){
		printf("������ �ȹ޾ҳ׿�");
	} 
	virtual int getWheel() {
		printf("������ �ȹ޾ҳ׿�");
		return -1;
	}
//	virtual void setVehicleType(std::string VehicleType) {
//	}	//�����Ƽ� �ȸ��� 
//	virtual std::string getVehicleType() {
//	}
	//�������̽��� �ƴ����� ��� ������ �ȳ��� �̷��� ����
};

//������ ����  
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

//Vehicle �� ��ӹ��� Power �� ��ӹ��� Car
class Car : public Power {
private:
	int wheel;
public:
	virtual int getWheel() final { //��� ���� �������̵� (������) �Ұ�
		return this->wheel;
	}
	virtual void setWheel(int wheel) override { //��� ���� ���� 
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
