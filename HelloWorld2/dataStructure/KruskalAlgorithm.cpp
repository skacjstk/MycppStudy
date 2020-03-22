/*
크루스칼 알고리즘
 크루스칼 알고리즘은 무향 연결 그래프가 주어질 때, '최소 스패닝 트리' 라고 부르는 서브 그래프를 찾는 알고리즘입니다.
 크루스칼 알고리즘은 유니온 파인드 자료구조를 사용합니다.

 최소 스패닝 트리: 스패닝 트리들 중에서 간선의 가중치의 합이 가장 작은 스패닝 트리

출처: https://www.weeklyps.com/entry/크루스칼-알고리즘-Kruskals-algorithm [weekly ps]
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
	//왜인지는 모르겠지만 const 와 &를 넣으라고 한다. const 는 상수화, &는 참조이니 거기에 의미가 있겠지..?
	//근데 빼도 되기는 된다...?
	if (x.height < y.height) {
		return true;
	}
	else
		return false;
};

int kruskal(std::vector<int> &parent, std::vector<edge> &qArr) {
	int maxHeight = 0; //가중치 최솟값
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
	
	std::cout << "크루스칼 알고리즘\nnode 간 간선의 수 입력:";
	std::cin >> cnt; 
	ParentInitialize(parentList);
	qArr.resize(cnt);
	for (int i = 0; i < cnt; ++i) {
		std::cout << " node 2개, 가중치 1개 입력:";
		std::cin >> x >> y >> z;
		if (x > MAX_ARRAY && y > MAX_ARRAY){
			std::cout << "node 를 " << MAX_ARRAY << " 이하로 입력해주세요";
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
	printf("크루스칼 결과, 가중치 최솟값: %d ", resultKruskal);

	return 0;
}

