/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>


class Edge {

public:
	int node[2];
	int weight;

	Edge(int node1, int node2, int _weight) {
		node[0] = node1;
		node[1] = node2;
		weight = _weight;
	}

	int getWeight() {
		return weight;
	}

	int getParent(std::vector<int> &set, int x) {
		if (set[x] == x) return x;
		return set[x] = getParent(set, set[x]);
	}
	bool find(std::vector<int> &set, int a, int b) {
		a = getParent(set, a);
		b = getParent(set, b);
		if (a == b)
			return true;
		else
			return false;
	}
	void Union(std::vector<int> &set, int a, int b) {
		a = getParent(set, a);
		b = getParent(set, b);
		if (a >= b)
			set[a] = b;
		else
			set[b] = a;
	}
};


bool compare(Edge a, Edge b) {
	return a.weight < b.weight;
}

int main()
{
	int node, edge;
	while (true) {

		std::vector<Edge> graph;
		std::vector<int> set; //0¹ø ¿ø¼Ò ¾È¾¸ 
		int weightTotal = 0;
		scanf("%d %d", &node, &edge);
		if (node == 0 && node == edge)
			break;
		set.resize(node + 1);
		for (int i = 0; i < edge; ++i) {
			int node1, node2, weight;
			scanf("%d %d %d", &node1, &node2, &weight);
			graph.push_back(Edge(node1, node2, weight));
			weightTotal += weight;
		}
		for (int i = 1; i <= node; ++i) {
			set[i] = i;
		}
		std::sort(graph.begin(), graph.end(), compare);
		//  printf("%d",graph[0].getWeight());                                                                      

		int sum = 0;

		for (long i = 0; i < graph.size(); ++i) {
			if (!graph[i].find(set, graph[i].node[0], graph[i].node[1])) {
				sum += graph[i].weight;
				graph[i].Union(set, graph[i].node[0], graph[i].node[1]);
			}
		}
		printf("%d\n", weightTotal - sum);
	}
	return 0;
}
