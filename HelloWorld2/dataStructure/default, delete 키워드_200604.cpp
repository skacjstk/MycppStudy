#include <iostream>

class DefaultCon {
private:
	int num;
public:
	DefaultCon(int) = delete;
	DefaultCon() = default;   
};
int main()
{
	DefaultCon d;
	DefaultCon d(5);
	return 0;
}
//컴파일 에러