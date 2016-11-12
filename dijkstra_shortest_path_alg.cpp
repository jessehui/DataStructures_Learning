//单源最短路径算法

#include <iostream>
#include <algorighm>
#include <climits>	//定义有各种数据类型的最值 纯C中是limits.h
#include <queue>

#include "graph_ad_list.h"	//邻接表


using namespace std;

struct node{
	int id;		//节点名字
	int dist;	//最短路的距离
	int prev;	//目前最优解中的前一个节点
	bool processed;	//标志位: 是否已经被处理过
	node: dist(INT_MAX), prev(-1), processed(false) {}
};

struct compare_node{
	bool operator()(node &a, node &b)	//重载()操作符
	{
		return a.dist > b.dist;
	}
};

vecotr<node> dijkstra(graph_ad_list &g, int source)	//从source开始的最短路
{
	int node_count = g.ad_list.size();
	vector<node> nodes(node_count);

	for(int i = 0; i< node_count; i++)	//给数组标号
	{
		nodes[i].id = i;
	}
	nodes[source].dist = 0;	//从source到source距离为0

	priority_queue<node, vecotr<node>, compare_node> node_pq;
	node_pq.push(nodes[source]);	//先把source入栈

	while(!node_pq.empty())
	{
		node current_node = node_pq.top();
		node_pq.pop();

		if(current_node.processed)
			continue;

		//get all edges from the current node
		//因为graph_ad_list(邻接表)这个数据结构中的ad_list元素是所有edge的集合
		list<edge_node> edge_nodes = g.ad_list[current_node.id];

		//for each edge from current node (`->`指针的时候用)
		for(auto edge_pos = edge_nodes.begin(); 
			edge_pos != edge_nodes.end(); edge_pos++)
		{
			node& dest_node = nodes[edge_pos -> dest_id];
			if(current_node.dist + edge_pos->weight < dest_node.dist)
			{
				dest_node.dist = current_node.dist + edge_pos->weight;
				dest_node.prev = current_node.id;
				node_pq.push(dest_node);
			}
		}
		current_node.processed = true;


	}
	return nodes;	//所有节点都processed且piority_queue为空的时候返回
}

int main()
{
	graph_ad_list g(9);	//9个节点
	g.add_edge(0, 1, 2);
	g.add_edge(0, 3, 9);
	g.add_edge(0, 4, 6);
	g.add_edge(1, 2, 1);
	g.add_edge(1, 4, 3);
	g.add_edge(2, 4, 1);
	g.add_edge(2, 6, 6);
	g.add_edge(3, 7, 4);
	g.add_edge(4, 3, 2);
	g.add_edge(4, 5, 9);
	g.add_edge(5, 6, 5);
	g.add_edge(5, 8, 1);
	g.add_edge(6, 8, 5);
	g.add_edge(7, 5, 1);
	g.add_edge(7, 8, 5);


	vector<node> result = dijkstra(g,0);
	for(int i = 0; i < result.size(); i++)
	{
		cout << "Print path and dist for node: " << result[i].id << endl;
		print_path(result, result[i].id);
		cout << endl << "Dist: " << result[i].dist << endl;
	}
	return 0;
}



