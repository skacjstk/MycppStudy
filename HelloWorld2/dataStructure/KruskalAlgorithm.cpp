/*
ũ�罺Į �˰���
 ũ�罺Į �˰����� ���� ���� �׷����� �־��� ��, '�ּ� ���д� Ʈ��' ��� �θ��� ���� �׷����� ã�� �˰����Դϴ�.
 ũ�罺Į �˰����� ���Ͽ� ���ε� �ڷᱸ���� ����մϴ�.

 �ּ� ���д� Ʈ��: ���д� Ʈ���� �߿��� ������ ����ġ�� ���� ���� ���� ���д� Ʈ��

��ó: https://www.weeklyps.com/entry/ũ�罺Į-�˰���-Kruskals-algorithm [weekly ps]
*/

#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_ARRAY = 65536;

struct edge {
	int x, y, height;
};
void ParentInitialize(std::vector<int> &parent) {
	parent[0] = 0;
	for (int i = 1; i < MAX_ARRAY; ++i) {
		parent[i] = i;
	}
}


int getParent(std::vector<int> &parent, int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent, parent[x]);
}

void Union(std::vector<int> &parent, int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x < y)
		parent[y] = x;
	else if (y >= x)
		parent[x] = y;
}

bool Find(std::vector<int> &parent, int x, int y) {
	return getParent(parent, x) == getParent(parent, y);
}

void Debug(std::vector<int> const &parent) {
	for (int i = 0; i < 100; ++i) {
		std::cout << parent[i] << "\n";
	}
}

bool Compare(const edge &x, const edge &y){
	//https://namnamseo.tistory.com/entry/stdsort%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%A0%95%EB%A0%AC
	//�������� �𸣰����� const �� &�� ������� �Ѵ�. const �� ���ȭ, &�� �����̴� �ű⿡ �ǹ̰� �ְ���..?
	//�ٵ� ���� �Ǳ�� �ȴ�...?
	if (x.height < y.height) {
		return true;
	}
	else
		return false;
};

int kruskal(std::vector<int> &parent, std::vector<edge> &qArr) {
	int maxHeight = 0; //����ġ �ּڰ�
	std::sort(qArr.begin(), qArr.end(),Compare);
	for (auto here : qArr) {
		if (!Find(parent, here.x, here.y)) {
		maxHeight += here.height;
		Union(parent, here.x, here.y);
		}
	}
	return maxHeight;
}

int main(void)
{
	std::vector<int> parentList(MAX_ARRAY); //0~65535
	std::vector<edge> qArr;
	edge buffer;
	int x, y, z, cnt;
	
	std::cout << "ũ�罺Į �˰���\nnode �� ������ �� �Է�:";
	std::cin >> cnt;
	ParentInitialize(parentList);
	qArr.resize(cnt);
	for (int i = 0; i < cnt; ++i) {
		std::cout << " node 2��, ����ġ 1�� �Է�:";
		std::cin >> x >> y >> z;
		if (x > MAX_ARRAY && y > MAX_ARRAY){
			std::cout << "node �� " << MAX_ARRAY << " ���Ϸ� �Է����ּ���";
			--i;
			continue;
		}
		else{
			qArr[i].x = x;
			qArr[i].y = y;
			qArr[i].height = z;
		} //end else
	} //endfor
	int resultKruskal = kruskal(parentList, qArr);
	printf("ũ�罺Į ���, ����ġ �ּڰ�: %d ", resultKruskal);

	return 0;
}

