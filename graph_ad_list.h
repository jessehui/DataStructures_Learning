//用邻接表代替邻接矩阵来表示比较稀疏的图
//而且如果要解决的问题中,边有权重, 应该选用邻接表
//graph adjacency matrix 邻接矩阵
//graph adjacency list 邻接表
#include <iostream>
#include <list>
#include <vector>

using namespace std;


//边的数据结构
struct edge_node{
	int dest_id;
	int weight;

	//struct 构造函数
	edge_node(int dest_id, int weight):dest_id(dest_id),weight(weight){}
};

//邻接表的数据结构
struct graph_ad_list{

	//第一层是vector, 第二层是list
	//ad_list里边存edge_node 比如vector[2]存一个edge_node(3,5)就表示起点是2, 终点是3, 权重是5
	vector<list<edge_node>> ad_list;	
	//ad_list可以用vector的各种方法 是节点
	//ad_list[x]可以用list的各种方法	是和节点相连的边

	//n表示节点数
	graph_ad_list(int n): ad_list(n);

	//添加边
	void add_edge(int source, int dest, int weight)
	{
		edge_node new_edge(dest,weight);
		ad_list[source].push_back(new_edge);	//链表末尾添加一个元素
	}

	void dump()//打印图
	{
		//for each node
		for(int i = 0; i < ad_list.size();i++)
			//for each edge
			for(auto pos = ad_list[i].begin(); pos != ad_list[i].end();pos++)
			{
				cout << "edge from" << i << " to " << pos->dest_id;
				cout << "weight : " << pos->weight << endl;
			}
	}
	
};


