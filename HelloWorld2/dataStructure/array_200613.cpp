#include <iostream>
#include <array>
int main(void)
{
	std::array <int, 4> arr1;
	std::array <int, 4> arr2 = { 0,2,1,3 };

	std::array <int, 4> arr3;

	arr3 = { 0,1,2 };	//����ִ� �κ��� 0���� �ʱ�ȭ 
	// �� ������Ģ���� �ʱ�ȭ�Ǵ°Ŷ�  �Ʒ��� 4,4 �� 4,4,0,0 ���� �ʱ�ȭ��.
	arr3 = { 4, 4 }; //�̴ϼȶ����� �ʰ� �Ұ�  

	printf("%d\n", arr3[2]);	//�Ϲ� �迭ó�� �������

	//arr2.at(4) = 5;	//��Ÿ�� ����(����) throw 

	printf("%d -->", arr2.at(3));
	arr2.at(3) = 10;
	printf("%d", arr2.at(3));
	return 0;

}