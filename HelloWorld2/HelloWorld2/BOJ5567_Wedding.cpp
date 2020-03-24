#include <iostream>
#include <vector>

void FriendMore(std::vector<std::vector<int>> &sangen, std::vector<bool> &discoverd, const int &before, const int& friendBridge);
void FriendCnt(std::vector<std::vector<int>> &sangen, std::vector<bool> &discoverd, const int &root, const int& friendBridge)
{
	int size = sangen[root].size();
	for (int i = 0; i < size; ++i) {
		discoverd[sangen[root][i]] = true; //ģ�� �Ǵ� ģ����ģ��
		FriendMore(sangen, discoverd, sangen[root][i], friendBridge);
	}
}

void FriendMore(std::vector<std::vector<int>> &sangen, std::vector<bool> &discoverd, const int &before, const int& friendBridge)
{
	int inSize = sangen[before].size();
	for (int i = 0; i < inSize; ++i) {
		discoverd[sangen[before][i]] = true; //ģ�� �Ǵ� ģ����ģ��
	}
	return;
}


int main()
{
	//BOJ 5567 
		//������� ���� �� 2~500 n
	int student;
	std::cin >> student;

	std::vector<std::vector<int>> sangen;
	std::vector<bool> discoverd;
	sangen.resize(student + 1);
	discoverd.resize(student + 1);
	//����Ʈ�� ���� 1~10000 m
	int relationSize;
	std::cin >> relationSize;

	//ģ������ ���� 2��  ����n
	for (int i = 0; i < relationSize; ++i) {
		int a, b;
		std::cin >> a >> b;
		sangen[a].push_back(b);
		sangen[b].push_back(a);
	}
	int cnt = 0;
	int root = 1;
	int friendBridge = 2; //ģ���� ģ��
	FriendCnt(sangen, discoverd, root, friendBridge);
	for (int i = 2; i <= student; ++i) {
		if (discoverd[i])
		{
			//		printf("%d�� ���̴�.\n",i);
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}