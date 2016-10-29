//利用kruskal算法, 实现最小生成树. 即遍历所有的点, 用最短的边.

#include <iostream>
#include <vector>
#include <algorithm>

#include "graph_ad_list.h"	//用于存放所有节点和路径
#include "disjoint_set.h"	//用于存放最短路径


using namespace std;

struct edge{
	int source, dest, weight;
	edge(int source, int dest, int weight):source(source), dest(dest), weight(weight){}
};

//a<b 1; a>b 0
bool compare_weight(edge a, edge b)
{
	return a.weight < b.weight
}

//引用传递
graph_ad_list kruskal(graph_ad_list &g)
{	
	//disjoint_set本质是链表
	//subsets是一个存放链表的向量
	vector<disjoint_set *> sub_sets(g.ad_list.size());

	//for each node
	for(int i = 0;i<g.ad_list.size();i++)
		sub_sets[i] = new disjoint_set;

	//边
	vector<edge> edges;	

	//for each node
	for(int i = 0; i< g.ad_list.size();i++)
		//for each edge
		for(auto pos = g.ad_list[i].begin(); pos != g.ad_list[i].end();pos++)

}



int main()
{
	graph_ad_list g(5);
	g.add_edge(0,4,1);
	g.add_edge(0,1,3);
	g.add_edge(1, 4, 4);
    	g.add_edge(1, 2, 5);
   	g.add_edge(2, 4, 6);
    	g.add_edge(2, 3, 2);
   	g.add_edge(3, 4, 7);

   	graph_ad_list min_span_tree = kruskal(g);	//用kruskal算法求最小生成树
   	min_span_tree.dump();	//打印
   	return 0;

}


