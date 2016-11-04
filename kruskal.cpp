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
	//每个节点开始的时候都不是连着的, 每个节点都产生一个并查集
	vector<disjoint_set *> sub_sets(g.ad_list.size());

	//for each node 每个节点都有一个独立的并查集
	for(int i = 0;i<g.ad_list.size();i++)
		sub_sets[i] = new disjoint_set;

	//边 初始化
	vector<edge> edges;	

	//把所有边聚集在一起,为了后边排序
	//for each node
	for(int i = 0; i< g.ad_list.size();i++)
		//for each edge
		for(auto pos = g.ad_list[i].begin(); pos != g.ad_list[i].end();pos++)
		{
			edge edge(i, pos->dest_id, pos->height);
			edges.push_back(edge);	//edges是一个edge类型的向量 push_back就是在最后添加
		}

	//sorting edges by weight
	//这里用的C++ STL中的排序函数sort(), 最后一个参数是一个自己定义的函数,表示用这个函数来进行排序, 这样可以sort升序或者降序
	//前边的两个参数表示范围
	std::sort(edges.begin(), edges.end(), compare_weight);

	//初始化一个存储结果的邻接表
	graph_ad_list result(g.ad_list.size());

	//从最小的边开始选择路线
	//for each edge
	for(int i = 0;i<edges.size();i++)
	{
		edge e = edges[i];

	//	if source node and dest node are not in the same sub set
		if(sub_sets[e.source]->find_root() != sub_sets[e.dest] -> find_root() )
		{
			result.add_edge(e.source, e.dest, e.weight);
			sub_sets[e.source] -> union_set(sub_sets[e.dest]);	//因为subsets是一个指针类型的容器,所以调用元素或者方法要用->
		}
	}

	return result;


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


