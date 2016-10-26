#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	vector<vector<int>> G = 
	{
	//origin	target	
		//	A, B, C, D
	/*A*/		{0,0,1,1},
	/*B*/		{0,0,1,1},
	/*C*/		{0,1,0,0},
	/*D*/		{0,1,1,0}

	};//可以看到有四个节点, 7条边(7个1)
	//行是初始节点, 列是目标节点 e.g G[3][2] = 1,就表示从C到B有一条路径(单向的)

	GraphAdMatrix graph(G);		//GraphAdMatrix是一个class
	graph.dfs_recursive(0);
}
