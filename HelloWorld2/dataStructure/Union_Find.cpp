#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_ARRAY = 65536;

void ParentInitialize(std::vector<int> &parent){
	parent[0] = 0;
	for (int i = 1; i < MAX_ARRAY; ++i) {
		parent[i] = i;
	}
}


int FindParent(std::vector<int> &parent, int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = FindParent(parent, parent[x]);
}

void Union(std::vector<int> &parent, int x, int y) {
	x = FindParent(parent, x);
	y = FindParent(parent, y);

	if (x < y) 
		parent[y] = x;
	else if (y >= x) 
		parent[x] = y;	
}

bool Find(std::vector<int> &parent, int x, int y) {
	x = FindParent(parent, x);
	y = FindParent(parent, y);
	if (x == y)
		return true;
	else
		return false;
}

void Debug(std::vector<int> const &parent) {
	for (int i = 0; i < 100; ++i) {
		std::cout << parent[i] << "\n";
	}
}

int main(void)
{
	std::vector<int> parentList(MAX_ARRAY); //0~65535
	int x,y,cnt;
	std::cout << "node �� ������ �� �Է�:";
	std::cin >> cnt;	

	ParentInitialize(parentList);

	for (int i = 0; i < cnt; ++i) {
		std::cout << "union �� node �ΰ� �Է�:";
		std::cin >> x >> y;
		if (x > MAX_ARRAY && y > MAX_ARRAY)
		{
			std::cout << "node �� " << MAX_ARRAY << " ���Ϸ� �Է����ּ���";
			--i;
			continue;
		}
		else
			Union(parentList, x, y);	//x �� y�� �������� ����
	} //endfor
	for (int i = 0; i < cnt; ++i) 
	{
		bool flag;
		std::cout << "Find �� node �ΰ� �Է�:";
		std::cin >> x >> y;
		flag = Find(parentList,x, y);		
		if (flag)
			std::cout << x << "��" << y << "�� �̾��� �ִ�.\n";
	}
	return 0;
}

